//課題5a 2019/10/18 19D8104026J 可児憲太郎
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
int main(void){
  printf("データ数nを入力してください:");
  int n;
  scanf("%d",&n);
  int a[8];
  input_array(a,n);
  print_array(a,n);
  return 0;
}
/*
データ数nを入力してください:3
1
1
1
1 1 1 
*/
