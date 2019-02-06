int ENA = 5;
int IN1 = 7;
int IN2 = 8;

void setup(){
  pinMode(ENA, OUTPUT); 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop(){
  //Preparamos la salida para que el motor gire en un sentido
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  
  // Aplicamos PWM al pin ENA, haciendo girar el motor, cada 2 seg aumenta la velocidad
  analogWrite(ENA,55);
  delay(2000);
  analogWrite(ENA,105);
  delay(2000);
  analogWrite(ENA,255);
  delay(2000);
  
  // Apagamos el motor y esperamos 5 seg
  analogWrite(ENA,0);
  delay(5000);
}
