byte trig1 = 2;     //trig1 connected to pin number 2 on arduino
byte trig2 = 3;     //trig2 connected to pin number 3 on arduino
byte echo1 = 4;     //echo1 connected to pin number 4 on arduino
byte echo2 = 5;     //echo2 connected to pin number 5 on arduino
byte gled1 = 6;     //green led 1 connected to pin number 6 on arduino
byte gled2 = 13;    //green led 2 connected to pin number 13 on arduino
byte rled1 = 8;     //red led 1 connected to pin number 8 on arduino
byte rled2 = 10;    //red led 2 connected to pin number 10 on arduino
int i=0;
int s = 100;
float timeOut=2*((s)+10)/100/340*1000000; 
int setup() {
  // put your setup code here, to run once:
  pinMode(trig1,OUTPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(echo2,INPUT);
  pinMode(gled1,OUTPUT);
  pinMode(gled2,OUTPUT);
  pinMode(rled1,OUTPUT);
  pinMode(rled2,OUTPUT);
  digitalWrite(rled1,LOW);
  digitalWrite(gled1,LOW);
  digitalWrite(rled2,LOW);
  digitalWrite(gled2,LOW);
  return 1;

}

void loop() {
  int d1 = getDistance(trig1,echo1);
  int d2 = getDistance(trig2,echo2);
  if(d1>=s && d2<=s)
  {
    digitalWrite(rled1,HIGH);
    digitalWrite(gled1,LOW);
    digitalWrite(rled2,LOW);
    digitalWrite(gled2,HIGH);
    delay(5000);
    i=0;
  }
  else if(d1<=s && d2>=s)
  {
    digitalWrite(rled1,LOW);
    digitalWrite(gled1,HIGH);
    digitalWrite(rled2,HIGH);
    digitalWrite(gled2,LOW);
    delay(5000);
    i=0;
  }
  else if(d1<=s && d2<=s)
  {
    if(i%2==0)
    {
      digitalWrite(rled1,HIGH);
      digitalWrite(gled1,LOW);
      digitalWrite(rled2,LOW);
      digitalWrite(gled2,HIGH);
      delay(5000);
    }
    else
    {
      digitalWrite(rled1,LOW);
      digitalWrite(gled1,HIGH);
      digitalWrite(rled2,HIGH);
      digitalWrite(gled2,LOW);
      delay(5000);
    }
    i++;
  }
  digitalWrite(rled1,LOW);
  digitalWrite(gled1,LOW);
  digitalWrite(rled2,LOW);
  digitalWrite(gled2,LOW);
}
int getDistance(byte trig,byte echo)
{
  int distances;
  unsigned long pulseTime; 
  digitalWrite(trig, HIGH);                         //Generate a 10 microsecond pulse
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pulseTime = pulseIn(echo, HIGH, timeOut);
  distances = (float)pulseTime * 340 / 2 / 10000;
  return distances;
}
