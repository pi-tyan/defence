#pragma once

#include<Arduino.h>
#include<timer.h>
#include<set.h>

class BALL{
private:
        int ball1, ball2, ball3, ball4, ball5, ball6, ball7, ball8, ball9, ball10, ball11, ball12, ball13, ball14, ball15, ball16;
        float x1,x2,x3,x4,x5;
        float y1,y2,y3,y4,y5;
        float deg_old, ret;
        int ba[16]= {ball1, ball2, ball3, ball4, ball5, ball6, ball7, ball8, ball9, ball10, ball11, ball12, ball13, ball14, ball15, ball16};
        float x[5] = {x1, x2, x3, x4, x5};
        float y[5] = {y1, y2, y3, y4, y5};
public:
        float ang;
        float far;
        float far_old = 0;
        float x_pos;
        float y_pos;
        float dx;
        float far_old2 = 0;
        int flag = 1;
        int ball_get();
        BALL();
        int getBallposition();
        void print();
        void begin();
};