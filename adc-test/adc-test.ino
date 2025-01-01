int clockPin = 9; // Define the pin for clock output
int delayTime = 10; // Delay time in milliseconds for 100 Hz frequency

// Define individual input pins
int inputPin1 = 2;
int inputPin2 = 3;
int inputPin3 = 4;
int inputPin4 = 5;
int inputPin5 = 6;
int inputPin6 = 7;
int inputPin7 = 8;
int inputPin8 = 10;

void setup() {
  pinMode(clockPin, OUTPUT); // Set the clock pin as output

  // Set each input pin as INPUT
  pinMode(inputPin1, INPUT);
  pinMode(inputPin2, INPUT);
  pinMode(inputPin3, INPUT);
  pinMode(inputPin4, INPUT);
  pinMode(inputPin5, INPUT);
  pinMode(inputPin6, INPUT);
  pinMode(inputPin7, INPUT);
  pinMode(inputPin8, INPUT);

  Serial.begin(9600); // Initialize Serial Monitor at 9600 baud
}

void loop() {
  // Generate clock signal
  digitalWrite(clockPin, HIGH); // Set the clock pin HIGH
  delay(delayTime);             // Wait for 5 ms
  digitalWrite(clockPin, LOW);  // Set the clock pin LOW
  delay(delayTime);             // Wait for 5 ms

  // Read the state of each input pin and build binary string
  String binaryData = "";
  binaryData += String(digitalRead(inputPin8)); // Read Pin 2
  binaryData += String(digitalRead(inputPin7)); // Read Pin 3
  binaryData += String(digitalRead(inputPin6)); // Read Pin 4
  binaryData += String(digitalRead(inputPin5)); // Read Pin 5
  binaryData += String(digitalRead(inputPin4)); // Read Pin 6
  binaryData += String(digitalRead(inputPin3)); // Read Pin 7
  binaryData += String(digitalRead(inputPin2)); // Read Pin 8
  binaryData += String(digitalRead(inputPin1)); // Read Pin 10

  // Convert binary string to decimal
  int decimalValue = 0;
  for (int i = 0; i < binaryData.length(); i++) {
    decimalValue = (decimalValue << 1) | (binaryData[i] - '0');
  }

  // Calculate voltage using the equation: (decimal number / 256) * 3.88
  float voltage = ((decimalValue / 256.0) * 5);

  // Output only the voltage for serial plotter
  Serial.println(voltage, 3); // Display with 3 decimal places
}