#define t_exp 5000 //Tiempo de muestreo
#define Ts 10 //intervalo de tiempo
#define pin_u 3 //pin de salida 

//Entrada y salida para almacenar
unsigned int muestras = t_exp/Ts+1;
unsigned int u = 0;
unsigned int y = 0;

void setup() {
  Serial.begin(115200); 
  pinMode(pin_u,OUTPUT);
  Serial.println("Inicio");
  digitalWrite(pin_u,LOW);
}

void loop() {
  delay(5000); //tiempo de espera para descargar el capacitor
  digitalWrite(pin_u,HIGH);//Entrada al sistema RC
  while(muestras){ //Ciclo para capturar la salida y entrada
    u = analogRead(A0);//lectura de la entrada al sistema desde el micro
    y = analogRead(A1);//lectura der la salida del sistema
    Serial.print(u);//muestra de los datos
    Serial.print(',');
    Serial.println(y);
    muestras = --muestras;
    delay(Ts); //tiempo de espera entre cada muestreo  
    }
  digitalWrite(pin_u,LOW);//deja de alimentar el circuito
  Serial.println("Final");//indicador 
  while(1);
}

