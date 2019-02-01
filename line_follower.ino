byte sir1=A0;
byte sir2=A1;
int ma1=8,ma2=9,pwma=10;
int mb1=7,mb2=6,pwmb=5;
void setup(){
  Serial.begin(9600);
//sensores
  pinMode(2,INPUT);
  pinMode(3,INPUT);
//motores
  pinMode(ma1,OUTPUT);
  pinMode(ma2,OUTPUT);
  pinMode(pwma,OUTPUT);
  pinMode(mb1,OUTPUT);
  pinMode(mb2,OUTPUT);
  pinMode(pwmb,OUTPUT);
}
void loop(){
  int senaI=analogRead(sir1);
  delay(1);
  int sendI=digitalRead(2);
  delay(1);
  int senaD=analogRead(sir2);
  delay(1);
  int sendD=digitalRead(3);
  delay(1);
 
    Serial.print("analog 1 ");
    Serial.println(senaI);
    Serial.print("digital 1 ");
    Serial.println(sendI);
    Serial.print("analog 2 ");
    Serial.println(senaD);
    Serial.print("digital 2 ");
    Serial.println(sendD);
    Serial.print("Analog 3");
    Serial.println(sendE); 
    
  if(sendI==1&&sendD==1){
    derecho(150);
  }
  else if(sendI==1&&sendD==0){
    left(150);
  }
  else if(sendI==0&&sendD==1){
    right(150);
  }
  else if(sendI==0&&sendD==0){
    finish(150);
  }
}
void derecho(int vel){
  digitalWrite(ma1,HIGH);
  digitalWrite(ma2,HIGH);
  analogWrite(pwma,vel);
  digitalWrite(mb1,HIGH);
  digitalWrite(mb2,HIGH);
  analogWrite(pwmb,vel);
}
void left(int vel){
  digitalWrite(ma1,HIGH);
  digitalWrite(ma2,LOW);
  analogWrite(pwma,vel);
  digitalWrite(mb1,LOW);
  digitalWrite(mb2,HIGH);
  analogWrite(pwmb,vel);
}
void right(int vel){
  digitalWrite(ma1,LOW);
  digitalWrite(ma2,HIGH);
  analogWrite(pwma,vel);
  digitalWrite(mb1,HIGH);
  digitalWrite(mb2,LOW);
  analogWrite(pwmb,vel);
}
void finish(int vel){
  digitalWrite(ma1,LOW);
  digitalWrite(ma2,LOW);
  analogWrite(pwma,vel);
  digitalWrite(mb1,LOW);
  digitalWrite(mb2,LOW);
  analogWrite(pwmb,vel);
}
