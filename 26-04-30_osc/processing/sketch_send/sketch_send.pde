import oscP5.*;
import netP5.*;

OscP5 oscp5;
NetAddress servidor;

void setup () {
  oscp5 = new OscP5(this, 10000);
  servidor = new NetAddress("127.0.0.1",10001);
}

void draw () {
  background(0);
}

void mouseClicked() {
  println("Hice click " + str(millis()));
  OscMessage msg = new OscMessage("/tiempo");
  msg.add(millis());
  oscp5.send(msg, servidor);
}
