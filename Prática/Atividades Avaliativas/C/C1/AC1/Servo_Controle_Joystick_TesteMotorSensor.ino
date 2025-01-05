#include <VarSpeedServo.h>
 
//Cria objeto para controlar o servo base
VarSpeedServo servo_base;
//Cria objeto para controlar o servo inclinacao
VarSpeedServo servo_inclinacao;
//Cria objeto para controlar o servo altura
VarSpeedServo servo_altura;
//Cria objeto para controlar o servo garra
VarSpeedServo servo_garra;
 
// ---------------------------------------------------------

const int TRIG_PIN   = 4; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN   = 5; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int DISTANCE_THRESHOLD = 6; // centimeters
float duration_us, distance_cm;

// ---------------------------------------------------------
 
void setup()
{
  //Define a porta a ser ligada ao servo base
  servo_base.attach(11, 1, 180);
  //Define a porta a ser ligada ao servo inclinacao
  servo_inclinacao.attach(10, 1, 180);
  //Define a porta a ser ligada ao servo altura
  servo_altura.attach(9, 1, 180);
  //Define a porta a ser ligada ao servo garra
  servo_garra.attach(8, 1, 180);

  Serial.begin (9600);         // initialize serial port

  pinMode(TRIG_PIN, OUTPUT);   // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);    // set arduino pin to input mode
}
 
void loop()
{
  //Move o servo base
  Serial.println("Testando base:");
  Serial.println(">>> 1 ate 180");
  for (int pos=1; pos<=180; pos+=10) {
    servo_base.slowmove(pos, 60);
    delay(60);
  }  
  Serial.println(">>> 180 ate 1");
  for (int pos=180; pos>=1; pos-=10) {
    servo_base.slowmove(pos, 60);
    delay(60);
  }  
  servo_base.slowmove(90, 60);

  //Move o servo inclinacao
  Serial.println("Testando inclinacao:");
  Serial.println(">>> 1 ate 180");
  for (int pos=1; pos<=180; pos+=10) {
    servo_inclinacao.slowmove(pos, 60);
    delay(60);
  }  
  Serial.println(">>> 180 ate 1");
  for (int pos=180; pos>=1; pos-=10) {
    servo_inclinacao.slowmove(pos, 60);
    delay(60);
  }  
  servo_inclinacao.slowmove(90, 60);

  //Move o servo altura
  Serial.println("Testando altura:");
  Serial.println(">>> 1 ate 180");
  for (int pos=1; pos<=180; pos+=10) {
    servo_altura.slowmove(pos, 60);
    delay(60);
  }  
  Serial.println(">>> 180 ate 1");
  for (int pos=180; pos>=1; pos-=10) {
    servo_altura.slowmove(pos, 60);
    delay(60);
  }  
  servo_altura.slowmove(90, 60);

  //Move o servo garra
  Serial.println("Testando garra:");
  Serial.println(">>> 1 ate 180");
  for (int pos=1; pos<=180; pos+=10) {
    servo_garra.slowmove(pos, 60);
    delay(60);
  }  
  Serial.println(">>> 180 ate 1");
  for (int pos=180; pos>=1; pos-=10) {
    servo_garra.slowmove(pos, 60);
    delay(60);
  }  
  servo_garra.slowmove(1, 60);

// ------------------------------------------------------

  for (int i=1; i<=5; i++) {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // measure duration of pulse from ECHO pin and calculate the distance
  distance_cm = 0.017 * pulseIn(ECHO_PIN, HIGH);
  // print the value to Serial Monitor
  Serial.println("Distancia "+i);
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay(1000);
  }
}
