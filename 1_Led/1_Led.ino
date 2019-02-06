int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  delay(2000);
  d_morse();
}

void loop() {
}

// Funciones adicionales
void punto(){
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(300);  
}

void raya(){
  digitalWrite(ledPin, HIGH);
  delay(800);
  digitalWrite(ledPin, LOW);
  delay(300);  
}

void d_morse(){
  raya();
  punto();
  punto();
}

