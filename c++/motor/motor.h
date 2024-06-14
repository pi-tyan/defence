#pragma  once

#include<Arduino.h>
#include<math.h>
#include<line.h>
#include<angle.h>

class Motor
{
private:
    int motorspeed1, motorspeed2, motorspeed3, motorspeed4;
    int IN1mo1, IN2mo1, IN1mo2, IN2mo2, IN1mo3, IN2mo3, IN1mo4, IN2mo4;
    void motor_ac(float);
    float Moutput(int,float);
    int line_val = 2;
    int Val[4];
public:
    void motor_stop(void);
    void motor_deg(float angle);
    void motor_turn(float NOW, float tardeg);
    Motor();
    const int pah[4] = {2,4,6,8};
    const int ena[4] = {3,5,7,9};
}