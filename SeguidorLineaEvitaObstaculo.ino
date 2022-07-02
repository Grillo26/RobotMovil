
int aM1 = 6;
int rM1 = 7;
int aM2 = 4;
int rM2 = 5;

int ledIzq = 9;
int ledDer = 8;
int ledVerde = 10;
int ledRojo = 11;

int trig = 2;
int echo = 3;
int tiempo;
int distancia;



void setup()
{
  Serial.begin(9600);
  pinMode(aM1, OUTPUT);
  pinMode(rM1, OUTPUT);
  pinMode(aM2, OUTPUT);
  pinMode(rM2, OUTPUT);
  
  pinMode(ledIzq, OUTPUT);
  pinMode(ledDer, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
}

void loop()
{
  //i = Contador de los lados
  for(int i=1; i<=4; i++){
    Serial.print("Lado N ");
    Serial.println(i);
    
    girarCuadrado(); 
    
  }
  Stop();
  Serial.println("Stop...");
  delay(5000);
    
}
//<------ Gira en Cuadrado 1 metro---->
void girarCuadrado(){
    Adelante();
    buscarObjeto();//<------
    delay(5000);
    Izquierda();
    delay(3000);
}
//<-----Busca Obstaculo en sensor---->
void buscarObjeto(){
  digitalWrite(trig,HIGH);
  delay(1);
  digitalWrite(trig,LOW);
  tiempo = pulseIn(echo,HIGH);
  distancia = tiempo/58.2; //Tiempo en segundos
  Serial.println(distancia);
  delay(500);
  
  if(distancia <50){
        Serial.println("Objeto Detectado");
      esquivar();
    }
}
//<-----Esquiva Obstaculo---->
void esquivar(){
    Serial.println("Esquivando...");
    Stop();
    delay(3000);
    Derecha();
    delay(3000);
    Adelante();
    delay(5000);
    Izquierda();
    delay(3000);
    Adelante();
    delay(5000);
    Izquierda();
    delay(3000);
    Adelante();
    delay(5000);
    Derecha();
    delay(3000);
}


//<-------- Motores -------->
void Adelante(){
digitalWrite(ledVerde, HIGH);
digitalWrite(ledRojo, LOW);
digitalWrite(ledDer, LOW);
digitalWrite(ledIzq, LOW);
  
digitalWrite(rM1, LOW);
digitalWrite(rM2, LOW);
digitalWrite(aM1, HIGH);
digitalWrite(aM2, HIGH);
}

void Atras(){
digitalWrite(ledVerde, LOW);
digitalWrite(ledRojo, LOW);
digitalWrite(ledDer, HIGH);
digitalWrite(ledIzq, HIGH);

digitalWrite(aM1, LOW);
digitalWrite(aM2, LOW);
digitalWrite(rM1, HIGH);
digitalWrite(rM2, HIGH);
}

void Izquierda(){
digitalWrite(ledVerde, LOW);
digitalWrite(ledRojo, LOW);
digitalWrite(ledDer, LOW);
digitalWrite(ledIzq, HIGH);
  
digitalWrite(aM1, LOW);
digitalWrite(aM2, HIGH);
  


}

void Derecha(){
digitalWrite(ledVerde, LOW);
digitalWrite(ledRojo, LOW);
digitalWrite(ledIzq, LOW);
digitalWrite(ledDer, HIGH);
  
digitalWrite(aM2, LOW);
digitalWrite(aM1, HIGH);
}

void Stop(){
digitalWrite(ledVerde, LOW);
digitalWrite(ledRojo, HIGH);
digitalWrite(ledIzq, HIGH);
digitalWrite(ledDer, HIGH);
  
digitalWrite(aM1, LOW);
digitalWrite(aM2, LOW);
digitalWrite(rM1, LOW);
digitalWrite(rM2, LOW);


}
