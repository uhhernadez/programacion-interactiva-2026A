int pushButton = 2;
const int outLed = 11;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {
  char puredata = 0;
  if(Serial.available()) {
    puredata = Serial.read();
  }
  analogWrite(outLed, puredata);
}


