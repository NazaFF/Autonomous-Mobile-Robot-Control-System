void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // reads the input on analog pin A0 (value between 0 and 1023)
  int analogValue = analogRead(A0);

  Serial.print("Analog reading: ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 10) {
    Serial.println(" - Dark");
  } else if (analogValue < 200) {
    Serial.println(" - Dim");
  } else if (analogValue < 500) {
    Serial.println(" - Light");
  } else if (analogValue < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }

  delay(500);
}


//int light_sensor = A3; 
 
//void setup() {
//Serial.begin(9600); //begin Serial Communication
//}
 
//void loop() {
//  int raw_light = analogRead(light_sensor); // read the raw value from light_sensor pin (A3)
 // int light = map(raw_light, 0, 1023, 0, 100); // map the value from 0, 1023 to 0, 100
 
//  Serial.print("Light level: "); 
//  Serial.println(light); // print the light value in Serial Monitor
 
//  delay(1000); // add a delay to only read and print every 1 second
//}