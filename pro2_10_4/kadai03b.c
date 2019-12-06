//課題3b  2019/10/4 19D8104026J 可児憲太郎
#include<stdio.h>
#define a 2
#define countNum 8
#define firstNum 1.2
int main(void){
  double k=1.2,l;
  int i;
  for(i=0;i<countNum;i++){
    l=(a+k*k)/(2*k);
    k=l;
    printf("%d:%.15lf\n",i+1,k);
  }
  return 0;
}
/*
1:1.433333333333333
2:1.414341085271318
3:1.414213568122094
4:1.414213562373095
5:1.414213562373095
6:1.414213562373095
7:1.414213562373095
8:1.414213562373095
*/
