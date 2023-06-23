void setup() {
  #define digitosUnidade 12
  #define digitosDezena 13
  #define Entrada1 6
  #define Entrada2 9
  #define Entrada3 8
  #define Entrada4 7
  
  Serial.begin(9600);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  
  for(byte i = Entrada1; i <= digitosDezena; i++)
    pinMode(i, OUTPUT);
  
  digitalWrite(digitosUnidade,true);
  digitalWrite(digitosDezena,true);
}

void display_7seg(byte valor) {
  switch(valor){
      case 0:
        digitalWrite(Entrada1, LOW);
        digitalWrite(Entrada2, LOW);
        digitalWrite(Entrada3, LOW);
        digitalWrite(Entrada4, LOW);
        delay(10);
        break;
      
      case 1:
        digitalWrite(Entrada1, HIGH);
        digitalWrite(Entrada2, LOW);
        digitalWrite(Entrada3, LOW);
        digitalWrite(Entrada4, LOW);
        delay(10);
        break;
      
      case 2:
        digitalWrite(Entrada1, LOW);
        digitalWrite(Entrada2, HIGH);
        digitalWrite(Entrada3, LOW);
        digitalWrite(Entrada4, LOW);
        delay(10);
        break;
      
      case 3:
        digitalWrite(Entrada1, HIGH);
        digitalWrite(Entrada2, HIGH);
        digitalWrite(Entrada3, LOW);
        digitalWrite(Entrada4, LOW);
        delay(10);
        break;
      
      case 4:
        digitalWrite(Entrada1, LOW);
        digitalWrite(Entrada2, LOW);
        digitalWrite(Entrada3, HIGH);
        digitalWrite(Entrada4, LOW);
        delay(10);
        break;
      
      case 5:
        digitalWrite(Entrada1, HIGH);
        digitalWrite(Entrada2, LOW); 
        digitalWrite(Entrada3, HIGH);
        digitalWrite(Entrada4, LOW);
        delay(10);
        break;
      
      case 6:
        digitalWrite(Entrada1, LOW);
        digitalWrite(Entrada2, HIGH);
        digitalWrite(Entrada3, HIGH);
        digitalWrite(Entrada4, LOW);
        delay(10);
        break;
      
      case 7:
        digitalWrite(Entrada1, HIGH);
        digitalWrite(Entrada2, HIGH);
        digitalWrite(Entrada3, HIGH);
        digitalWrite(Entrada4, LOW);
        delay(10);
        break;
      
      case 8:
        digitalWrite(Entrada1, LOW);
        digitalWrite(Entrada2, LOW);
        digitalWrite(Entrada3, LOW);
        digitalWrite(Entrada4, HIGH);
        delay(10);
        break;
      
      case 9:
        digitalWrite(Entrada1, HIGH);
        digitalWrite(Entrada2, LOW);
        digitalWrite(Entrada3, LOW); 
        digitalWrite(Entrada4, HIGH);
        delay(10);
        break;
      
    }       
}

byte unidade = 0, dezena = 0;

void loop()
{
  display_7seg(unidade);
  digitalWrite(digitosUnidade,false);
  delay(2);
  digitalWrite(digitosUnidade,true);
  
  display_7seg(dezena);
  digitalWrite(digitosDezena,false);
  delay(2);  
  digitalWrite(digitosDezena,true);
  
  if(digitalRead(11) == 1){
    unidade++;
    
    if(unidade > 9){
      unidade = 0;
      dezena++;
      
      if(dezena > 9)
        dezena = 0;
    }
    delay(250);
  }
  
  if(digitalRead(10) == 1){
    if(dezena == 0 && unidade == 0){
      dezena = 9;
      unidade = 9;      
    }else if(unidade == 0){
        dezena--;
      unidade = 9;
    }else {
      unidade--;
    }
    delay(250);
  }  
}