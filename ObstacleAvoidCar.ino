const int RMF = 3;
const int RMB = 4;
const int LMF = 5;
const int LMB = 6;

const int trigPin = 9;
const int echoPin = 8;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (RMF, OUTPUT);
  pinMode (RMB, OUTPUT);
  pinMode (LMF, OUTPUT);
  pinMode (LMB, OUTPUT);
}
long duration, distance;

void loop()
{     
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if(distance<20)                            // When distance of Obstacle is less than 20 cm then turn LEFT
    {
      digitalWrite(RMF, HIGH);               // For the bot to make a RIGHT turn instead of LEFT turn change (HIGH to LOW) and (LOW to HIGH)
      digitalWrite(RMB, LOW); 
      digitalWrite(LMF, LOW); 
      digitalWrite(LMB, HIGH);
      delay(1000);
    }
    
  else                                      // When there is no obstacle under 20cm then the bot moves forward.
    {
      digitalWrite(RMF, HIGH); 
      digitalWrite(RMB, LOW); 
      digitalWrite(LMF, HIGH); 
      digitalWrite(LMB, LOW);
    }  
 delay(100);
}
