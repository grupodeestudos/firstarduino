#define LED 13
#define BUZ 7
#define LUZ 0
#define OFF 0
#define DEFAULT_DELAY 100

int get_luminosidade()
{
    int luz;
    luz = analogRead(LUZ);
    if (luz <= 500)
        //escuro
        return 0;
    else
        return 1;
}

void beep(int times) {
    for (int i = 0; i < times; i++){
        digitalWrite(BUZ, HIGH);
        delay(DEFAULT_DELAY);
        digitalWrite(BUZ, LOW);
        delay(DEFAULT_DELAY);
    }
}

void setup(){
    pinMode(LED, OUTPUT);
    pinMode(BUZ, OUTPUT);
    int init;
    init = get_luminosidade();
    if (init == 0){
        digitalWrite(LED, HIGH);
    }
}

void loop(){
    int luminosidade_atual, estado;
    estado = get_luminosidade();
    delay(DEFAULT_DELAY);
    luminosidade_atual = get_luminosidade();
    if (luminosidade_atual != estado){
      if (luminosidade_atual == OFF){
        //APAGARAM A LUZ
        digitalWrite(LED, HIGH);
        beep(2);
      }
      else {
        //ACENDERAM A LUZ
        digitalWrite(LED, LOW);
        beep(1);
      }
    }
}

