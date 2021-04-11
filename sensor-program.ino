/* gesture controll laptop 
 arduino code
 team members
 -roopak bedekar
 -shruti jain 
 -afeera
 -mohit rathod
 cse 3rd sem
 sec b
 */




//Global Variables
const int trigger1 = 2; //Trigger pin of 1st Sesnor
const int echo1 = 3; //Echo pin of 1st Sesnor
const int trigger2 = 4; //Trigger pin of 2nd Sesnor
const int echo2 = 5;//Echo pin of 2nd Sesnor

long time_taken;
int dist,distL,distR; 

 

void setup() {
Serial.begin(9600); 
  
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 
}

/###Function to calculate distance###/
void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>50)
dist = 50;
}

void loop() { //infinite loopy
calculate_distance(trigger1,echo1);
distL =dist; //get distance of left sensor

calculate_distance(trigger2,echo2);
distR =dist; //get distance of right sensor


//Pause Modes -Hold
if ((distL >40 && distR>40) && (distL <50 && distR<50)) //Detect Both Hands for Play/Pause
{Serial.println("Play/Pause"); delay (500);}

if ((distL >30 && distR>30) && (distL <40 && distR<40)) //Browser Home Functionality
{Serial.println("BrowserHome"); delay (500);}

if ((distL >20 && distR>20) && (distL <30 && distR<30)) //Mouse Open Functionality
{Serial.println("MouseDoubleClick"); delay (500);}

if ((distL >10 && distR>10) && (distL <20 && distR<20)) //Mouse Select Functionality
{Serial.println("LeftmostClick"); delay (500);}

calculate_distance(trigger1,echo1);
distL =dist;

calculate_distance(trigger2,echo2);
distR =dist;

 

//Control Modes
//Lock Left - Control Mode
if (distL>=13 && distL<=17)
{
  delay(100); //Hand Hold Time
  calculate_distance(trigger1,echo1);
  distL =dist;
  if (distL>=13 && distL<=17)
  {
    Serial.println("Left Locked");
    while(distL<=40)
    {
      calculate_distance(trigger1,echo1);
      distL =dist;
      if (distL<10) //Hand pushed in 
      {Serial.println ("Vup"); delay (100);}
      if (distL>20) //Hand pulled out
      {Serial.println ("Vdown"); delay (100);}
    }
  }
}

//Lock Right - Control Mode
if (distR>=13 && distR<=17)
{
  delay(100); //Hand Hold Time
  calculate_distance(trigger2,echo2);
  distR =dist;
  if (distR>=13 && distR<=17)
  {
    Serial.println("Right Locked");
    while(distR<=40)
    {
      calculate_distance(trigger2,echo2);
      distR =dist;
      if (distR<10) //Right hand pushed in
      {Serial.println ("Rewind"); delay (100);}
      if (distR>20) //Right hand pulled out
      {Serial.println ("Forward"); delay (100);}
  }
}
}

delay(200);
}