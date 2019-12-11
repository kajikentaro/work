//課題07a 2019/11/8(FRI) 19d8104026j 可児憲太郎
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
void swap(int *x_ptr,int *y_ptr){
  int tmp=*x_ptr;
  *x_ptr=*y_ptr;
  *y_ptr=tmp;
}
void selection_sort(int a[] ,int n){
  for(int i=0;i<n;i++){
    swap(&a[find_min_index(a,n,i)],&a[i]);
  }
}
int main(void){
  int n;
  printf("データ数nを入力:");
  scanf("%d",&n);

  
  //グローバル関数で定義された配列aにn個のランダムなデータを代入
  make_array_r(a,n);

  //aを出力
  print_array(a,n);

  //時間計測開始
  int start=clock();
  
  //aを「選択ソート」で整列
  selection_sort(a,n);

  //時間計測終了
  int end=clock();
  
  //aを出力
  print_array(a,n);

  //経過時間を出力
  printf("ソートにかかった時間は %f 秒です(%d)\n",(double)(end-start)/CLOCKS_PER_SEC,end-start);
  
  return 0;
}
	 
  
/*nがそれぞれ、
  
4096の時：
ソートにかかった時間は 0.010000 秒です(10000)

8192の時:
ソートにかかった時間は 0.070000 秒です(70000)

16384の時:
ソートにかかった時間は 0.290000 秒です(290000)

32768の時:
ソートにかかった時間は 1.140000 秒です(1140000)

65536の時:
ソートにかかった時間は 4.570000 秒です(4570000)

131072の時:
ソートにかかった時間は 18.220000 秒です(18220000)

*/
