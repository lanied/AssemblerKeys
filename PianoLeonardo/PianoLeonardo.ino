#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keyboard.h>
#include <OneButton.h>

#include "Notas.h"

saveKeys saveKey[50];
volatile int savePos = 0;
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
  for (btnI = 0; btnI < 12; btnI++) {
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
  for (btnI = 0; btnI < 12 ; btnI++) {
    keys[btnI].btn.tick();
  //definir octava
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
  //enviar nota
  Keyboard.write(keys[btnI].ch);
  //guardar nota saveKeys;
  if (savePos < sizeof(saveKey)) {
    saveKey[savePos].nom = keys[btnI].nom + (octava + 2) + ",";
    saveKey[savePos].ch = keys[btnI].ch;
    savePos++;
  }
  if (savePos == 1) { //limpiar pantalla la primera ves
    lcd.clear();//once
  }
  //imprimir nota
  lcd.print(saveKey[savePos].nom);
}//click

void play() {
  //TODO: clear func asm
  Keyboard.write(Clean);
  lcd.clear();

  for (int i = 0; i < savePos ; i++) {
    lcd.print(saveKey[i].nom);
    Keyboard.write(saveKey[i].ch);
    delay(500);
  }
}

void clearNotes() {
  lcd.clear();
  lcd.print("PIANO LEONARDO EQ.10");
  memset(saveKey, 0, savePos); //limpiar array
}

void exitAsm() {
  Keyboard.write(Exit);
  lcd.noBacklight();
}
