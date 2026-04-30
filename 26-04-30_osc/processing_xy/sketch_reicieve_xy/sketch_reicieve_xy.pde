import oscP5.*;
import netP5.*;

OscP5 oscp5;

void setup () {
  oscp5 = new OscP5(this, 10001);
}

int xOsc = -1;
int yOsc = -1;
void draw () {
  //background(200, 0, 0);
  point(xOsc, yOsc);
  println(xOsc + " " + yOsc);
}

void oscEvent(OscMessage msg) {
  msg.print();
  if (msg.checkAddrPattern("/pointer/x") == true) {
    xOsc = msg.get(0).intValue();
  } else if (msg.checkAddrPattern("/pointer/y") == true) {
    yOsc = msg.get(0).intValue();
  }
  
}
