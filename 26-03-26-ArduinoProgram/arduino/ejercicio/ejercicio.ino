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
  //Serial.write(buttonState);
  Serial.println("A0 5342.67");
  //Serial.println(buttonState);
  //Serial.write(pot);
  knightRider(pot);
}

void knightRider(int pot) {
  delay(pot);
  turnOnOffLeds(true, false, false, false);
  delay(pot);
  turnOnOffLeds(false, true, false, false);
  delay(pot);
  turnOnOffLeds(false, false, true, false);
  delay(pot);
  turnOnOffLeds(false, false, false, true);
  delay(pot);
  turnOnOffLeds(false, false, true, false);
  delay(pot);
  turnOnOffLeds(false, true, false, false); 
}


void turnOnOffLeds (bool l1, bool l2, bool l3, bool l4) {
  digitalWrite(ledOutput0, l1);
  digitalWrite(ledOutput1, l2);
  digitalWrite(ledOutput2, l3);
  digitalWrite(ledOutput3, l4);

}


void allLedsHigh() {
  digitalWrite(ledOutput0, HIGH);
  digitalWrite(ledOutput1, HIGH);
  digitalWrite(ledOutput2, HIGH);
  digitalWrite(ledOutput3, HIGH);
}

void allLedsLow () {
  digitalWrite(ledOutput0, LOW);
  digitalWrite(ledOutput1, LOW);
  digitalWrite(ledOutput2, LOW);
  digitalWrite(ledOutput3, LOW);
}

void halfHighLowA () {
  digitalWrite(ledOutput0, LOW);
  digitalWrite(ledOutput1, HIGH);
  digitalWrite(ledOutput2, LOW);
  digitalWrite(ledOutput3, HIGH);
}

void halfHighLowB () {
  digitalWrite(ledOutput0, HIGH);
  digitalWrite(ledOutput1, LOW);
  digitalWrite(ledOutput2, HIGH);
  digitalWrite(ledOutput3, LOW);
}

void load1 (){
  digitalWrite(ledOutput0, HIGH);
  digitalWrite(ledOutput1, LOW);
  digitalWrite(ledOutput2, LOW);
  digitalWrite(ledOutput3, LOW);
}

void load2 (){
  digitalWrite(ledOutput0, HIGH);
  digitalWrite(ledOutput1, HIGH);
  digitalWrite(ledOutput2, LOW);
  digitalWrite(ledOutput3, LOW);
}

void load3 (){
  digitalWrite(ledOutput0, HIGH);
  digitalWrite(ledOutput1, HIGH);
  digitalWrite(ledOutput2, HIGH);
  digitalWrite(ledOutput3, LOW);
}

void load4 (){
  digitalWrite(ledOutput0, HIGH);
  digitalWrite(ledOutput1, HIGH);
  digitalWrite(ledOutput2, HIGH);
  digitalWrite(ledOutput3, HIGH);
}
