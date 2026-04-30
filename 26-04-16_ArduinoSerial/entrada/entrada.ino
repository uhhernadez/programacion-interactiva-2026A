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
  int remapPhoto = map (photorest, 40, 540, 0, 2000);
  String send1;
  send1 = msg1 + remapPhoto;
  Serial.println(send1);
  String msg2 = "A0 ";
  // Los valores del intervalo depende totalmente del circuito
  int remapP = map(potenciometer, 0, 512, 0, 1000);
  String send2;
  send2 = msg2 + remapP;
  Serial.println(send2);
  //delay(1000);
}
