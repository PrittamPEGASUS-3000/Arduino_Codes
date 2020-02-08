//Duto progrm bhogoban jne konta kaj krbe ;)



/*  Ultrasonic VCC to Arduino 5v.
    Ultrasonic GND to Arduino GND.
    Ultrasonic TRIG to Arduino D12.
    Ultrasonic ECHO to Arduino D11.

    Buzzer RED to Arduino D8.
    Buzzer BLACK to Arduino GND.
    Vibrator motor pin 1 to Arduino D7.
    Vibrator motor pin 2 to Arduino GND

    9-volt battery RED to Toggle switch pin 1.
    9-volt battery BLACK to DC male power jack(-).
    Toggle switch pin 2 to DC male power jack (+)*/
  //Program 1
/*#define trigPin 13
#define echoPin 12
#define motor 7
#define buzzer 6
void setup()
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(motor, OUTPUT);
pinMode(buzzer,OUTPUT);
}
void loop()
{
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 70)// This is where checking the distanceyou can change the value
{
digitalWrite(motor,HIGH); // When the the distance below 100cm
digitalWrite(buzzer,HIGH);
} else
{
digitalWrite(motor,LOW);// when greater than 100cm
digitalWrite(buzzer,LOW);
} delay(500);
}*/



//Program 2 
const int trigger = 5; //Trigger pin of 1st Sesnor
const int echo = 6; //Echo pin of 1st Sesnor
const int Buzz = 10; //Echo pin of 1st Sesnor
const int Remote = A0; //Echo pin of 1st Sesnor
const int Light = A1; //Echo pin of 1st Sesnor
long time_taken;
int dist;
int Signal;
int Intens;
int similar_count;
void setup() {
Serial.begin(9600); 
pinMode(Buzz,OUTPUT);
digitalWrite(Buzz,LOW);
pinMode(trigger, OUTPUT); 
pinMode(echo, INPUT); 
}
//Function to calculate distance
void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>300)
dist=300;
}
void loop() { //infinite loop
calculate_distance(trigger,echo);
Signal = analogRead(Remote);
Intens = analogRead(Light);
/*/Check if Remote is pressed
int temp = analogRead(Remote);
similar_count=1;
while (Signal==temp)
{
 Signal = analogRead(Remote);
 similar_count++;
}
//If remote pressed
if (similar_count<100)
{
  Serial.print(similar_count); Serial.println("Remote Pressed");
  digitalWrite(Buzz,HIGH);delay(3000);digitalWrite(Buzz,LOW);
}*/
//If very dark
if (Intens<200)
{
  Serial.print(Intens); Serial.println("Low Light");
  digitalWrite(Buzz,HIGH);delay(200);digitalWrite(Buzz,LOW);delay(200);digitalWrite(Buzz,HIGH);delay(200);
  digitalWrite(Buzz,LOW);delay(200);
  delay(500);
}
/*/If very bright
if (Intens>800)
{
  Serial.print(Intens); Serial.println("Low Light");
  digitalWrite(Buzz,HIGH);delay(500);digitalWrite(Buzz,LOW);delay(500);digitalWrite(Buzz,HIGH);delay(500);
  digitalWrite(Buzz,LOW);delay(500);
}*/
if (dist<50)
{
  Serial.print(dist); Serial.println("Object Alert");
  digitalWrite(Buzz,HIGH);
  for (int i=dist; i>0; i--)
    delay(10);
  digitalWrite(Buzz,LOW);
  for (int i=dist; i>0; i--)
    delay(10);
}
Serial.print("dist=");
Serial.println(dist);
Serial.print("Similar_count=");
Serial.println(similar_count);
Serial.print("Intens=");
Serial.println(Intens);
}
