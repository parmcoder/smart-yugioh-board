/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

int myPins[] = {2, 3, 4, 5, 6, 7};

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);

}
// the loop function runs over and over again forever
void loop() {
  int sv1 = analogRead(A0);
  int sv2 = analogRead(A1);
  int sv3 = analogRead(A2);
  int sv4 = analogRead(A3);
  int sv5 = analogRead(A4);
  int sv6 = analogRead(A5);
  int sensorsValues[] = {sv1, sv2, sv3, sv4, sv5, sv6};
  for ( int i = 0; i < 6; i++) {
    if (sensorsValues[i] > 100) {
      digitalWrite(myPins[i], LOW);   // turn the LED on (HIGH is the voltage level)
    }
    else {
      digitalWrite(myPins[i], HIGH);   // turn the LED on (HIGH is the voltage level)
    }
    if (i == 5) {
//      Serial.println("at ");
//      Serial.print(i);
      Serial.println(sensorsValues[i]);
    }


  }


  // print out the value you read:
  //  Serial.println(sensorValue);
  delay(2);        // delay in between reads for stability
  // wait for a second
}
