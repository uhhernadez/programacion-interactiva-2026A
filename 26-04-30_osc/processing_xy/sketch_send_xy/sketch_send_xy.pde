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

void mouseMoved() {
  //println("Hice click " + str(millis()));
  OscMessage msgx = new OscMessage("/pointer/x");
  msgx.add(mouseX);
  oscp5.send(msgx, servidor);
  OscMessage msgy = new OscMessage("/pointer/y");
  msgy.add(mouseY);
  oscp5.send(msgy, servidor);
}
