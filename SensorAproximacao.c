const int PINO_TRIGGER = 13;
const int PINO_ECHO = 12;
const int OBSTACULO_DISTANCIA = 300;
const int PERIGO = 75;

void setup() {
  Serial.begin(9600);
  pinMode(PINO_TRIGGER, OUTPUT);
  pinMode(PINO_ECHO, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  int distancia = medir_distancia(PINO_TRIGGER, PINO_ECHO);
  
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  
  if(distancia <= OBSTACULO_DISTANCIA){
    digitalWrite(10, HIGH);
    Serial.print("Obstaculo a frente: ");
    Serial.print(distancia);
    Serial.println("cm");
    if(distancia <= PERIGO){
      	digitalWrite(10, LOW);
    	digitalWrite(11, HIGH);
    }
  }
  else{
    Serial.println("Sem obstaculo");
  }
  delay(100);
}

int medir_distancia(int pino_trigger, int pino_echo){
  long duracao, cm;
  digitalWrite(pino_trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pino_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pino_trigger, LOW);
  duracao = pulseIn(pino_echo, HIGH);
  cm = (duracao / 2) / 29.1;
}

