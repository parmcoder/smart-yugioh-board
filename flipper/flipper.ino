const int buttonPin = 2;      // the pin that the LED is attached to

int voltage = 0;
bool isClicked = false;
bool isShow = false;
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  //  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  //  Serial
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);           // tell servo to go to position in variable 'pos'

}

void loop() {
  int getButton = digitalRead(A5);
  if ((isClicked == false) && (getButton == LOW)) {
    //    Serial.println("Circulating");
    Serial.println(isShow);
    if (isShow) {
      myservo.write(0);           // tell servo to go to position in variable 'pos'

    } else {
      myservo.write(90);           // tell servo to go to position in variable 'pos'

    }
    isShow = !isShow;

    isClicked = true;
  } else if ((isClicked == true) && (getButton == HIGH)) {
    isClicked = false;
  }
  delay(10);
}
