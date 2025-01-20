int mux[8][3] = {
    {0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1}, 
    {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}
};
int result[64]; // Stores the 8x8 matrix readings

float ans;

void setup() {
  Serial.begin(115200);

  // Set all mux control pins as OUTPUT
  pinMode(2, OUTPUT); // C1
  pinMode(3, OUTPUT); // B1
  pinMode(4, OUTPUT); // A1
  pinMode(5, OUTPUT); // C2
  pinMode(6, OUTPUT); // B2
  pinMode(7, OUTPUT); // A2
}

void loop() {
  int iter = 0;  // Index for the result array

  for (int i = 0; i < 8; i++) { 
    digitalWrite(5, mux[i][0]);  // Set MUX2 controls
    digitalWrite(6, mux[i][1]);
    digitalWrite(7, mux[i][2]);

    for (int j = 0; j < 8; j++) { 
      digitalWrite(2, mux[j][0]);  // Set MUX1 controls
      digitalWrite(3, mux[j][1]);
      digitalWrite(4, mux[j][2]);

      delay(10);  // Allow MUX switching delay

      ans = analogRead(A0);  // Read the sensor value
      result[iter] = (int)ans;  // Store in the result array
      iter++;
    }
  }

  // Send the result array over Serial
  for (int i = 0; i < 64; i++) {
    Serial.println(result[i]);
  }

  Serial.println("Done");  // Indicate end of transmission
  delay(500);  // Wait before the next transmission
}
