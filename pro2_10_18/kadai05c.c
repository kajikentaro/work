//課題5c 2019/10/18 19D8104026J 可児憲太郎
#include<stdio.h>
#define ARRAY_MAX 8
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
int search(int a[],int n,int x){
  int i;
  for(i=0;i<n;i++){
    if(a[i]==x)return i;
  }
  return -1;
}
void push(int a[],int *n_ptr,int x){
  a[*n_ptr]=x;
  (*n_ptr)++;
  //囲わないと0かけるn_ptrになります
}
int main(void){
  printf("データ数nを入力してください:");
  int n;
  scanf("%d",&n);
  int a[ARRAY_MAX];
  input_array(a,n);
  printf("整数xを入力してください:");
  int x;
  scanf("%d",&x);
  
  
  if(search(a,n,x)==-1){
    if(n>=ARRAY_MAX){
      puts("挿入できない");
    }else{
      push(a,&n,x);
    }
  }
  
  print_array(a,n);
  printf("データ数は%dです\n",n);
  return 0;
}
/*

データ数nを入力してください:3
1
2
3
整数xを入力してください:4
1 2 3 4 
データ数は4です
*/
