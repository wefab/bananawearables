
int val;

int hb = A2;

int d1 = 9; 
int d2 = 11;
int d3 = 12;
int d4 = A1;

int sA = 5;
int sB = 4;
int sC = 13;
int sD = A0;
int sE = 10; 
int sF = 7;
int sG = 8;
int dp = 6;

int ledPin = 13; 
int sensorPin = A7; 
double alpha = 0.75; 
int period = 20; 
double change = 0.0;

void setup() {

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);

  pinMode(sA, OUTPUT);
  pinMode(sB, OUTPUT);
  pinMode(sC, OUTPUT);
  pinMode(sD, OUTPUT);
  pinMode(sE, OUTPUT);
  pinMode(sF, OUTPUT);
  pinMode(sG, OUTPUT);

  Serial.begin(9600);
  Serial.println();

}
void loop()
{
  static double oldValue = 0;   
  static double oldChange = 0;   
  int rawValue = analogRead (sensorPin);   
  double value = alpha * oldValue + (1 - alpha) * rawValue;
  //Serial.print (rawValue);   
  Serial.print (",");   
  Serial.println (value);   
  displayNumber(value);
  
  oldValue = value;   
  delay (period);   
  
  //val++;

//displayNumber(1000);

}

void displayNumber(int toDisplay) {

#define DISPLAY_BRIGHTNESS 5000
#define DIGIT_ON HIGH
#define DIGIT_OFF LOW

  long beginTime = millis();
  for (int digit = 4; digit > 0; digit--) {
    //digitalWrite(dp3, HIGH);
    //Turn on a digit for a short amount of time
    switch (digit) {
      case 1:
        digitalWrite(d1, DIGIT_ON);
        break;
      case 2:
        digitalWrite(d2, DIGIT_ON);
        break;
      case 3:
        digitalWrite(d3, DIGIT_ON);
        //digitalWrite(dp3, !hb);
        break;
      case 4:
        digitalWrite(d4, DIGIT_ON);
        break;
    }
    //digitalWrite(dphb, !hb);
    //Turn on the right segments for this digit
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS); //Display this digit for a fraction of a second (between 1us and 5000us, 500 is prettygood)
    //Turn off all segments
    lightNumber(10);
    //Turn off all digits
    digitalWrite(d1, DIGIT_OFF);
    digitalWrite(d2, DIGIT_OFF);
    digitalWrite(d3, DIGIT_OFF);
    digitalWrite(d4, DIGIT_OFF);
  }
  while ( (millis() - beginTime) < 10) ; //Wait for 20ms to pass before we paint the display again
}
//Given a number, turns on those segments
//If number == 10, then turn off number
void lightNumber(int numberToDisplay) {

#define SEGMENT_ON LOW
#define SEGMENT_OFF HIGH

  switch (numberToDisplay) {
    case 0:
      digitalWrite(sA, SEGMENT_ON);
      digitalWrite(sB, SEGMENT_ON);
      digitalWrite(sC, SEGMENT_ON);
      digitalWrite(sD, SEGMENT_ON);
      digitalWrite(sE, SEGMENT_ON);
      digitalWrite(sF, SEGMENT_ON);
      digitalWrite(sG, SEGMENT_OFF);
      break;
    case 1:
      digitalWrite(sA, SEGMENT_OFF);
      digitalWrite(sB, SEGMENT_ON);
      digitalWrite(sC, SEGMENT_ON);
      digitalWrite(sD, SEGMENT_OFF);
      digitalWrite(sE, SEGMENT_OFF);
      digitalWrite(sF, SEGMENT_OFF);
      digitalWrite(sG, SEGMENT_OFF);
      break;
    case 2:
      digitalWrite(sA, SEGMENT_ON);
      digitalWrite(sB, SEGMENT_ON);
      digitalWrite(sC, SEGMENT_OFF);
      digitalWrite(sD, SEGMENT_ON);
      digitalWrite(sE, SEGMENT_ON);
      digitalWrite(sF, SEGMENT_OFF);
      digitalWrite(sG, SEGMENT_ON);
      break;
    case 3:
      digitalWrite(sA, SEGMENT_ON);
      digitalWrite(sB, SEGMENT_ON);
      digitalWrite(sC, SEGMENT_ON);
      digitalWrite(sD, SEGMENT_ON);
      digitalWrite(sE, SEGMENT_OFF);
      digitalWrite(sF, SEGMENT_OFF);
      digitalWrite(sG, SEGMENT_ON);
      break;
    case 4:
      digitalWrite(sA, SEGMENT_OFF);
      digitalWrite(sB, SEGMENT_ON);
      digitalWrite(sC, SEGMENT_ON);
      digitalWrite(sD, SEGMENT_OFF);
      digitalWrite(sE, SEGMENT_OFF);
      digitalWrite(sF, SEGMENT_ON);
      digitalWrite(sG, SEGMENT_ON);
      break;
    case 5:
      digitalWrite(sA, SEGMENT_ON);
      digitalWrite(sB, SEGMENT_OFF);
      digitalWrite(sC, SEGMENT_ON);
      digitalWrite(sD, SEGMENT_ON);
      digitalWrite(sE, SEGMENT_OFF);
      digitalWrite(sF, SEGMENT_ON);
      digitalWrite(sG, SEGMENT_ON);
      break;
    case 6:
      digitalWrite(sA, SEGMENT_ON);
      digitalWrite(sB, SEGMENT_OFF);
      digitalWrite(sC, SEGMENT_ON);
      digitalWrite(sD, SEGMENT_ON);
      digitalWrite(sE, SEGMENT_ON);
      digitalWrite(sF, SEGMENT_ON);
      digitalWrite(sG, SEGMENT_ON);
      break;
    case 7:
      digitalWrite(sA, SEGMENT_ON);
      digitalWrite(sB, SEGMENT_ON);
      digitalWrite(sC, SEGMENT_ON);
      digitalWrite(sD, SEGMENT_OFF);
      digitalWrite(sE, SEGMENT_OFF);
      digitalWrite(sF, SEGMENT_OFF);
      digitalWrite(sG, SEGMENT_OFF);
      break;
    case 8:
      digitalWrite(sA, SEGMENT_ON);
      digitalWrite(sB, SEGMENT_ON);
      digitalWrite(sC, SEGMENT_ON);
      digitalWrite(sD, SEGMENT_ON);
      digitalWrite(sE, SEGMENT_ON);
      digitalWrite(sF, SEGMENT_ON);
      digitalWrite(sG, SEGMENT_ON);
      break;
    case 9:
      digitalWrite(sA, SEGMENT_ON);
      digitalWrite(sB, SEGMENT_ON);
      digitalWrite(sC, SEGMENT_ON);
      digitalWrite(sD, SEGMENT_ON);
      digitalWrite(sE, SEGMENT_OFF);
      digitalWrite(sF, SEGMENT_ON);
      digitalWrite(sG, SEGMENT_ON);
      break;
    case 10:
      digitalWrite(sA, SEGMENT_OFF);
      digitalWrite(sB, SEGMENT_OFF);
      digitalWrite(sC, SEGMENT_OFF);
      digitalWrite(sD, SEGMENT_OFF);
      digitalWrite(sE, SEGMENT_OFF);
      digitalWrite(sF, SEGMENT_OFF);
      digitalWrite(sG, SEGMENT_OFF);
      break;
  }
}
