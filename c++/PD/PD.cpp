//検証します！！
void main()
{
double dF,dFctrl;
double dAcc,dVel,dPos;dTime;
int d;
}

{
//初期値
dVel=0;//速度
dPos=0;//位置
dTime=0;//時間
}

for(d=0;d<500;d++){
//コントロール
dFctrl=PDctrl(10,dPos);

//外力
dF=dFctrl-(K_POS*dPos+K_VEL*dVel);

//加速度
dAcc=dF/MASS;

//速度
dVel+=dAcc*INT_TIME;

//位置
dPos+=dVel*INT_TIME;

//時間
dTime+=INT_TIME;

printf("dTime=%f, dPos=%f, dVel=%f, dFctrl=%f, dF=%f, dAcc=%f\n",dTime,dPos,dVel,dFctrl,dF,dAcc);
}
