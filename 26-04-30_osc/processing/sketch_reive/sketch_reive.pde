import oscP5.*;
import netP5.*;

OscP5 oscp5;

void setup () {
  oscp5 = new OscP5(this, 10001);
}

int millisOsc = 0;
void draw () {
  background(200, 0, 0);
  textAlign(CENTER);
  text("Mensaje: "+ millisOsc, 
      width/2.0,
      height/2.0);
}

void oscEvent(OscMessage msg) {
  msg.print();
  if (msg.checkAddrPattern("/tiempo") == true) {
    millisOsc = msg.get(0).intValue();
  }
  
}
