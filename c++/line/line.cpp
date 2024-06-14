#include<Arduino.h>
#include<line.h>
#include<timer.h>
#include<angle.h>

void Line::Line_value()
{
    this->line1 = 1;
    this->line2 = 1;
    this->line3 = 1;
    this->line4 = 1;
    this->line5 = 1;
    this->line6 = 1;
    this->line7 = 1;
    this->line8 = 1;
    this->line9 = 1;
    this->line10 = 1;
    this->line11 = 1;
    this->line12 = 1;
    this->line13 = 1;
    this->line14 = 1;
    this->line15 = 1;
    this->line16 = 1;
}

void LINE::setup(){
 for (int i=0; i<3; i++){
   pinMode(Lselect[i], OUTPUT);
   pinMode(Lread[i], INPUT);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
 }
 pinMode(LINE_light, OUTPUT);

 for (int i=0; i<24; i++){
   Lrad = PI_E / 12 * i;
   ele_X[i] = cos(Lrad);
   ele_Y[i] = sin(Lrad);
   Lsencer_Dir[i] = 15.0 * i;
 }
 digitalWrite(LINE_light,HIGH);
}

int LINE::getLine_Vec(){
  int LniseF = 10; 
  int data[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
  int data_ave[24]; 
  int data_on[24];
  int Lnum = 0;
  int flag = 0;
  int block_first[Long];
  int block_last[Long];
  int block_num = -1;
  float block_X[Long];
  float block_Y[Long];
  num = 0;
  for (int i=0; i<3; i++){
    num += digitalRead(Lread[i]);
  }
  return num;
}

 float x=0;
 float y=0;

 for(int j=0;j<LniseF;j++){
    for(int i=0; i<8; i++)  
      if(i==1 || i==3 || i==5 || i==7){
        digitalWriteFast(Lselect[0],HIGH);
      }else{
        digitalWriteFast(Lselect[0],LOW);
      }
      if(i==2 || i==3 || i==6 || i==7){
        digitalWriteFast(Lselect[1],HIGH);
      }else{
        digitalWriteFast(Lselect[1],LOW);
      }
      if(i>=4){
        digitalWriteFast(Lselect[2],HIGH);
      }else{
        digitalWriteFast(Lselect[2],LOW);
      }
    }

  for (int Lic_num=0; Lic_num<3; Lic_num++)
      {
        Lnum = i + Lic_num * 8; 
        data[Lnum] += analogRead(Lread[Lic_num]);
      }
    
  for(int i=0; i<24; i++) 
  {
    data_ave[i] = data[i] / LniseF;
  }

  if(LINE_Level < data_ave[0]){
    data_on[0] = 1;
  }else{
    data_on[0] = 0;
  }

for(int i=1; i<24; i++) 
  {
    if(LINE_Level < data_ave[i]){
      data_on[i] = 1;
    }else{
      data_on[i] = 0;
    }
  }
 if(flag == 0){
      if(data_on[i] == 1){
        block_num++;
        block_first[block_num] = i;
        flag = 1;
      }
    }

 int LINE::switchLineflag(angle linedir){
   linedir.to_range(-45,false);
  line_flag = 0;
  for(int i = 0; i < 4; i++){  
    if(-45 +(i * 90) < linedir.degree && linedir.degree < 45 +(i * 90)){ 
      line_flag = i + 1;
    }
  }
}
    
double line_switch(int,double,int);


float LINE::decideGoang(angle linedir,int line_flag){
  float goang = 0;
  linedir.to_range(-15,false);
  for(int i = 0; i < 12; i++){  
    if(-15 +(i * 30) < linedir.degree && linedir.degree < 15 +(i * 30)){ 
      goang = line_switch(i,linedir.degree,line_flag);
    }
  }
  
  return goang;
}


double line_switch(int i,double ang,int line_flag){  
  if(i == 11 || i <= 1){
    if(line_flag == 3){
      return 0.0;
    }
  }
  else if(2 <= i && i <= 4){
    if(line_flag == 4){
      return 90.0;
    }
  }
  else if(5 <= i && i <= 7){
    if(line_flag == 1){
      return 180.0;
    }
  }
  else if(8 <= i && i <= 10){
    if(line_flag == 2){
      return -90.0;
    }
  }

  double goang = (i * 30.0)- 180.0;


  return goang;
}
