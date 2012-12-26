void setup() {
    pinMode(13, OUTPUT);
}

void loop() {
    int time;
    time = random(30, 1000);    
    digitalWrite(13, !digitalRead(13));
    delay(time);
    digitalWrite(13, !digitalRead(13));
    delay(time);    
}
