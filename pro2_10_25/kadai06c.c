//課題06c 2019/10/25(FRI) 19d8104026j 可児憲太郎
#include<stdio.h>
#define MAX 100
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

  int a[MAX];
  puts("配列aを入力");
  input_array(a,n);
  print_array(a,n);

  selection_sort(a,n);

  print_array(a,n);
  return 0;
}
	 
  
/*
データ数nを入力:10
配列aを入力
1 10 2 9 3 8 4 7 5 6
1 10 2 9 3 8 4 7 5 6 
1 2 3 4 5 6 7 8 9 10 

*/
