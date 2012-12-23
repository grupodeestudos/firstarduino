int ledPins[] = {13,12,11,10,9,8,7};
int pinCount = 7;
int countLoop = 0;
int countLoopInt = 0;


void setup() {
   for (int count = 0; count < pinCount; count++)  {
     pinMode(ledPins[count], OUTPUT);    
     digitalWrite(ledPins[count], HIGH);
   }  
   Serial.begin(9600);
}

int ret=-1;

void loop() {
  ret = numberFromSerial();
  if (ret > 0)
  {
    digitalWrite(ret, !digitalRead(ret));
    Serial.println(ret);
  }
}

int numberFromSerial(void)
{
  char numberString[8];
  unsigned char index=0;
  while(Serial.available() > 0)
  {
    numberString[index++]=Serial.read();
    delay(10);
    if(index > 2)
    {
      break;
    }
  }
  numberString[index]=0;
  return atoi(numberString);
}

