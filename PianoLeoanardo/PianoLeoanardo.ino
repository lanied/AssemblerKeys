#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keyboard.h>
#include <OneButton.h>

#include "Notas.h"

key keys[] = {
  {"DO4", OneButton(A1, true), DO4},
  {"RE4", OneButton(A2, true), RE4},
  {"Exit", OneButton(A3, true),Exit}
};


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
  //TODO: print lcd "nom" key
}//click
