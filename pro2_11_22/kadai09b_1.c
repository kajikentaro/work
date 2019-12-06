//課題09b(1) 2019/11/22(FRI) 19d8104026j 可児憲太郎
#include<stdio.h>
#include<stdlib.h>
int get_point(){
  double tmp=(rand()+1.0)/(RAND_MAX+1.0);
  if(tmp>0.5){
    return 1;
  }else{
    return -1;
  }
}
int main(void){
  int i;
  int float_sum=0;
  int score=0;
  int previous_point;
  for(i=0;i<20;i++){
    int tmp=get_point();
    score+=tmp;
    if(score==0){
      if(tmp>0){
	//加算される前はマイナスだった
      }else{
	//加算される前はプラス
	float_sum++;
      }
    }
    if(score>0){
      float_sum++;
    }
  }
  printf("%d\n",float_sum);
}
/*
20
*/
