const int triggerPin = 2;   // Pin digital 2 para el Trigger del sensor
const int echoPin = 3;   // Pin digital 3 para el Echo del sensor

void setup() {
  Serial.begin(9600); // Iniciailzamos la comunicación
  pinMode(triggerPin, OUTPUT); // Pin como salida
  pinMode(echoPin, INPUT);  // Pin como entrada
  digitalWrite(triggerPin, LOW); // Inicializamos el pin con 0
}

void loop() {
  long t; // Tiempo que demora en llegar el eco
  long d; // Distancia en centimetros

  // Enviamos un pulso de 10us
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  t = pulseIn(echoPin, HIGH); // Obtenemos el tiempo de respuesta
  d = t/59; // Convertir a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.print("cm");
  Serial.println();
  delay(100);
}
