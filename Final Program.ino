//  initialize digital pin motor as an output
int pin5=5;
int pin6=6;
int pin7=7;
int pin8=8;
int t1=A0;
int t2=A1;
int irPin=4;
int pathLoop=2;
int numGantry=3;
static int flag=0;
static int gantryCounter=0;
static long CurrentTimeG = 0;
static long ElapsedTimeG =0;
unsigned long d=0;
static long StartTime=0;
static long CurrentTime = 0;
unsigned long ElapsedTime = 0;
static long StartTimeG=millis();
const int trigPin = 13;
const int echoPin = 12;
long duration;
long distanceCm;
//long distanceInch;
void setup() {
pinMode(pin5,OUTPUT);
pinMode(pin6,OUTPUT);
pinMode(pin7,OUTPUT);
pinMode(pin8,OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(t1,INPUT);
pinMode(t2,INPUT);
pinMode(irPin,INPUT);
//pathLoop = Serial.read();
Serial.begin(9600);
Serial.print("+++");  // Enter xbee AT command mode, NB no carriage return here
delay(1500);          // Guard time
Serial.println("ATID 3333, CH C, CN");
}
// the loop function runs over and over again forever
void loop()
{
   
    if (flag==1)
   {
     normalLineFollow();
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
   
    duration = pulseIn(echoPin, HIGH);
    distanceCm = (duration*0.034)/2;
    Serial.print("The disctance in CM is: ");
Serial.println(distanceCm);
if(distanceCm<15 && distanceCm>0 )     //here we set the object range 15cm.
{
 
stopBuggy();
delay(1000);
}
    
      }
      if (flag==2)
   {
     gantryMode();
     pinMode(trigPin, OUTPUT);
     digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    distanceCm = (duration*0.034)/2;
    Serial.print("The distance in CM is: ");
    Serial.println(distanceCm);
//distanceInch = duration*0.0133/2;
if(distanceCm<9)     //here we set the object range 15cm.
{
 
  stopBuggy();
  delay(1000);
 
 
}
  
      }
    
    if (flag==3)
   {
     gantryParking();
     CurrentTime=millis();
     ElapsedTime = CurrentTime-StartTime;
     if(ElapsedTime>6500)
     {
      stopBuggy();
      flag=0;
     }
    }
int r1=digitalRead(t1);
int r2=digitalRead(t2);
 if (Serial.available() > 0) //here we check serial data on serial port and than read it.
  { 
   
//    char s='G';
 
      char s = Serial.read();
        switch (s) {
                case 'F':
                {
                  normalLineFollow();
                  flag=1;
                  break;
                 
        }
        case 'G':
                {
                  gantryMode();
                  flag=2;
                  break;
                 
        }
       
       
                  
                  case 'S':
                  {
                  flag=0;
                  stopBuggy();
                  break;
                  }
                 
   }
}
 
}
void normalLineFollow()
{
int r1=digitalRead(t1);
int r2=digitalRead(t2);
if(r1==HIGH&&r2==HIGH)
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
 
}
 if(r1==LOW&&r2==LOW)
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
 
} if(r1==HIGH&&r2==LOW)
{
  digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
 }
 if(r1==LOW&&r2==HIGH)
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
 
}
/*digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
//distanceInch = duration*0.0133/2;
if(distanceCm<15)     //here we set the object range 15cm.
{
 
  stopBuggy();
  delay(1000);
  flag=1;
}
else
{
normalLineFollow();
flag=1;
 
  } */
}
void gantryMode()
{
int r1=digitalRead(t1);
int r2=digitalRead(t2);
if(r1==HIGH&&r2==HIGH)
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
 
}
 if(r1==LOW&&r2==LOW)
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
 
} if(r1==HIGH&&r2==LOW)
{
  digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
 }
 if(r1==LOW&&r2==HIGH)
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
 
}
if (digitalRead(irPin)==HIGH)
{
gantryCounter=gantryCounter+1;
d = pulseIn(irPin,HIGH);
 if(d > 500 and d < 1500)
            {
               // Serial.println(d);
                Serial.println("Gantry: 1");
               
            }
        else if (d> 1500 and d < 2500)
            {
              //  Serial.println(d);
                Serial.println("Gantry: 2");
               
            }
        else if (d > 2500 and d < 3500)
            {
              //  Serial.println(d);
                Serial.println("Gantry: 3");
               
            }
         else {
            // Serial.println(d);
             Serial.println("Gantry: Unknown");
            
         }
stopBuggy();
delay(2000);
if (gantryCounter==(numGantry*pathLoop))
{
 StartTime = millis();
 gantryParking();
 flag=3;
}
else
{
flag=2;
}
}
/*digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
if(distanceCm<15)     //here we set the object range 15cm.
{
 
  stopBuggy();
  delay(1000);
  flag=2;
}
else
{
gantryMode();
flag=2;
 
  }*/
}
void gantryParking()
{
   CurrentTimeG=millis();
     ElapsedTimeG = CurrentTimeG-StartTimeG;
    
     if(ElapsedTimeG<2500)
     {
      flag=3;
      leftBlind();
     }
     if(ElapsedTimeG>2500 && ElapsedTimeG<6500)
     {
      flag=3;
      normalLineFollow();
     }
     if(ElapsedTimeG>6500)
     {
      stopBuggy();
      Serial.print("Buggy:1 Parked");
      //Serial.println(ElapsedTimeG);
      delay(200);
      flag=-1;
     }
flag=3;
/*digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
if(distanceCm<15)     //here we set the object range 15cm.
{
 
  stopBuggy();
  delay(1000);
  flag=0;
}*/
}
void stopBuggy()
  {
  digitalWrite(pin5,LOW);
  digitalWrite(pin6,LOW);
  digitalWrite(pin7,LOW);
  digitalWrite(pin8,LOW);
  }
  void leftBlind()
{
  
int r2=digitalRead(t2);
 if(r2==LOW)
{
  digitalWrite(pin5,LOW);
  digitalWrite(pin6,LOW);
  digitalWrite(pin7,HIGH);
  digitalWrite(pin8,LOW);
 
}
 if(r2==HIGH)
{
  digitalWrite(pin5,HIGH);
  digitalWrite(pin6,LOW);
  digitalWrite(pin7,HIGH);
  digitalWrite(pin8,LOW);
 
}}
