int pushButton = 2;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {  
  if (Serial.available())  {
    int intensidad = Serial.parseInt();
    
    // Limpiar el buffer de remanentes como '\n' o '\r'
    while(Serial.available() > 0) {
      Serial.read();
    }
    analogWrite(11, intensidad);
    Serial.println(intensidad);
  }
  
}
