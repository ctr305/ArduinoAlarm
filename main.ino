#include <LiquidCrystal.h>
#include <Keypad.h>

#define LED A5
#define BUZ A4

const int RS = 12,EN = 11,D4 = 10,D5 = 9,D6 = 8,D7 = 7;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
	{'*', '0', '#'}
};
byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {6, 5, 4};

Keypad keypad = Keypad (makeKeymap(keys), rowPins, colPins, ROWS, COLS);

bool armed, triggered;
const int limit = 10;
const String password = "1234";
String input_password;

void setup(){

	armed = true;
	triggered = false;
	input_password.reserve(32);
	
	Serial.begin(9600);
	lcd.begin(16,2);
	pinMode(LED,OUTPUT);
	pinMode(BUZ,OUTPUT);
}

void loop(){

	if(!triggered){
		char key = keypad.getKey();
	
		if (key != NO_KEY){
			if(key == '*'){
				input_password = "";
			}else if(key == '#'){
				if(input_password == password){
					armed = false;
					lcd.clear();
					lcd.setCursor(0,0);
					lcd.print("Correct Pass");
					lcd.setCursor(0,1);
					lcd.print("(;_;)");
				}else{
					lcd.setCursor(0,1);
					lcd.print("Wrong Pass");
					input_password = "";
				}
			}else{
				input_password += key;
			}
		}
	}
	
	if(armed){
		if((millis()/1000)>=limit){
			triggered = true;
		}
		lcd.setCursor(0,0);
		lcd.print(millis()/1000);
		lcd.print("s / 10 left.");
	}else{
		while(1){} //Detiene el proceso
	}
	
	if(triggered){
		digitalWrite(LED,HIGH);
		digitalWrite(BUZ,HIGH);
		while(1){}
	}
}
