int pushButton = 2;
const int outLed = 11;
const int outZumbador = 10;
void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}
int separador;
int largo;
int valor;
void loop() {
  if(Serial.available()) {
    String mensaje =  Serial.readStringUntil('\n');
    mensaje.trim();
    // { 'i' , 'n',  't', '1', ' ', '1', '2' ,'3', '\n'}
    //    0  ,  1 ,   2 ,  3 ,  4 ,  5 ,  6  , 7 ,  8 
    if (mensaje.startsWith("out1")) {
      separador = mensaje.indexOf(' ');

      if (separador < 0 ) { 
        // No existe el espacio
        return ;
      }

      largo = mensaje.length();
      String numero = mensaje.substring(separador + 1 ,largo);
      Serial.println(numero);
      valor = numero.toInt();
      analogWrite(outLed, valor);
    } else if (mensaje.startsWith("out2")) {
      separador = mensaje.indexOf(' ');

      if (separador < 0 ) { 
        // No existe el espacio
        return ;
      }

      largo = mensaje.length();
      String numero = mensaje.substring(separador + 1 ,largo);
      Serial.println(numero);
      valor = numero.toInt();
      analogWrite(outZumbador, valor);
    } else {
      // No soportado
    }


  }
}


