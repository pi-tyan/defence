#include <Arduino.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
int ball1,ball2,ball3,ball4,ball5,ball6,ball7,ball8,ball9,ball10,ball11,ball12,ball13,ball14,ball15,ball16;
float x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,r,deg;
unsigned long time_new, time_old = 0;
int ba[16]={ball1,ball2,ball3,ball4,ball5,ball6,ball7,ball8,ball9,ball10,ball11,ball12,ball13,ball14,ball15,ball16};
float x[]={x1,x2,x3,x4,x5};
float y[]={y1,y2,y3,y4,y5};
void ba_val();
void ball();
void pin();
void vec(float le1,float le2,float le3,float le4);
void vec5(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float x5, float y5);
void swap(int *pa, int *pb);
void bubble_sort(int n, int a[]);
void sort();
void setup(){
Serial.begin(9600);
for (int i =0; i<16; i++){
  ba[i]=0;
}

}


void loop() {

}



// put function definitions here:
void vec(float x1,float y1,float x2,float y2){
  x1=x1+x2;
  y1=y1+y2;
}
void vec5(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float x5, float y5)
{
  vec(x1,y1,x2,y2);
  vec(x3,y3,x4,y4);
  vec(x3,y3,x5,y5);
  vec(x1,y1,x3,y3);
}
void pin(){
  pinMode(8,OUTPUT);
}
void ba_val(){
  time_new= micros();
  
  float val1= PIND & _BV(8);
  float val2= PIND & _BV(6);
  float val3= PIND & _BV(4);
  float val4= PIND & _BV(2);
  float val5= PIND & _BV(34);
  float val6= PIND & _BV(30);
  float val7= PIND & _BV(28);
  float val8= PIND & _BV(24);
  float val9= PIND & _BV(22);
  float val10= PIND & _BV(20);
  float val11= PIND & _BV(18);
  float val12= PIND & _BV(16);
  float val13= PIND & _BV(14);
  float val14= PIND & _BV(26);
  float val15= PIND & _BV(12);
  float val16= PIND & _BV(10);
  float val[]={val1,val2,val3,val4,val5,val6,val7,val8,val9,val10,val11,val12,val13,val14,val15,val16};
  while (time_new - time_old<=833){
    for (int i=0; i<=15; i++){
       if(val[i]==1){
        ba[i]=ba[i]+1;
       } else
       {
        ba[i]=ba[i];
       }
    }
  }
  time_old=time_new;
}


void swap(int *pa, int *pb)
{
  int tmp;
 
  tmp = *pa;
  *pa = *pb;
  *pb = tmp;
}
void bubble_sort(int n, int a[])
{
  int i, j;
 
  for (i = 0; i < n; i++) {
    for (j = 1; j < n - i; j++) {
      if (a[j] < a[j - 1]) {
        swap(&a[j], &a[j - 1]);
      }
    }
  }
}
void sort(){
  bubble_sort(16,ba);
  for (int n =15; n>10; n--){
    if (ba[n]==ball1){//90
      x[15-n]=ball1;
      y[15-n]=0;
    } else if (ba[n]==ball2){//67.5
      x[15-n]=0.3826834*ball2;
      y[15-n]=0.9238795*ball2;
    }else if (ba[n]==ball3){//45
      x[15-n]=0.7071067*ball3;
      y[15-n]=0.7071067*ball3;
    }else if (ba[n]==ball4){//22.5
      x[15-n]=0.92387953*ball4;
      y[15-n]=0.38268343*ball4;
    }else if (ba[n]==ball5){//0
      x[15-n]=ball5;
      y[15-n]=0;
    }else if (ba[n]==ball6){//337.5
      x[15-n]=0.9238795*ball6;
      y[15-n]=-0.3826834*ball6;
    }else if (ba[n]==ball7){//315
      x[15-n]=0.7071067*ball7;
      y[15-n]=-0.7071067*ball7;
    }else if (ba[n]==ball8){//292.5
      x[15-n]=0.38268343*ball8;
      y[15-n]=-0.9238795*ball8;
    }else if (ba[n]==ball9){//270
      x[15-n]=0;
      y[15-n]=-1*ball9;
    }else if (ba[n]==ball10){//247.5
      x[15-n]=-0.3826834*ball10;
      y[15-n]=-0.9238795*ball10;
    }else if  (ba[n]==ball11){//225
      x[15-n]=-0.7071067*ball11;
      y[15-n]=-0.7071067*ball11;
    }else if (ba[n]==ball12){//202.5
      x[15-n]=-0.9238795*ball12;
      y[15-n]=-0.3826834*ball12;
    }else if (ba[n]==ball13){//180
      x[15-n]=-1*ball13;
      y[15-n]=0;
    }else if (ba[n]==ball14){//157.5
      x[15-n]=-0.9238795*ball14;
      y[15-n]=0.3826834*ball14;
    }else if (ba[n]==ball15){//135
      x[15-n]=-0.7071067*ball15;
      y[15-n]=0.7071067*ball15;
    }else if (ba[n]==ball16){//112.5
      x[15-n]=-0.3826834*ball16;
      y[15-n]=0.9238795*ball16;
    }
  }
 
}
void ball(){
  ba_val();
  sort();
  vec5(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5);
  r=sqrtf(x1*x1+y1*y1);
  deg=atanf(y1 / x1);
  deg=(180/ PI)*deg;
}


