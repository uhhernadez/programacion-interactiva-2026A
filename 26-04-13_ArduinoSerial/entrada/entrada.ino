int pushButton = 2;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {
  int buttonState = digitalRead(pushButton);
  int potenciometer = analogRead(A0);
  int photorest = analogRead(A3);
  
  String msg1 = "A3 ";
  String send1;
  send1 = msg1 + photorest;
  Serial.println(send1);
  String msg2 = "A0 ";
  String send2;
  send2 = msg2 + potenciometer;
  Serial.println(send2);
}
