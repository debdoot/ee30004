// pins for the LEDs in Pixel 1:
const int pix1RedPin = 3;
const int pix1GreenPin = 5;
const int pix1BluePin = 6;

// pins for the LEDs in Pixel 2:
const int pix2RedPin = 9;
const int pix2GreenPin = 10;
const int pix2BluePin = 11;

int refreshCounter = 0;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(pix1RedPin, OUTPUT);
  pinMode(pix1GreenPin, OUTPUT);
  pinMode(pix1BluePin, OUTPUT);
  
  pinMode(pix2RedPin, OUTPUT);
  pinMode(pix2GreenPin, OUTPUT);
  pinMode(pix2BluePin, OUTPUT);

}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int pix1Red = Serial.parseInt();
    // do it again:
    int pix1Green = Serial.parseInt();
    // do it again:
    int pix1Blue = Serial.parseInt();
    // Check to see if only one pixel value entered, then replicate
    if (Serial.read() == '\n') {
      refreshCounter = refreshCounter + 1;
      // constrain the values to 0 - 255
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
      pix1Red = constrain(pix1Red, 0, 255);
      pix1Green = constrain(pix1Green, 0, 255);
      pix1Blue = constrain(pix1Blue, 0, 255);

      // fade the red, green, and blue legs of the LED:
      analogWrite(pix1RedPin, pix1Red);
      analogWrite(pix1GreenPin, pix1Green);
      analogWrite(pix1BluePin, pix1Blue);

      analogWrite(pix2RedPin, pix1Red);
      analogWrite(pix2GreenPin, pix1Green);
      analogWrite(pix2BluePin, pix1Blue);

      // print the three numbers in one string as hexadecimal:
      Serial.print("Trial # ");
      Serial.println(refreshCounter, DEC);
      
      Serial.print("Pixel 1 ");
      Serial.print(pix1Red, DEC); 
      Serial.print(",");
      Serial.print(pix1Green, DEC); 
      Serial.print(",");
      Serial.println(pix1Blue, DEC);
      
      Serial.print("Pixel 2 ");
      Serial.print(pix1Red, DEC); 
      Serial.print(",");
      Serial.print(pix1Green, DEC); 
      Serial.print(",");
      Serial.println(pix1Blue, DEC);
    }
    // do it again:
    int pix2Red = Serial.parseInt();
    // do it again:
    int pix2Green = Serial.parseInt();
    // do it again:
    int pix2Blue = Serial.parseInt();
    
    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
      refreshCounter = refreshCounter + 1;
      // constrain the values to 0 - 255
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
      pix1Red = constrain(pix1Red, 0, 255);
      pix1Green = constrain(pix1Green, 0, 255);
      pix1Blue = constrain(pix1Blue, 0, 255);

      pix2Red = constrain(pix2Red, 0, 255);
      pix2Green = constrain(pix2Green, 0, 255);
      pix2Blue = constrain(pix2Blue, 0, 255);

      // fade the red, green, and blue legs of the LED:
      analogWrite(pix1RedPin, pix1Red);
      analogWrite(pix1GreenPin, pix1Green);
      analogWrite(pix1BluePin, pix1Blue);

      analogWrite(pix2RedPin, pix2Red);
      analogWrite(pix2GreenPin, pix2Green);
      analogWrite(pix2BluePin, pix2Blue);

      // print the three numbers in one string as hexadecimal:
      Serial.print("Trial # ");
      Serial.println(refreshCounter, DEC);
      
      Serial.print("Pixel 1 ");
      Serial.print(pix1Red, DEC); 
      Serial.print(",");
      Serial.print(pix1Green, DEC); 
      Serial.print(",");
      Serial.println(pix1Blue, DEC);
      
      Serial.print("Pixel 2 ");
      Serial.print(pix2Red, DEC); 
      Serial.print(",");
      Serial.print(pix2Green, DEC); 
      Serial.print(",");
      Serial.println(pix2Blue, DEC);
    }
  }
}
