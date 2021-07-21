const int buttonPin = 2;      // the pin that the LED is attached to

int voltage = 0;
#include <Servo.h> //
Servo myServos[5];

void setup() {
  // initialize the serial communication:
//  Serial.begin(9600);
  // initialize the ledPin as an output:
  //  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  //  Serial
  for (int i = 0; i < 5; i++)
  {
    myServos[i].attach(i + 2);
    myServos[i].write(0);
  }
}

bool isShow[] = {false, false, false, false, false};
bool isClicked[] = {false, false, false, false, false};

void loop() {
  int getButton1 = digitalRead(A0);
  int getButton2 = digitalRead(A1);
  int getButton3 = digitalRead(A2);
  int getButton4 = digitalRead(A3);
  int getButton5 = digitalRead(A4);
  int sensorsValues[] = {getButton1, getButton2, getButton3, getButton4, getButton5};

  for ( int i = 0; i < 5; i++) {
    //    Serial.println("Circulating");

    if ((isClicked[i] == false) && (sensorsValues[i] == LOW)) {
//      Serial.println("pressed");
//      Serial.println(isShow[i]);
//      Serial.print(i);
      if (isShow[i]) {
        myServos[i].write(0);           // tell servo to go to position in variable 'pos'
//        delay(100);


      } else {
        myServos[i].write(100);           // tell servo to go to position in variable 'pos'
//        delay(100);

      }
      isShow[i] = !isShow[i];

      isClicked[i] = true;
    } else if ((isClicked[i] == true) && (sensorsValues[i] == HIGH)) {
//      Serial.println("not pressed");
//      Serial.print(isShow[i]);
      isClicked[i] = false;
    }
  }
  delay(10);

}
