#include<stdio.h>
#include<math.h>
double my_sin(double x,int N){
    double sum=0,item;
    int i,j;
    for(i=1;i<(2*N);i+=2){
        item=1;
        for(j=0;j<i;j++){
            item *=x;
            item /=(i-j);
        }
        //printf("item =%.15lf\n",item);
        if(i%4==1)sum+=item;
        if(i%4==3)sum-=item;
    }
    //printf("result:%.15lf\n",sum);
    return sum;
}/*
int main(void){
    double x;
    puts("xの値を入力してください");
    scanf("%lf",&x);
    int N;
    puts("Nの値を入力してください");
    scanf("%d",&N);
    my_sin(x,N);
    }*/
int main(void){
  int i;
  double tmp;
  for(i=0;i<5;i++){
    tmp=my_sin(M_PI_2,i+1);
    printf("N=%dの時　値:%lf 誤差:%lf\n",i+1,tmp,1-tmp);
  }
  return 0;
}
/*
N=1の時　値:1.570796 誤差:-0.570796
N=2の時　値:0.924832 誤差:0.075168
N=3の時　値:1.004525 誤差:-0.004525
N=4の時　値:0.999843 誤差:0.000157
N=5の時　値:1.000004 誤差:-0.000004
*/
