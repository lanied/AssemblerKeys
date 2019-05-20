#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keyboard.h>
#include <OneButton.h>

#include "Notas.h"

volatile String saveKeys;//struc
volatile int btnI;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int i;
void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  
  keys[0].btn.attachClick(clicked);

}

void loop() {
   keys[0].btn.tick();
   
   delay(10);
}

void clicked(){
  
  //TODO: print lcd "nom" key btnI
      //send keyboard data
      //save key saveKeys=;
}//click

void exitAsm(){
  //todo: send exit func
}

void play(){
  //TODO: clear func asm
  //print lcd "nom" of saveKeys
  //send keyboard data
}
