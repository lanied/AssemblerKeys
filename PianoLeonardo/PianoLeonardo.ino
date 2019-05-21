#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keyboard.h>
#include <OneButton.h>

#include "Notas.h"

String saveKeys ="";
volatile int btnI;
volatile int octava;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int i;
void setup() {
  //mensaje de inicio
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("PIANO LEONARDO EQ.10");

  Keyboard.begin();

  //attach event every btn
  for (btnI = 0; btnI < 12; i++) {
    keys[btnI].btn.attachClick(clicked);
  }
  //boton 13 funciones
  keys[12].btn.attachClick(play);
  keys[12].btn.attachDoubleClick(clearNotes);
  keys[12].btn.attachLongPressStop(exitAsm);
}

void loop() {
  //leer octava
  octava = map(analogRead(A10), 0, 1023, 1, 2);

  //configurar botones
  for (btnI = 0; btnI < 12 ; i++) {
    keys[btnI].btn.tick();

    if (octava == 1) {
      keys[btnI].ch = firstOctave[btnI];
    } else {
      keys[btnI].ch = secondOctave[btnI];
    }
    delay(10);
  }
  //boton 13 "funciones"

  delay(10);
}

void clicked() {
  //imprimir nota
  lcd.clear();
  lcd.print(keys[btnI].nom + (octava + 2)+",");
  //enviar nota
  Keyboard.write(keys[btnI].ch);
  //guardar nota saveKeys+=;
  saveKeys.concat(keys[btnI].ch);
}//click

void play() {
  //TODO: clear func asm
  //print lcd "nom" of saveKeys
  //send keyboard data
}

void clearNotes() {
}

void exitAsm() {
  //todo: send exit func
}
