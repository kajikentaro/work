////課題07b(1) 2019/11/8(FRI) 19d8104026j 可児憲太郎
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
double getLength(double x,double y){
  return sqrt((x-0.5)*(x-0.5)+(y-0.5)*(y-0.5));
}
int main(void){
  int n;
  puts("点の数nを入力してください");
  scanf("%d",&n);
  int i;
  srand((unsigned int)time(NULL));
  int inner_point=0;
  for(i=0;i<n;i++){
    double x=(rand()+1.0)/((double)RAND_MAX+1.0);
    double y=(rand()+1.0)/((double)RAND_MAX+1.0);
    if(getLength(x,y)<0.5){
      inner_point++;
    }
  }
  puts("計算された円の面積の近似値は");
  double result=(double)inner_point/n;
  printf("%lf です。%lf の誤差\n ",result,result-M_PI*0.5*0.5);
  return 0;
}
    
/*
[19D8104026J@ISE51c pro2_11_8]$ ./a.out
点の数nを入力してください
10000
計算された円の面積の近似値は
0.786300 です。0.000902 の誤差
*/
