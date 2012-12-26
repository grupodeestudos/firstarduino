void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(5000);
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(13, HIGH);
  delay(800);
  digitalWrite(13, LOW);
  delay(100);
}


