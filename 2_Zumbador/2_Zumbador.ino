unsigned int duracion = 100;
int zumbPin = 4;

void setup() {
  // put your setup code here, to run once:
  tone(zumbPin, 784, duracion);
  delay(duracion*1.2);
  noTone(zumbPin);
}

void loop() {
}
