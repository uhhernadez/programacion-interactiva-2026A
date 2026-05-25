import oscP5.*;
import netP5.*;
import controlP5.*;
ControlP5 cp5;
OscP5 osc;
NetAddress address;
PImage img;
Chart graph;

void setup () {
  noStroke();
  size (500, 500);
  osc = new OscP5(this, 10003);
  address = new NetAddress("127.0.0.1", 10000);
  cp5 = new ControlP5(this);
  
  cp5.addSlider("pitch")
     .setPosition(50,50)
     .setRange(0,2)
     .setSize(20, 100);
  cp5.addSlider("volumen")
     .setPosition(100,50)
     .setRange(0,1)
     .setSize(20, 100);
  graph = cp5.addChart("graph")
             .setPosition(100, 350)
             .setRange(-1, 1)
             .setSize(300, 100)
             .setView(Chart.BAR)
             .setStrokeWeight(2);
             
  graph.addDataSet("values");
  graph.setData("values", new float[64]);
  img = loadImage("logo.png");     
}

void draw (){
  background(10);
  image(img, 100,100);
}

void oscEvent(OscMessage msg) {
  println("Nuevo mensaje");
  println("Tipo: " + msg.typetag());
  for (int k = 0; k < 64; k++) {
    float tmp = msg.get(k).floatValue();
    graph.getData("values", k).setValue(tmp);
  }
}

void pitch (float value) {
  OscMessage msg = new OscMessage("/pitch");
  msg.add(value);
  osc.send(msg, address);
}

void volumen (float value) {
  OscMessage msg = new OscMessage("/volumen");
  msg.add(value);
  osc.send(msg, address);
}
