//VISIT : www.robotechmaker.com

  const int pingTrigPin = 5; //Trigger connected to PIN 5   
  const int pingEchoPin = 6; //Echo connected to PIN 6   
  int buz=3; //Buzzer to PIN 3   
  void setup() {   
  Serial.begin(9600);   
  pinMode(buz, OUTPUT);   
  }   
  void loop()   
  {   
   int sensorValue = analogRead(A0); //read the A0 pin value
  float voltage = sensorValue * (5.00 / 1023.00) * 2; //convert the value to a true voltage.
  if (voltage < 4.55) //set the voltage considered low battery here
  {
    while (voltage < 4.55) {
      digitalWrite(buz, HIGH);   
    delay(200);   
    digitalWrite(buz, LOW);   
    delay(200);  
    digitalWrite(buz, HIGH);   
    delay(200);   
    digitalWrite(buz, LOW);   
    delay(200);  
    digitalWrite(buz, HIGH);   
    delay(200);   
    digitalWrite(buz, LOW);   
    delay(1000);  
    }
  }

   if (voltage > 4.55)
   {
     long duration, cm;   
    pinMode(pingTrigPin, OUTPUT);   
    digitalWrite(pingTrigPin, LOW);   
    delayMicroseconds(2);   
    digitalWrite(pingTrigPin, HIGH);   
    delayMicroseconds(5);   
    digitalWrite(pingTrigPin, LOW);   
    pinMode(pingEchoPin, INPUT);   
    duration = pulseIn(pingEchoPin, HIGH);   
    cm = microsecondsToCentimeters(duration);   
    if(cm<=120 && cm>0)   
    {   
    int d= map(cm, 1, 100, 20, 2000);   
    digitalWrite(buz, HIGH);   
    delay(cm * 2);   
    digitalWrite(buz, LOW);   
    delay(cm * 5);  
    }   
    Serial.print(cm);    
    Serial.print("cm");   
    Serial.println();   
    delay(100);   
   }
    
    }   
    long microsecondsToCentimeters(long microseconds)   
    {   
    return microseconds / 29 / 2;   
    }   
