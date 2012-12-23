int ledPins[] = {13,12,11,10,9,8,7};
int pinCount = 7;
int countLoop = 0;
int countLoopInt = 0;


void setup() {
   for (int count = 0; count < pinCount; count++)  {
     pinMode(ledPins[count], OUTPUT);    
   }  
   Serial.begin(9600);
}

void loop() {
    Serial.println(countLoop);
  
    for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
      digitalWrite(ledPins[thisPin], HIGH);   
      delay(50);                  
      digitalWrite(ledPins[thisPin], LOW);    
    }
    
    countLoop += 1;
    if(countLoop %50 == 0){
      while(countLoop %100 != 0){
        for (int thisPin = pinCount; thisPin >= 0; thisPin--) { 
          digitalWrite(ledPins[thisPin], HIGH);   
          delay(20);                  
          digitalWrite(ledPins[thisPin], LOW);    
        }
        countLoop +=1 ;
      }
    }
    
    if (countLoop %70 == 0){
      Serial.println("Pisca, pausa...");
      for(countLoopInt = 0; countLoopInt < 8 ; countLoopInt++){
        Serial.println("Pisca, pausa...Uhuuu");
        Serial.println(countLoopInt);
        for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
          digitalWrite(ledPins[thisPin], LOW);   
        }
        
        delay(800);
  
        for (int thisPin = 0; thisPin < pinCount/2; thisPin++) { 
          digitalWrite(ledPins[thisPin], HIGH);   
        }
        
        delay(800);
        
        for (int thisPin = pinCount/2; thisPin < pinCount; thisPin++) { 
          digitalWrite(ledPins[thisPin], HIGH);   
        }    
        
        delay(800);    
        
      }
      countLoop = 0;
    }
    
    if (countLoop %110 == 0){
      for(countLoopInt = 0; countLoopInt < 3 ; countLoopInt++){
        for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
          digitalWrite(ledPins[thisPin], LOW);   
        }
        
        delay(200);
  
        for (int thisPin = 0; thisPin < pinCount/2; thisPin++) { 
          if(thisPin%countLoopInt==0){ 
            digitalWrite(ledPins[thisPin], HIGH);   
          }else{
            digitalWrite(ledPins[thisPin], LOW);   
          }
          delay(300);          
        }

        delay(800);    
        
        for (int i = 0; i< 2;i++){
          for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
            digitalWrite(ledPins[thisPin], HIGH);   
          }    
          delay(800);    
          for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
            digitalWrite(ledPins[thisPin], LOW);   
          }    
          delay(800);    
        }
        
      }
      countLoop = 0;
    }


    
}
