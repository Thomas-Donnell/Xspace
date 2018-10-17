#include <Servo.h>
#include <IRremote.h>

int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int DP = 7;
int F = 8;
int G = 9;
int RECV_PIN = 11;
Servo launchServo;
int mot_min = 90;   //min servo angle  
int mot_max = 180; //Max servo angle   
int before;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(A, OUTPUT);
pinMode(B, OUTPUT);
pinMode(C, OUTPUT);
pinMode(D, OUTPUT);
pinMode(E, OUTPUT);
pinMode(DP, OUTPUT);
pinMode(F, OUTPUT);
pinMode(G, OUTPUT);

  before = 0;
   launchServo.attach(10);//////////////////////////////////////////////////////
   launchServo.write(mot_min);  
   
}

void One ()
{
digitalWrite(A, LOW);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, LOW);
digitalWrite(E, LOW);
digitalWrite(DP, LOW);
digitalWrite(F, LOW);
digitalWrite(G, LOW);

}
////////////////////////////////////////
void Two ()
{
digitalWrite(A, HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, LOW);
digitalWrite(D, HIGH);
digitalWrite(E, HIGH);
digitalWrite(DP, LOW);
digitalWrite(F, LOW);
digitalWrite(G, HIGH);

}
//////////////////////////////////////////////
void Three(){
  digitalWrite(A, HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, LOW);
digitalWrite(DP, LOW);
digitalWrite(F, LOW);
digitalWrite(G, HIGH);

}
////////////////////////////////////////////////
void Four(){
  digitalWrite(A, LOW);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, LOW);
digitalWrite(E, LOW);
digitalWrite(DP, LOW);
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);

}
/////////////////////////////////////////////////////
void Five(){
  digitalWrite(A, HIGH);
digitalWrite(B, LOW);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, LOW);
digitalWrite(DP, LOW);
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);

}
///////////////////////////////////////////
void loop() {
  if (irrecv.decode(&results)) {
Serial.println(results.value, HEX);
  if (results.value==0xCB3CC07F)
{ //Code to turn the LED ON/OFF
    if(before==0){ // if the LED was turned off, then we turn it on 
   
       launchServo.write(mot_max);  
      before=1; //LED is now turned on
    }
    else{
   
       launchServo.write(mot_min);  
      before=0;
    
    }}
 irrecv.resume();
  }}





    
