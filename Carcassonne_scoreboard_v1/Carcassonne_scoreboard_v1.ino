
#include <Keypad.h>

const byte ROWS_V = 4; //four ROWS_V
const byte COLS_V = 4; //four columns
const byte ROWS_P = 2;
const byte COLS_P = 3;

//define the cymbols on the buttons of the keypads
char wartosci[ROWS_V][COLS_V] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

char gracze[ROWS_P][COLS_P] = {
  {'G','Y','R'},
  {'B','P','K'}
};
byte rowPins_v[ROWS_V] = {7, 6, 5, 4}; //connect to the row pinouts of the keypad
byte colPins_v[COLS_V] = {3, 2, 1, 0}; //connect to the column pinouts of the keypad

byte rowPins_p[ROWS_P] = {8, 9};
byte colPins_p[COLS_P] = {10, 11, 12};

//initialize an instance of class NewKeypad
Keypad valueKeypad = Keypad( makeKeymap(wartosci), rowPins_v, colPins_v, ROWS_V, COLS_V); 
Keypad playerKeypad = Keypad( makeKeymap(gracze), rowPins_p, colPins_p, ROWS_P, COLS_P); 

void setup(){
  Serial.begin(9600);
}

char valueKey;
char playerKey;

void loop(){
  valueKey = valueKeypad.getKey();
  playerKey = playerKeypad.getKey();
  
  if(playerKey)
  {
    Serial.println(playerKey);
  }
  else if(valueKey)
  {
    Serial.println(valueKey);
  }

}
