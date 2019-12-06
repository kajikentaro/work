//課題5b 2019/10/18 19D8104026J 可児憲太郎
#include<stdio.h>
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
int main(void){
  printf("データ数nを入力してください:");
  int n;
  scanf("%d",&n);
  int a[8];
  input_array(a,n);
  printf("整数xを入力してください:");
  int x;
  scanf("%d",&x);
  printf("search関数の戻り値は%dです\n",search(a,n,x));
  return 0;
}
/*
データ数nを入力してください:3
1
2
3
整数xを入力してください:2
search関数の戻り値は、1です
*/
