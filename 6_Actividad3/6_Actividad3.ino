// HC-SR04
const int triggerPin = 2;
const int echoPin = 3;
long t;
long d;
// Buzzer
int zumbPin = 4;
unsigned int duracion = 100;
// L298
int ENA = 5;
int IN1 = 7;
int IN2 = 8;
int ENB = 6;
int IN3 = 9;
int IN4 = 10;

void setup(){
  // Comunicación serial
  Serial.begin(9600);
  // HC-SR04
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(triggerPin, LOW);
  // L298
  pinMode(ENA, OUTPUT); 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT); 
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  adelante();
}

void loop(){
  // Enviamos un pulso de 10us
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Interpretamos la lectura
  t = pulseIn(echoPin, HIGH);
  d = t/59; // cm

  // Lógica principal
  if(d > 10){
    // Avanzar
    avanzar();
    delay(120);
  }
  else{
    // Detener
    detener();
    // Que se active el zumbador
    tone(zumbPin, 784, duracion);
    delay(duracion*1.2);
    noTone(zumbPin);
  }

  // Communcación serial
  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.print("cm");
  Serial.println();
}

//-------------------------------------------------------
// Funciones adicionales
//-------------------------------------------------------
void adelante(){  
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void atras(){  
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void derecha(){  
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
}

void izquierda(){  
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void avanzar(){
  analogWrite(ENA,128);
  analogWrite(ENB,128);
}

void detener(){
  analogWrite(ENA,0);
  analogWrite(ENB,0);
}

