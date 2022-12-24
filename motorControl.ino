
//OUTPUTS
int backWardMotor = 11;
int forwardMotor = 10;
int motherBoardOnLine = 4;

///INPUTS
int timmerSignal = 7;
int waterLevelSensor = 8;
int highAmpSensor = 2;


///REFERENCES VALUES
int timeOpenning = 5000;
int timeClosing = 5500;
int irrigationTime = 5000;
int closingSpeed = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(forwardMotor,OUTPUT);
  pinMode(backWardMotor,OUTPUT);
  pinMode(motherBoardOnLine,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(highAmpSensor), HighAmpResponse, RISING);


}

void loop() {
  int timmerStatus = digitalRead(timmerSignal);
  int waterLevelStatus = digitalRead(waterLevelSensor);
  int highAmpStatus = digitalRead(highAmpSensor);

  digitalWrite(motherBoardOnLine, HIGH);
  // digitalWrite(motherBoardOnLine, LOW);

  if(timmerStatus == HIGH){
    
    digitalWrite(forwardMotor,HIGH);
    delay(timeOpenning);
    digitalWrite(forwardMotor,LOW);
    delay(irrigationTime);
    digitalWrite(backWardMotor,HIGH);
    
  }

  if(waterLevelStatus == HIGH){
    analogWrite(backWardMotor,closingSpeed);
    delay(timeClosing);
    
  }

}

void HighAmpResponse(){
  digitalWrite(backWardMotor,LOW);

}
