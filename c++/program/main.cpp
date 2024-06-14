#include <Arduino.h>
#include <ball.h>
#include <line.h>
#include <motor.h>
#include <BNO.h>
#include <PD.h>
ball ball_b;
line line_l;
motor motor_m;
bno bno_b;
pdcon pdcon_p;

void setup()
{
  serial.begin(9600);
}
void loop()
{
  char flag = 0;
  int deg = 0;
  if (flag == 0)
  {
    bno.setExtCrystalUse(false);
    motor.motor_deg(BALL);
    flag=1;
  }
  if (flag == 1)
  {
    ball.getBallposition();
    flag=2;
  }
  if (flag == 2)
  {
    line.getLine_Vec();
    flag=3;
  }
  if (flag == 3)
  {
    pdcon.pdcon_deg(deg);
    flag=4;
  }
  if (flag == 4)
  {
    motor.motor_deg(deg);
  }
}
