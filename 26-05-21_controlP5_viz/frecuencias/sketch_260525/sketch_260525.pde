import oscP5.*;
import netP5.*;
import controlP5.*;
ControlP5 cp5;
OscP5 osc;
NetAddress address;

Chart graph;

void setup () {
  noStroke();
  size (500, 500);
  osc = new OscP5(this, 10003);
  address = new NetAddress("127.0.0.1", 10000);
  cp5 = new ControlP5(this);
  
  graph = cp5.addChart("graph")
             .setPosition(100, 50)
             .setRange(0, 1)
             .setSize(300, 400)
             .setView(Chart.BAR)
             .setStrokeWeight(2);
             
  graph.addDataSet("values");
  graph.setData("values", new float[32]);     
}

void draw (){
  background(10);
}

void oscEvent(OscMessage msg) {
  println("Nuevo mensaje");
  println("Tipo: " + msg.typetag());
  for (int k = 0; k < 32; k++) {
    float tmp = msg.get(k).floatValue();
    graph.getData("values", k).setValue(tmp);
  }
}
