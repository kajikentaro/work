//課題3c  2019/10/4 19D8104026J 可児憲太郎
#include<stdio.h>
#define countNum 10
double getY(double X){
  return X*(X*X-2);
}
int main(void){
  double k,l;
  //printf("初期値を入力してください");
  scanf("%lf",&k);
  int i;
  printf("%.15lf %.15lf\n",k,getY(k));
  for(i=0;i<countNum;i++){
    l=(2*k*k*k)/(3*k*k-2);
    k=l;
    printf("%.15lf %.15lf\n",k,getY(k));
  }
  return 0;
}
