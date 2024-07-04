int mux[8][3] = {{0,0,0}, {0,0,1}, {0,1,0}, {0,1,1}, {1,0,0}, {1,0,1}, {1,1,0}, {1,1,1}};
int result[64];

float ans;

void setup() {
  Serial.begin(115200);

  pinMode(2, OUTPUT); //C1
  pinMode(3, OUTPUT); //B1
  pinMode(4, OUTPUT); //A1
  pinMode(5, OUTPUT); //C2
  pinMode(6, OUTPUT); //B2
  pinMode(7, OUTPUT); //A2

}

void loop() {
  int iter = 0;
  for(int i=0; i<8; i++){ 
    
    digitalWrite(5, mux[i][0]);
    digitalWrite(6, mux[i][1]);
    digitalWrite(7, mux[i][2]);

    //Serial.print(i+1);
    //Serial.print(": ");
      
    for(int j=0; j<8; j++){ 
      digitalWrite(2, mux[j][0]);
      digitalWrite(3, mux[j][1]);
      digitalWrite(4, mux[j][2]);
      
      delay(1);
  
      ans = analogRead(A0);

      result[iter] = ans;
      iter+=1;

      //Serial.print(ans);
      //Serial.print(", ");    
    }
   //Serial.println("");
  }
  //Serial.println("---");
  for (int i=0; i<64 ;i++){
    Serial.println(result[i]);
  }
  Serial.println("Done");
  delay(500);
}
