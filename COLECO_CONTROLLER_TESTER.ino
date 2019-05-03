// Colecovision and Adam Controller Tester
// 20190503 michael flemming
// Super Action Controller, Driving Controller, and Roller controller not yet supported
// series type Controller does not use Pin 7 and 9 
// roller controller, prototype controller and driving controller use Pins 7 and 9 
// please note that diodes in coleco controller schematic 1.0 have wrong polarity 

// pinout PIN1 is Pin1 of D Sub 9 
// use digital pins

#define PIN1 2
#define PIN2 3
#define PIN3 4
#define PIN4 5
#define PIN5 6
#define PIN6 7
#define PIN7 8
#define PIN8 9
#define PIN9 10


void setup() 
{
 Serial.begin(115200);
  pinMode(PIN1, INPUT);
  pinMode(PIN2, INPUT);
  pinMode(PIN3, INPUT);
  pinMode(PIN4, INPUT);
  pinMode(PIN5, INPUT);
  pinMode(PIN6, INPUT);
  pinMode(PIN7, INPUT);
  pinMode(PIN8, INPUT);
  pinMode(PIN9, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

 Serial.println("Coleco Controller Test");

}

void loop() 
{
 // button variables for joystick, fire and arm button
 unsigned char btn_up, btn_down,btn_left, btn_right,btn_fire, btn_arm;
 
 // button variables for numbers star and hash key
 unsigned char btn_1, btn_2,btn_3, btn_4,btn_5,btn_6, btn_7,btn_8, btn_9,btn_0, btn_star,btn_hash;

 // temporary variables to convert keyboard buttons to number
 unsigned char btn_pin1,btn_pin2,btn_pin3,btn_pin4;
 unsigned char convertinput;  

 // output variables 
 unsigned char convertoutput;
 unsigned int buttonState;
    
 // configuration for joystick and left fire button <-> atari pinout
 pinMode(PIN1, INPUT_PULLUP);
 pinMode(PIN2, INPUT_PULLUP);
 pinMode(PIN3, INPUT_PULLUP);
 pinMode(PIN4, INPUT_PULLUP);
 pinMode(PIN5, INPUT_PULLUP);
 pinMode(PIN6, INPUT_PULLUP);
 pinMode(PIN7, INPUT_PULLUP);
 pinMode(PIN9, INPUT_PULLUP);
 digitalWrite(PIN8, LOW);
 pinMode(PIN8, OUTPUT);

 delay(10); // wait some msec before reading pins

 // read joystick and left fire button
  btn_up    = (digitalRead(PIN1)==true)?0:1; 
  btn_down  = (digitalRead(PIN2)==true)?0:1; 
  btn_left  = (digitalRead(PIN3)==true)?0:1; 
  btn_right = (digitalRead(PIN4)==true)?0:1; 
  btn_fire  = (digitalRead(PIN6)==true)?0:1; 

 // configuration for keyboard and arm button 

 pinMode(PIN8, INPUT_PULLUP);
 digitalWrite(PIN5, LOW);
 pinMode(PIN5, OUTPUT);

  delay(10); // wait some msec before reading pins

 // read arm key <-> right fire button
 btn_arm  = (digitalRead(PIN6)==true)?0:1; 

 // read keyboard
 btn_pin1  = (digitalRead(PIN1)==true)?0:1; 
 btn_pin2  = (digitalRead(PIN2)==true)?0:1; 
 btn_pin3  = (digitalRead(PIN3)==true)?0:1; 
 btn_pin4  = (digitalRead(PIN4)==true)?0:1; 

 // encode buttons to one output variable
  buttonState = btn_up * 512 + btn_down * 256 + btn_left * 128 + btn_right * 64 + btn_fire * 32 + btn_arm * 16 + btn_pin1 * 8 + btn_pin2 * 4 + btn_pin3 * 2 + btn_pin4;

 // convert keyboardlines to temporary variable
  convertinput = btn_pin1 * 8 + btn_pin2 * 4 + btn_pin3 * 2 + btn_pin4;
  
  // reset single keyboard button variables
  btn_1=0; btn_2=0;btn_3=0;btn_4=0;btn_5=0;btn_6=0; btn_7=0;btn_8=0; btn_9=0;btn_0=0; btn_star=0;btn_hash=0;

  // convert temporary variable to keys 1...9 => 1...9; 0=>10; star=> 11; hash => 12
  // and at the same time set single keyboard button variables
   switch (convertinput)
   {
    case 0:    // no key
      convertoutput = 0;
      break;
    case 1:    // key
      convertoutput = 1;
      btn_1 =1;
      break;
    case 2:    // key
      convertoutput = 2;
      btn_2 =1;
      break;
    case 9:    // key
      convertoutput = 3;
      btn_3 =1;
      break;
    case 14:    // key
      convertoutput = 4;
      btn_4 =1;
      break;
    case 6:    // key
      convertoutput = 5;
      btn_5 =1;
      break;
    case 8:    // key
      convertoutput = 6;
      btn_6 =1;
      break;
    case 3:    // key
      convertoutput = 7;
      btn_7 =1;
      break;
    case 7:    // key
      convertoutput = 8;
      btn_8 =1;
      break;
    case 4:    // key 
      convertoutput = 9;
      btn_9 =1;
      break;
    case 5:    // key *
      convertoutput = 11;
      btn_star=1;
      break;
    case 12:    // key 0
      convertoutput = 10;
      btn_0 =1;
      break;
    case 10:    // key #
      convertoutput = 12;
      btn_hash=1;
      break;
    default :    // error
      convertoutput = 0;
      break;
   }

   /* // debug output 
  Serial.print(buttonState);
  Serial.print("-");
  Serial.print(convertinput);
  Serial.print("-");
  Serial.print(convertoutput);
  Serial.println();
  */

  // print status to monitor

  if (btn_up) Serial.println("up");
  if (btn_down) Serial.println("down");
  if (btn_left) Serial.println("left");
  if (btn_right) Serial.println("right");
  if (btn_fire) Serial.println("fire");
  if (btn_arm) Serial.println("arm");
  
  if (btn_1) Serial.println("1");
  if (btn_2) Serial.println("2");
  if (btn_3) Serial.println("3");
  if (btn_4) Serial.println("4");
  if (btn_5) Serial.println("5");
  if (btn_6) Serial.println("6");
  if (btn_7) Serial.println("7");
  if (btn_8) Serial.println("8");
  if (btn_9) Serial.println("9");
  if (btn_0) Serial.println("0");
  if (btn_star) Serial.println("star");
  if (btn_hash) Serial.println("hash");
 
 // make output readable
 delay(100); 

} 

 
