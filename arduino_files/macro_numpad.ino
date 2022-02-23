#include <Keypad.h>
#include <Keyboard.h>

#define LED1 15
#define LED2 14
#define LED3 16

bool layoutArun = false;
bool layoutBrun = false;
bool layoutCrun = false;
bool layoutDrun = true;

const byte ROWS = 4;
const byte COLS = 4;

char layoutKey = 'D';
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  digitalWrite(LED1, HIGH);
  delay(300);
  digitalWrite(LED1, LOW);
  delay(300);
  digitalWrite(LED2, HIGH);
  delay(300);
  digitalWrite(LED2, LOW);
  delay(300);
  digitalWrite(LED3, HIGH);
  delay(300);
  digitalWrite(LED3, LOW);
  delay(300);
}

void assign()
{
  layoutKey =  customKeypad.getKey();
  if(layoutKey)
  {
    if(layoutKey == 'A')
    {
      Serial.println("layout key assigned 'A'");
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
    }

    if(layoutKey == 'B')
    {
      Serial.println("layout key assigned 'B'");
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
    }

    if(layoutKey == 'C')
    {
      Serial.println("layout key assigned 'C'");
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
    }
    if(layoutKey == 'D')
    {
      Serial.println("layout key assigned 'D'");
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
    }
    decode(layoutKey);
  }
}

void decode(char layoutKey) 
{
  switch(layoutKey){
    case 'A':
    layoutArun = true;
    layoutBrun = false;
    layoutCrun = false;
    layoutDrun = false;
    Serial.println("layout key set 'A'");
    break;

    case 'B':
    layoutArun = false;
    layoutBrun = true;
    layoutCrun = false;
    layoutDrun = false;
    Serial.println("layout key set 'B'");
    break;

    case 'C':
    layoutArun = false;
    layoutBrun = false;
    layoutCrun = true;
    layoutDrun = false;
    Serial.println("layout key set 'C'");
    break;

    case 'D':
    layoutArun = false;
    layoutBrun = false;
    layoutCrun = false;
    layoutDrun = true;
    Serial.println("layout key set 'D'");
    break;
  }
  loop();
}

void loop()
{
  assign();
  char key = customKeypad.getKey();
  if(layoutDrun == true)
  switch(key)
  {
    case '1':
      Keyboard.write('1');
      Serial.println("1");
      break;
    case '2':
      Keyboard.write('2');
      Serial.println("2");
      break;
    case '3':
      Keyboard.write('3');
      Serial.println("3");
      break;
    case '4':
      Keyboard.write('4');
      Serial.println("4");
      break;
    case'5':
      Keyboard.write('5');
      Serial.println("5");
      break;
    case '6':
      Keyboard.write('6');
      Serial.println("6");
      break;
    case '7':
      Keyboard.write('7');
      Serial.println("7");
      break;
    case '8':
      Keyboard.write('8');
      Serial.println("8");
      break;
    case '9':
      Keyboard.write('9');
      Serial.println("9");
      break;
    case '*':
      Keyboard.write('*');
      Serial.println("*");
      break;
    case '0':
      Keyboard.write('0');
      Serial.println("0");
      break;
    case '#':
      Keyboard.write('#');
      Serial.println("#");
      break;
  }
  if(layoutArun == true)
  {
  	switch(key)
  	{
    	case '1':
      	Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(97);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release(97);
        Serial.println("ctrl A");
      	break;
      
    	case '2':
      	Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(120);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release(120);
        Serial.println("ctrl X");
      	break;
      
    	case '3':
      	Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(99);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release(99);
        Serial.println("ctrl C");
      	break;
      
    	case '4':
      	Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(118);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release(118);
        Serial.println("ctrl V");
      	break;
      
    	case'5':
      	Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(122);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release(122);
        Serial.println("ctrl Z");
      	break;
      
    	case '6':
      	Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(121);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release(121);
        Serial.println("ctrl Y");
      	break;
      
    	case '7':
      	Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(115);
        Keyboard.release(KEY_LEFT_GUI);
        Keyboard.release(KEY_LEFT_SHIFT);
        Keyboard.release(115);
        Serial.println("key left GUI shift s");
      	break;
      
    	case '8':
      	Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(115);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release(115);
        Serial.println("ctrl s");
      	break;
      
    	case '9':
      	Serial.println("9");
      	break;
      
    	case '*':
      	Serial.println("*");
      	break;
      
    	case '0':
      	Serial.println("0");
      	break;
      
    	case '#':
      	Serial.println("#");
      	break;
    }
  }
  if(layoutBrun == true)
  {
  	switch(key)
  	{
    	case '1':
      	Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_UP_ARROW);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release(KEY_LEFT_ALT);
        Keyboard.release(KEY_UP_ARROW);
        Serial.println("ctrl Alt up");
      	break;
      
    	case '2':
      	Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_DOWN_ARROW);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release(KEY_LEFT_ALT);
        Keyboard.release(KEY_DOWN_ARROW);
        Serial.println("ctrl Alt down");
      	break;
      
    	case '3':
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_UP_ARROW);
        Keyboard.release(KEY_LEFT_ALT);
        Keyboard.release(KEY_UP_ARROW);
        Serial.println("Alt up");
      	break;
      
    	case '4':
      	Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_DOWN_ARROW);
        Keyboard.release(KEY_LEFT_ALT);
        Keyboard.release(KEY_DOWN_ARROW);
        Serial.println("Alt down");
      	break;
      
    	case'5':
      	Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(109);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release(KEY_LEFT_SHIFT);
        Keyboard.release(109);
        Serial.println("ctrl shift m");
      	break;
      
    	case '6':
      	Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(100);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release(KEY_LEFT_SHIFT);
        Keyboard.release(100);
        Serial.println("ctrl shift d");
      	break;
      
    	case '7':
      	Serial.println("7");
      	break;
      
    	case '8':
      	Serial.println("8");
      	break;
      
    	case '9':
      	Serial.println("9");
      	break;
      
    	case '*':
      	Serial.println("*");
      	break;
      
    	case '0':
      	Serial.println("0");
      	break;
      
    	case '#':
      	Serial.println("#");
      	break;
    }
  }
  if(layoutCrun == true)
  {
  	switch(key)
  	{
    	case '1':
        Serial.println("1");
      	break;
      
    	case '2':
        Serial.println("2");
      	break;
      
    	case '3':
        Serial.println("3");
      	break;
      
    	case '4':
      	Serial.println("4");
      	break;
      
    	case'5':
      	Serial.println("5");
      	break;
      
    	case '6':
      	Serial.println("6");
      	break;
      
    	case '7':
      	Serial.println("7");
      	break;
      
    	case '8':
      	Serial.println("8");
      	break;
      
    	case '9':
      	Serial.println("9");
      	break;
      
    	case '*':
      	Serial.println("*");
      	break;
      
    	case '0':
      	Serial.println("0");
      	break;
      
    	case '#':
      	Serial.println("#");
      	break;
    }
  }
}
