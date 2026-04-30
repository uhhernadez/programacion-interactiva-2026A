int pushButton = 2;
const int outLed = 11;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {
  
  if(Serial.available()) {
    int puredata = 0;
    puredata = Serial.parseInt();

    while(Serial.available() > 0) {
      Serial.read();
    }
    analogWrite(outLed, puredata);
  }
  
}


