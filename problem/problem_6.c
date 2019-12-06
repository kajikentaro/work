#include<stdio.h>
int function();
int main(void){
  puts("フィボナッチ数列を出力します");
  int n;
  printf("非負整数nを入力:");
  scanf("%d",&n);
  printf("%d\n",function(n));
  return 0;
}
int function(int n){
  if(n==0||n==1)return 1;
  return function(n-1)+function(n-2);
}
/*
フィボナッチ数列を出力します
非負整数nを入力:30
1346269
*/
