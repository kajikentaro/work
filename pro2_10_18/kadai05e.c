//課題5e 2019/10/18 19D8104026J 可児憲太郎
#include<stdio.h>
int inclusion(int a,int b){
  int b_holder=b;
  while(a!=0){
    b=b_holder;
    while(1){
      if(a%10==b%10)break;
      b/=10;
      if(b==0)return 0;
    }
    a/=10;
  }
  return 1;
}
int main(void){
  int a,b;
  printf("非負整数a,bを入力してください:");
  scanf("%d %d",&a,&b);
  if (inclusion(a,b)){
    puts("bはaを含んでいます");
  }else{
    puts("bはaを含んでいません");
  }
  return 0;
}
    
/*
[19D8104026J@ISE51c pro2_10_18]$ ./a.out
非負整数a,bを入力してください:12
1425
bはaを含んでいます
[19D8104026J@ISE51c pro2_10_18]$ ./a.out
非負整数a,bを入力してください:98765 1234567890
bはaを含んでいます
[19D8104026J@ISE51c pro2_10_18]$ ./a.out
非負整数a,bを入力してください:1357 2468
bはaを含んでいません
[19D8104026J@ISE51c pro2_10_18]$ ./a.out
非負整数a,bを入力してください:1357 135
bはaを含んでいません
[19D8104026J@ISE51c pro2_10_18]$ ./a.out
非負整数a,bを入力してください:135
136
bはaを含んでいません
*/
