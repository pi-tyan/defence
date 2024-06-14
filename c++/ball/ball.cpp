#include<Arduino.h>
#include<timer.h>
#include<set.h>
#include<math.h>
#include<ball.h>
#define pi 3.141592653

BALL::BALL(){
    ball_x.setLenth(3);
    ball_y.setLenth(3);
    far__.setLenth(1000);
}

void BALL::begin(){
     Serial8.begin(57600);
}
void BAll::ba_val()
{
    timer timer1(0);
    int val1 = PINA & _BV(6);
    int val2 = PINC & _BV(7);
    int val3 = PINC & _BV(6);
    int val4 = PINE & _BV(5);
    int val5 = PINE & _BV(4);
    int val6 = PINE & _BV(3);
    int val7 = PINE & _BV(2);
    int val8 = PINE & _BV(1);
    int val9 = PINE & _BV(0);
    int val10 = PIND & _BV(0);
    int val11 = PIND & _BV(2);
    int val12 = PINH & _BV(0);
    int val13 = PINJ & _BV(0);
    int val14 = PINL & _BV(7);
    int val15 = PINC & _BV(7);
    int val16 = PINA & _BV(6);
    int val[] = {val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12, val13, val14, val15, val16};
    timer1 .reset();
    for(int i = 0; i < 16; i++)
    {
        if(val[i] = 1)
        {
            ba[i] = 1;
        }
        else
        {
            ba[i] = 0;
        }
        if(ba[i] = 0)
        {
            set(i, 0);
        }
        else
        {
            set(i, 1);
        }
    }
}
int BALL::getBallposition(){
    float x = ball_x.returnAve();
    float y = ball_y.returnAve();
    if(x == 0 || y == 0){
        flag = 0;
        return flag;
    }
    else{
        flag = 1;
    }
    x *= 0.05;
    y *= 0.05;
    if(0 < x){
        x_pos = 130 - x;
    }
    else{
        x_pos = -130 - x;
    }
    if(0 < y){
        y_pos = 130 - y;
    }
    else{
        y_pos = -130 - y;
    }
    if(150 < abs(x)){
        x = (x < 0 ? -150 : 150);
    }
    if(150 < abs(y)){
        y = (y < 0 ? -150 : 150);
    }
    return flag;
 }

void BALL::print(){
    Serial.print(" ang : ");
    Serial.println(ang);
    Serial.print(" far : ");
    Serial.println(far);
    Serial.print(" x : ");
    Serial.println(x_pos);
    Serial.print(" y : ");
    Serial.println(y_pos);
    Serial.print(" dx : ");
    Serial.println(dx);
    Serial.print(" catch : ");
    Serial.println(flag);
    Serial.print(" flag : ");
    Serial.println(flag);
}
