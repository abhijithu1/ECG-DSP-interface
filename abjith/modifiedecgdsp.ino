// Existing pin definitions remain unchanged

void setup() {
  pinMode(clockPin, OUTPUT); 
  pinMode(inputPin1, INPUT);
  pinMode(inputPin2, INPUT);
  pinMode(inputPin3, INPUT);
  pinMode(inputPin4, INPUT);
  pinMode(inputPin5, INPUT);
  pinMode(inputPin6, INPUT);
  pinMode(inputPin7, INPUT);
  pinMode(inputPin8, INPUT);

  Serial.begin(9600); 
}

void loop() {
  digitalWrite(clockPin, HIGH); 
  delay(delayTime);             
  digitalWrite(clockPin, LOW);  
  delay(delayTime);             

  String binaryData = "";
  binaryData += String(digitalRead(inputPin8));
  binaryData += String(digitalRead(inputPin7));
  binaryData += String(digitalRead(inputPin6));
  binaryData += String(digitalRead(inputPin5));
  binaryData += String(digitalRead(inputPin4));
  binaryData += String(digitalRead(inputPin3));
  binaryData += String(digitalRead(inputPin2));
  binaryData += String(digitalRead(inputPin1));

  int decimalValue = 0;
  for (int i = 0; i < binaryData.length(); i++) {
    decimalValue = (decimalValue << 1) | (binaryData[i] - '0');
  }

  float voltage = ((decimalValue / 256.0) * 5);

  // Print timestamp + voltage
  Serial.print(millis());
  Serial.print(","); 
  Serial.println(voltage, 3); 
}
