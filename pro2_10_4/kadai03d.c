//課題3d  2019/10/4 19D8104026J 可児憲太郎
#include<stdio.h>
#define countNum 15
#define ableNum 0.00000001
double getY(double X){
  return X*(X*X-2);
}
double mainfunction(double firstNum){
  double k=firstNum,l;
  int i;
  //printf("%.15lf %.15lf\n",k,getY(k));
  for(i=0;i<countNum;i++){
    l=(2*k*k*k)/(3*k*k-2);
    k=l;
    //printf("%.15lf %.15lf\n",k,getY(k));
  }
  return k;
}
double getAbsoluteNum(double input){
  if(input>0){
    return input;
  }else{
    return -input;
  }
}
int checkResult(double result){
  if(getAbsoluteNum(getY(result))<ableNum){
    if(getAbsoluteNum(result-1.414213562373095)<ableNum)return 3;
    if(getAbsoluteNum(result+1.414213562373095)<ableNum)return 1;
    if(getAbsoluteNum(result)<ableNum)return 0;
  }else{
    return 0;
  }
}
int main(void){
  int j;
  for(j=0;j<65;j++){
    double x=-2+0.0625*j;
    double result=mainfunction(x);
    printf("%lf 0 %d\n",x,checkResult(result));
  }
  return 0;
}
