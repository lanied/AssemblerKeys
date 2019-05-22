#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keyboard.h>
#include <OneButton.h>

#include "Notas.h"

saveKeys saveKey[50];
volatile byte savePos = 0;
volatile byte btnI;
volatile byte octava;
//limita la cant. max de notas a mostrar
volatile int keyCounter = 0;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int i;
void setup() {
  //mensaje de inicio
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print(F("PIANO LEONARDO"));

  Keyboard.begin();

  //attach event every btn
  for (btnI = 0; btnI < 12; btnI++) {
    keys[btnI].btn.attachClick(clicked);
  }
  //boton 10 funciones
  keys[12].btn.attachClick(play);
  keys[12].btn.attachDoubleClick(clearNotes);
  keys[12].btn.attachLongPressStop(exitAsm);
}

void loop() {
  //leer octava
  octava = map(analogRead(A3), 0, 1023, 2, 1);
  //configurar botones
  for (btnI = 0; btnI < 12 ; btnI++) {
    keys[btnI].btn.tick();
    //definir octava
    if (octava == 2) {
      keys[btnI].ch = firstOctave[btnI];
    } else {
      keys[btnI].ch = secondOctave[btnI];
    }
  }
  //boton 10 "funciones"
  keys[12].btn.tick();

  delay(10);
}

void clicked() {
  if (savePos == 0) { //limpiar pantalla la primera ves
    lcd.clear();//once
  }

  //guardar nota saveKeys;
  if (savePos < sizeof(saveKey) / sizeof(saveKey[0])) {
    //enviar nota
    Keyboard.write(keys[btnI].ch);
    //guardar
    saveKey[savePos].nom = keys[btnI].nom + (octava + 2) + ",";
    saveKey[savePos].ch = keys[btnI].ch;
    //imprimir nota
    printLCD(saveKey[savePos].nom);
    savePos++;
  } else {
    lcd.clear();
    lcd.print(F("Memoria"));
    lcd.setCursor(0, 1);
    lcd.print(F("Llena"));
  }
}//click

void play() {
  Keyboard.write(Clean);
  lcd.clear();
  keyCounter = 0;

  if (savePos != 0) { // si no hay algo que tocar
    for (byte i = 0; i < savePos ; i++) {
      printLCD(saveKey[i].nom);
      Keyboard.write(saveKey[i].ch);
      delay(400);
    }
  } else {
    lcd.print(F("NADA QUE TOCAR"));
  }

}

void clearNotes() {
  Keyboard.write(Clean);
  lcd.clear();
  lcd.print(F("PIANO LEONARDO"));
  memset(saveKey, 0, sizeof(saveKey)); //limpiar array
  savePos = 0; //contador a 0
  keyCounter = 0;
}

void exitAsm() {
  Keyboard.write(Exit);
  lcd.noBacklight();
  //sleep
}

void printLCD(String var) {
  if (keyCounter == 3 ) {
    lcd.setCursor(0, 1);
  } else if (keyCounter == 6) {
    lcd.clear();
    keyCounter = 0;
  }

  lcd.print(var);
  keyCounter++;
}
