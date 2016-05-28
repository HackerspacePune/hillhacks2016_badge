/*
  Hillhacks Badge example sketch

 When first powered up, LED on D1 blinks on and off at 100ms intervals.
 After push button on D0:  LED fades in and out.
 After push button again:  LED blinks kind of randomly
 After push button again:  LED fades in and out quickly
 Push button again: back to beginning to blink LED on and off at 100ms intervals.
 etc.

 The circuit:
 * LED attached from pin 1 to ground
 * pushbutton attached to pin 0 to ground


Hacked from Arduino example sketches:  Blink and Fade
 This example code is in the public domain.
*/

// constants won't change values
const int buttonPin = 0;         // the number of the pushbutton pin
const int ledPin =  1;           // the number of the LED pin
const int MAX_BUTTON_COUNT = 4;  // max number of cool things that can happen by pushing the button
const int MAX_RAND_BLINK = 10;   // number of different blink rates for the random blink for the 3rd button press

// variables will change values
int buttonCount = 0;         // keep track of the number of times the button is pushed

int brightness = 0;          // how bright the LED is when we're in case 1)
int fadeAmount = 5;          // how many points to fade the LED by when we're in case 1)

int randomBlinkState = 0;    // keeps track of where we're at in the random blinking for case 2


// see if the button is being pushed, and if so, increment the buttonCount
int readButton() {  
  int buttonState = 0;   // variable for reading the pushbutton status

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);  // buttonState will be LOW if button is being pushed

  // if button is being pushed, increment the buttonCount
  if (buttonState == LOW) {
    buttonCount++;
    // reset the buttonCount to 0 if we've reached the max number
    if (buttonCount == MAX_BUTTON_COUNT) {
      buttonCount = 0;
    }
  }  

  // wait for button to stop being pressed
  while (buttonState == LOW) {
    buttonState = digitalRead(buttonPin);  // buttonState will be LOW if button is still being pushed
    delay(10);
  }
}


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  // See if the button is being pushed -- buttonCount is automatically incremented if it is
  readButton();

  // The LED will do something different depending on the number of times the button has been pushed
  switch(buttonCount) {

    // For case 0, the LED blinks on and off at 10msec intervals
    case 0 :
      digitalWrite(ledPin, HIGH); 
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);

      break;  // end of case 0


    // For case 1, the LED fades in and out
    case 1 :
      // set the brightness of the LED on pin 1:
      analogWrite(ledPin, brightness);

      // change the brightness for next time through the loop:
      brightness = brightness + fadeAmount;

      // reverse the direction of the fading at the ends of the fade:
      if (brightness == 0 || brightness == 255) {
        fadeAmount = -fadeAmount ;
      }

      // wait for 30 milliseconds to see the dimming effect
      delay(30);

      break;  // end of case 1


    // For case 2, the LED blinks on and off kind of randomly
    case 2 :

      switch (randomBlinkState) {
        case 0:
          digitalWrite(ledPin, HIGH); 
          delay(100);
          digitalWrite(ledPin, LOW);
          delay(100);
          // increment to next random blink state, and reset to 0 if reached the max state
          randomBlinkState++;
          if (randomBlinkState == MAX_RAND_BLINK) randomBlinkState = 0;
          break;
        case 1:
          digitalWrite(ledPin, HIGH); 
          delay(100);
          digitalWrite(ledPin, LOW);
          delay(500);
          // increment to next random blink state, and reset to 0 if reached the max state
          randomBlinkState++;
          if (randomBlinkState == MAX_RAND_BLINK) randomBlinkState = 0;
          break;
        case 2:
          digitalWrite(ledPin, HIGH); 
          delay(100);
          digitalWrite(ledPin, LOW);
          delay(100);
          // increment to next random blink state, and reset to 0 if reached the max state
          randomBlinkState++;
          if (randomBlinkState == MAX_RAND_BLINK) randomBlinkState = 0;
          break;
        case 3:
          digitalWrite(ledPin, HIGH); 
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
          // increment to next random blink state, and reset to 0 if reached the max state
          randomBlinkState++;
          if (randomBlinkState == MAX_RAND_BLINK) randomBlinkState = 0;
          break;
        case 4:
          digitalWrite(ledPin, HIGH); 
          delay(50);
          digitalWrite(ledPin, LOW);
          delay(100);
          // increment to next random blink state, and reset to 0 if reached the max state
          randomBlinkState++;
          if (randomBlinkState == MAX_RAND_BLINK) randomBlinkState = 0;
          break;
        case 5:
          digitalWrite(ledPin, HIGH); 
          delay(50);
          digitalWrite(ledPin, LOW);
          delay(100);
          // increment to next random blink state, and reset to 0 if reached the max state
          randomBlinkState++;
          if (randomBlinkState == MAX_RAND_BLINK) randomBlinkState = 0;
          break;
        case 6:
          digitalWrite(ledPin, HIGH); 
          delay(50);
          digitalWrite(ledPin, LOW);
          delay(100);
          // increment to next random blink state, and reset to 0 if reached the max state
          randomBlinkState++;
          if (randomBlinkState == MAX_RAND_BLINK) randomBlinkState = 0;
          break;
        case 7:
          digitalWrite(ledPin, HIGH); 
          delay(100);
          digitalWrite(ledPin, LOW);
          delay(500);
          // increment to next random blink state, and reset to 0 if reached the max state
          randomBlinkState++;
          if (randomBlinkState == MAX_RAND_BLINK) randomBlinkState = 0;
          break;
        case 8:
          digitalWrite(ledPin, HIGH); 
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(100);
          // increment to next random blink state, and reset to 0 if reached the max state
          randomBlinkState++;
          if (randomBlinkState == MAX_RAND_BLINK) randomBlinkState = 0;
          break;
        case 9:
          digitalWrite(ledPin, HIGH); 
          delay(100);
          digitalWrite(ledPin, LOW);
          delay(100);
          // increment to next random blink state, and reset to 0 if reached the max state
          randomBlinkState++;
          if (randomBlinkState == MAX_RAND_BLINK) randomBlinkState = 0;
          break;
      }
      
      break;  // end of case 2


    // For case 1, the LED fades in and out
    case 3 :
      // set the brightness of the LED on pin 1:
      analogWrite(ledPin, brightness);

      // change the brightness for next time through the loop:
      brightness = brightness + fadeAmount;

      // reverse the direction of the fading at the ends of the fade:
      if (brightness == 0 || brightness == 255) {
        fadeAmount = -fadeAmount ;
      }

      // wait for 5 milliseconds to see the dimming effect
      delay(5);

      break;  // end of case 3

  }
}

