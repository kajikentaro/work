//追加課題1 2019/10/4 19d8104026j 可児憲太郎
#define countNum 10
#define firstNum 1.4
#define formula k*k-2
#define miniNum 0.0000000001
#include<stdio.h>
double numerical_diff(double x,double h){
  double k=x+h;
  double child1=formula;
  k=x;
  double child2=formula;
  return (child1-child2)/h;
}
int main(void){
  double k=1.4,l;
  int i;
  for(i=0;i<countNum;i++){
    l=(0-(formula))/(numerical_diff(k,miniNum))+k;
    k=l;
    printf("%d:%.15lf\n",i+1,k);
  }
  return 0;
}
/*
1:1.414285713103709
2:1.414213564251898
3:1.414213562373098
4:1.414213562373095
5:1.414213562373095
6:1.414213562373095
7:1.414213562373095
8:1.414213562373095
9:1.414213562373095
10:1.414213562373095
*/
