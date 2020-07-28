/*
  Set RGB LED color on the Portenta H7
  July 28th, 2020
  by Daniel Danaie
  
  Edit from this example:
  AnalogWrite for each LED on the Portenta H7
  July 27th, 2020
  by Jeremy Ellis
  Twitter @rocksetta
  Website https://www.rocksetta.com
  Original Code https://github.com/hpssjellis/my-examples-for-the-arduino-portentaH7/blob/master/my06-onboard-LED-analogWrite.ino?fbclid=IwAR2--rFJQ5S56rf153TKVZS63kVeLkA3R9ZOb_Rm8NbcuES3KXtfHPxwN-0
*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  SetRGB(255,20,147, HIGH); //deep pink
}

//Set Full Color with amount of r, g or b between 0 and 255, and the state (HIGH or LOW)
void SetRGB(int r, int g, int b, int state){
  unsigned long previousMillisR;
  unsigned long previousMillisG;
  unsigned long previousMillisB;
  SetColor(LEDR, r, previousMillisR, state);
  SetColor(LEDG, g, previousMillisG, state);
  SetColor(LEDB, b, previousMillisB, state);
}

// Set Color (R, G or B) by setting digital write to high more often or less often since pmw does not work
void SetColor(int myPin, int myPWM, unsigned long &myMillis, int &myState){
  unsigned long currentMillis = micros();
  
  if (myPWM > 255){myPWM = 255;}
  if (myPWM < 0){myPWM = 0;}
  
  myPWM = (int) map(myPWM, 0, 255, 0, 1023);
  
  if (myState == LOW){      
     if(currentMillis - myMillis > myPWM){
        myState = HIGH;
        digitalWrite(myPin, myState);  
        myMillis = currentMillis;
      }     
  } else {
     if(currentMillis - myMillis > 1023-myPWM){
        myState = LOW;
        digitalWrite(myPin, myState);    
        myMillis = currentMillis;  
     }
  } 
}
