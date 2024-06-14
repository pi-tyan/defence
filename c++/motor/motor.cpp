#define pi 3.141592653
#include <motor.h>

void motor_deffence::moveMotor_l (angle ang,int val,double ac_val,LINE line){  
  double g = 0;               
  double h = 0;
  double Mval[4] = {0,0,0,0};  
  double max_val = val;        
  double mval_x = cos(ang.radians) + line.dis_X * line_val;  
  double mval_y = sin(ang.radians) + line.dis_Y * line_val;
}

void motor_deffence::moveMotor_r (angle ang,int val,double ac_val,LINE line){
  double g = 0;
  double h = 0;
  double Mval[4] = {0,0,0,0};
  double max_val = val;
  double mval_x = cos(ang.radians) + line.dis_X * line_val;
  double mval_y = sin(ang.radians) + line.dis_Y * line_val;
}

void Motor::motor::go()
{
  analogWrite(IN1mo1, 255);
  analogWrite(IN2mo1, 0);
  analogWrite(IN1mo2, 255);
  analogWrite(IN2mo2, 0);
  analogWrite(IN1mo3, 255);
  analogWrite(IN2mo3, 0);
  analogWrite(IN1mo4, 255);
  analogWrite(IN2mo4, 0);
}
void Motor::motor::stop()
{
  analogWrite(IN1mo1, 0);
  analogWrite(IN2mo1, 0);
  analogWrite(IN1mo2, 0);
  analogWrite(IN2mo2, 0);
  analogWrite(IN1mo3, 0);
  analogWrite(IN2mo3, 0);
  analogWrite(IN1mo4, 0);
  analogWrite(IN2mo4, 0);
}

const int IN1 = 3;
const int IN2 = 4;
const int IN3 = 5;
const int IN4 = 6;
const int ENA = 9;  
const int ENB = 10; 
 
int i = 0;
int step = 5;
 
void setup(){
 
  pinMode(IN1, OUTPUT);  
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
}
 
void loop(){
 
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
 
  for(i=0; i<=255; i=i+step){  
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(50);
  }
 
  delay(1000);
 
  
  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
 
  for(i=0; i<=255; i=i+step){  
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(50);
  }
 
  delay(1000);
 
}

