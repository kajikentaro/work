//課題2d 2019-9-27 19d8104026j 可児憲太郎
#include<stdio.h>
#include<math.h>
int sosu(int input){
  int tmp=1;
  int i;
  if(input==1)return 0;
  if(input==2)return 1;
  for(i=2;i<=(int)sqrt(input)+1;i++){
    if(input%i==0){
      tmp=0;
      break;
    }
  }
  return tmp;
}
int main(void){
  printf("整数を入力してください:");
  int a;
  scanf("%d",&a);
  if(sosu(a)){
      puts("素数でした");
  }else{
      puts("素数ではありませんでした");
  }
  return 0;
}  
/*
[19D8104026J@ISE51c pro2_9_27]$ ./a.out
整数を入力してください:5
素数でした
[19D8104026J@ISE51c pro2_9_27]$ ./a.out
整数を入力してください:15
素数ではありませんでした

*/
