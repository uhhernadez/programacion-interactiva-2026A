int pushButton = 2;
const int ledOutput0 = 8;
const int ledOutput1 = 9;
const int ledOutput2 = 10;
const int ledOutput3 = 11;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);

  pinMode(ledOutput0, OUTPUT);
  pinMode(ledOutput1, OUTPUT);
  pinMode(ledOutput2, OUTPUT);
  pinMode(ledOutput3, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(pushButton);
  int pot = analogRead(A0);
  Serial.write(buttonState);
  //Serial.println(buttonState);
  //Serial.write(pot);
  delay(pot);  
  digitalWrite(ledOutput0, LOW);
  digitalWrite(ledOutput1, LOW);
  digitalWrite(ledOutput2, LOW);
  digitalWrite(ledOutput3, LOW);
  delay(pot);  
  digitalWrite(ledOutput0, HIGH);
  digitalWrite(ledOutput1, HIGH);
  digitalWrite(ledOutput2, HIGH);
  digitalWrite(ledOutput3, HIGH);
}

