////課題07c 2019/11/8(FRI) 19d8104026j 可児憲太郎
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[1000000];

void make_array_r(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    a[i]=rand();
  }
}
void input_array(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
}
void print_array(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  putchar('\n');
}
int find_min_index(int a[],int n,int start_idx){
  int min_tmp=a[start_idx];
  int num_tmp=start_idx;
  for(int i=start_idx+1;i<n;i++){
    if(min_tmp>a[i]){
      min_tmp=a[i];
      num_tmp=i;
    }
  }
  return num_tmp;
}
void bubble_sort(int a[] ,int n){
  for(int i=0;i<n;i++){
    for(int j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
	int tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
      }
    }
  }
}
void get_needed_time(int n){

  
  //グローバル関数で定義された配列aにn個のランダムなデータを代入
  make_array_r(a,n);

  //aを出力
  //print_array(a,n);

  //時間計測開始
  int start=clock();
  
  //aを「バブルソート」で整列
  bubble_sort(a,n);

  //時間計測終了
  int end=clock();
  
  //aを出力
  //print_array(a,n);

  //経過時間を出力
  printf("ソートにかかった時間は %f 秒です\n",(double)(end-start)/CLOCKS_PER_SEC);
  
}

int main(void){
  int i;
  int twos=1;
  for(i=0;i<12;i++){
    twos*=2;
  }
  for(i=12;i<18;i++){
    printf("%dの時:",twos);
    get_needed_time(twos);
    twos*=2;
  }
  return 0;
    
    
    
}
/*
4096の時:ソートにかかった時間は 0.020000 秒です
8192の時:ソートにかかった時間は 0.140000 秒です
16384の時:ソートにかかった時間は 0.630000 秒です
32768の時:ソートにかかった時間は 2.650000 秒です
65536の時:ソートにかかった時間は 11.120000 秒です
131072の時:ソートにかかった時間は 44.980000 秒です

*/
