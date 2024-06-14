#pragma once

#include <timer.h>
#include <Arduino.h>
#include <angle.h>
#define Long 5

class line
{
private:
    char line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11, line12, line13, line14, line15, line16;
    char line[16] = {line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11, line12, line13, line14, line15, line16};
public:
    int getLine_Vec();
    void print();
    void begin();
    int switchLineflag(angle);
    float decideGoang(angle,int);
    void vector();
}
