////課題07b(2) 2019/11/8(FRI) 19d8104026j 可児憲太郎

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
double getLength(double x,double y){
  return sqrt((x-0.5)*(x-0.5)+(y-0.5)*(y-0.5));
}
double get_also_PI(int n){
  int i;
  int inner_point=0;
  for(i=0;i<n;i++){
    double x=(rand()+1.0)/((double)RAND_MAX+1.0);
    double y=(rand()+1.0)/((double)RAND_MAX+1.0);
    if(getLength(x,y)<0.5){
      inner_point++;
    }
  }
  return (double)inner_point/n*4;
  
}
int main(void){
  srand((unsigned int)time(NULL));
  int n;
  puts("点の数nを入力してください");
  scanf("%d",&n);

  int i;
  double sum=0;
  double result[10];
  for(i=0;i<10;i++){
    double also_PI=get_also_PI(n);
    sum+=also_PI;
    result[i]=also_PI;
  }
  double ave=sum/10;
  
  puts("円周率の推定値の平均は");
  printf("%lf です。\n",ave);

  double sum_=0;
  for(i=0;i<10;i++){
    sum_+=(result[i]-ave)*(result[i]-ave);
  }
  
  puts("標準偏差は");
  printf("%lf です。\n",sqrt(sum_/10));
  return 0;
}
    
/*
[19D8104026J@ISE51c pro2_11_8]$ ./a.out
点の数nを入力してください
10
円周率の推定値の平均は
3.080000 です。
標準偏差は
0.538145 です。
[19D8104026J@ISE51c pro2_11_8]$ ./a.out
点の数nを入力してください
1000
円周率の推定値の平均は
3.136400 です。
標準偏差は
0.033915 です。
[19D8104026J@ISE51c pro2_11_8]$ ./a.out
点の数nを入力してください
100000
円周率の推定値の平均は
3.142492 です。
標準偏差は
0.003852 です。
[19D8104026J@ISE51c pro2_11_8]$ ./a.out
点の数nを入力してください
10000000
円周率の推定値の平均は
3.141533 です。
標準偏差は
0.000420 です。
*/
