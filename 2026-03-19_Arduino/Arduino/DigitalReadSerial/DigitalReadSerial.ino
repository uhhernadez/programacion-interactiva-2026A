int pushButton = 2;
int ledOutput = 9;
void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(ledOutput, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(pushButton);
  int pot = analogRead(A0);
  Serial.write(buttonState);
  //Serial.println(buttonState);
  //Serial.write(pot);
  delay(1);  
  digitalWrite(ledOutput, buttonState);
}

