void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(12, OUTPUT);
  attachInterrupt(2,turnOnLight,RISING);
    attachInterrupt(2,turnOffLight,FALLING);
}
bool ledState=false;

void loop() {
  
  // put your main code here, to run repeatedly:
 Serial.print("DEMAT BREIZH\n");
}
void turnOnLight(){
  digitalWrite(12,HIGH);
}
void turnOffLight(){
  digitalWrite(12,LOW);
}
