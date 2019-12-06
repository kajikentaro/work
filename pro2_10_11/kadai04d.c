//課題4d 2019/10/11 19D8104026J 可児憲太郎
#include<stdio.h>
int ends_with(int a,int b){
  while(1){
    if(b%10!=a%10)return 0;
    b/=10;a/=10;
    if(b==0)return 1;
  }
}
int main(void){
  int a,b;
  printf("aとbを入力してください:\n");
  scanf("%d %d",&a,&b);
  int result=ends_with(a,b);
  printf("%dは%dで",a,b);
  if(ends_with(a,b)){
    puts("終わりました");
  }else{
    puts("終わりませんでした");
  }
  return 0;
}
/*
[19D8104026J@ISE51c pro2_10_11]$ ./a.out 
aとbを入力してください:
123
23
123は23で終わりました
[19D8104026J@ISE51c pro2_10_11]$ ./a.out 
aとbを入力してください:
456
23
456は23で終わりませんでした
[19D8104026J@ISE51c pro2_10_11]$ ./a.out 
aとbを入力してください:
23
123
23は123で終わりませんでした
*/
