#include<stdio.h>
void find_max_pair(int a[],int b[],int n,int *index_a,int *index_b){
  int amin=0,bmin=0,amax=0,bmax=0;
  //これらは添字！
  int i;
  for(i=1;i<n;i++){
    if(a[i]<a[amin])amin=i;
    if(a[i]>a[amax])amax=i;
  }
  for(i=1;i<n;i++){
    if(b[i]<b[amin])bmin=i;
    if(b[i]>b[amax])bmax=i;
  }
  int min=a[amin]*b[bmin];
  int max=a[amax]*b[bmax];
  if(min>=max){
    *index_a=amin;
    *index_b=bmin;
  }else{
    *index_a=amax;
    *index_b=bmax;
  }
}
int main(void){
  int n;
  puts("最大データ数を入力してください");
  scanf("%d",&n);
  int a[8],b[8];
  puts("配列aを入力");
  int i;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  puts("配列bを入力");
  for(i=0;i<n;i++){
    scanf("%d",&b[i]);
  }
  int index_a,index_b;
  find_max_pair(a,b,n,&index_a,&index_b);
  printf("最大となる組み合わせは、a[%d]とb[%d]で、値は%d\n",index_a,index_b,a[index_a]*b[index_b]);
  return 0;
}
  
