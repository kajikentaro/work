#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int myRand(){
  double tmp=(rand()+1.0)/(RAND_MAX+1.0);
  int i;
  //ここ書き換え可能
  int div=10;
  for(i=1;i<=div;i++){
    if(tmp<=(double)i/div){
      return i-1;
    }
  }
}
int main(void){
  srand(time(NULL));
  int answer=myRand();
  int q=-1;
  int count=0;
  while(q!=answer){
    count++;
    puts("数字を入力してください");
    scanf("%d",&q);
    if(q>answer)printf("%dよりも小さい数です。",q);
    if(q<answer)printf("%dよりも大きな数です。",q);
  }
  printf("当たりです。%d回で当てられました\n",count);
  return 0;
}
/*
数字を入力してください
3
3よりも大きな数です。数字を入力してください
4
4よりも大きな数です。数字を入力してください
5
5よりも大きな数です。数字を入力してください
6
6よりも大きな数です。数字を入力してください
7
当たりです。5回で当てられました
*/
