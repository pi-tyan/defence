#include <Arduino.h>
#include <stdio.h>

//PD制御ゲイン
#define GAIN_P 5.0
#define GAIN_D 1.0
//運動モデル
#define K_POS 1.0
#define K_VEL 1.0
#define MASS 1.0
#define INT_TIME 0.1

//PD制御
double PDctrl(double dCommand, double dVal)
{
 static double s_dErrIntg = 0;
 double dErr;
 double dRet;

//誤差
dErr = dCommand - dVal;

//誤差積分
s_dErrIntg += dErr * INT_TIME;

//制御入力
dRet = K_POS * dErr + K_VEL * s_dErrIntg;

return(dRet);
}
//以上！！