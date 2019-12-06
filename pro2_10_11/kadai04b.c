//課題4b 2019/10/11 19D8104026J 可児憲太郎
#include<stdio.h>
#include<math.h>
void root(double a,double b,double c,double *x_pt,double *y_pt,int *ok_pt){
  double d=b*b-(4*a*c);
  if(d>=0){
    *ok_pt=1;
    *x_pt=(-b+sqrt(d))/(2*a);
    *y_pt=(-b-sqrt(d))/(2*a);
  }else{
    *ok_pt=0;
  }
}
int main(void){
  double a,b,c,x,y;
  int ok;
  printf("a b cを入力してください:");
  scanf("%lf %lf %lf",&a,&b,&c);
  root(a,b,c,&x,&y,&ok);
  if(ok==1){
    printf("解は %.1lf と %.1lf です\n",x,y);
  }else{
    puts("解がありません");
  }
  return 0;
}
/*

a b cを入力してください:1 2 1
解は -1.0 と -1.0 です
*/
