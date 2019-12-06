//課題09b(2) 2019/11/22(FRI) 19d8104026j 可児憲太郎
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
int function(){
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
  return float_sum;
}
int main(void){
  int i;
  int log[21]={};
  for(i=0;i<1000000;i++){
    int floated=function();
    log[floated]++;
  }
  for(i=0;i<21;i++){
    printf("%d %lf\n",i,(double)log[i]/1000000);
  }
}
/*

0 0.176172
1 0.000000
2 0.092464
3 0.000000
4 0.073664
5 0.000000
6 0.065786
7 0.000000
8 0.061782
9 0.000000
10 0.060742
11 0.000000
12 0.061901
13 0.000000
14 0.065022
15 0.000000
16 0.074035
17 0.000000
18 0.092292
19 0.000000
20 0.176140
*/
