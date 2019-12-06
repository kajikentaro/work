//課題4c 2019/10/11 19D8104026J 可児憲太郎
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double getRand(double min,double max){
  return (min+(max-min)*((double)rand()+1.0)/((double)RAND_MAX+1.0));
}
void searchMin(int *minNo,int *minNo_,double *length,double a[],int n){
  int i,j;
  double tempMin;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      tempMin=fabs(a[i]-a[j]);
      if(i==0&&j==2){
	*minNo=i;
	*minNo_=j;
	*length=tempMin;
      }
      if(*length>fabs(a[i]-a[j])){
	*minNo=i;
	*minNo_=j;
	*length=tempMin;
      }
    }
  }
}
int main(void){
  int n;
  printf("nを入力してください:");
  scanf("%d",&n);
  double a[100];
  int i;
  for(i=0;i<n;i++){
    a[i]=getRand(-100,100);
    //printf("%lf\n",a[i]);
  }
  //代入完了
  int minNo,minNo_;
  double length;
  searchMin(&minNo,&minNo_,&length,a,n);
  //最小距離抽出完了
  printf("最も近いペア:(a[%d],a[%d]),距離:%lf\n",minNo,minNo_,length);
  return 0;
}
/*
nを入力してください:100
最も近いペア:(a[30],a[68]),距離:0.079406
*/
