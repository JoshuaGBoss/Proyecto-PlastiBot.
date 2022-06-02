#include <Servo.h>
#include <Wire.h>
Servo SGRIP;  


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
#define COLS 16 // Columnas del LCD
#define ROWS 2 // Filas del LCD 

unsigned long pre ;

int valser = 175; 

int estado = 1; 
int estadoA = 1; 


void setup() {

  lcd.backlight();
  lcd.init();
  lcd.begin(COLS, ROWS);

 
  pinMode(8, OUTPUT); //COMPRESION
  pinMode(9, OUTPUT); //REGRESO

  pinMode(4, INPUT_PULLUP); // DESCOMPRIMIDO
  pinMode(5, INPUT_PULLUP); //COMPRIMIDO
  pinMode(7, INPUT_PULLUP); // INFRAROJO


  digitalWrite(8, !LOW);
  digitalWrite(9, !LOW);
  
lcd.clear();
lcd.setCursor(3, 0); lcd.print("RECO-BOT"); lcd.setCursor(0, 1);   lcd.print("TEC NM ITT TLA.1");
delay(2000);

lcd.clear();
lcd.setCursor(2, 0); lcd.print("ADVERTENCIA"); lcd.setCursor(2, 1);   lcd.print("--PELIGRO--");
delay(2000);

lcd.clear();
lcd.setCursor(0, 0); lcd.print("ESTE PRODUCTO "); lcd.setCursor(0, 1);   lcd.print(" PUEDE CAUSAR");
delay(2000);

lcd.clear();
lcd.setCursor(0, 0); lcd.print("LESIONES SI NO"); lcd.setCursor(0, 1);   lcd.print("SE MANEJA CON");
delay(2000);

lcd.clear();
lcd.setCursor(2, 0); lcd.print("PRECAUCION"); lcd.setCursor(0, 1);   lcd.print("");
delay(2000);
lcd.clear();


SGRIP.attach(6);  // attaches the servo on pin 9 to the servo object
 SGRIP.write(valser);

 
  
}

void loop() {

lcd.clear();
lcd.setCursor(2, 0); lcd.print(" EN ESPERA "); lcd.setCursor(0, 1);   lcd.print("");
delay(300);


if(digitalRead(7)== LOW){
           delay(2500);
           if(millis() - pre > 500 ){
           pre = millis();
           lcd.clear();
           lcd.setCursor(0, 0); lcd.print("  RECOLECTANDO  "); lcd.setCursor(0, 1);   lcd.print("");
           }
    
    
    valser =85;
    SGRIP.write(valser);
    delay(2000);
    
    
     while (digitalRead(4)== HIGH ) {
           digitalWrite(8, !LOW);
           digitalWrite(9, !HIGH);
           }
   


    if(digitalRead(4)== LOW){
    
      
       estado = 1; 
       valser =5;
       SGRIP.write(valser);
       delay(1000);

}


while (digitalRead(5)== HIGH ) {

                 

           if(millis() - pre > 500 ){
           pre = millis();
           lcd.clear();
           lcd.setCursor(0, 0); lcd.print("  COMPACTANDO  "); lcd.setCursor(0, 1);   lcd.print("");
           }





         
         
         digitalWrite(9, !LOW);
         digitalWrite(8, !HIGH);
        }
        digitalWrite(9, !LOW);
        digitalWrite(8, !LOW);


   while (digitalRead(4)== HIGH ) {



           
           
           if(millis() - pre > 500 ){
           pre = millis();
           lcd.clear();
           lcd.setCursor(0, 0); lcd.print("  REGRESANDO "); lcd.setCursor(0, 1);   lcd.print("     PRENSA     ");
           }
          

           
           
           digitalWrite(8, !LOW);
           digitalWrite(9, !HIGH);
           }
          digitalWrite(9, !LOW);
        digitalWrite(8, !LOW);
   
  
  
  }





 

}
