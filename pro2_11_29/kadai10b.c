//2020/11/29 課題10b 19d8104026j 可児憲太郎
#include<stdio.h>
int main(void){
  int data[100]={41,67,34,50,69,24};
  int next[100]={1,4,3,5,-1,-1};
  int head_odd=0;
  int head_even=2;
  int tail_odd=4;
  int tail_even=5;
  int inew=6;

  int cursor=head_odd;
  int x;
  scanf("%d",&x);
  data[inew]=x;
  next[inew]=-1;
  if(1==x%2){
    //odd
    next[tail_odd]=inew;
    tail_odd=inew;
  }else{
    //even
    next[tail_even]=inew;
    tail_even=inew;
  }
  inew++;
  puts("奇数を出力します");
  while(-1!=cursor){
    printf("%d ",data[cursor]);
    cursor=next[cursor];
  }
  puts("\n偶数を出力します");
  cursor=head_even;
  while(-1!=cursor){
    printf("%d ",data[cursor]);
    cursor=next[cursor];
  }
  putchar('\n');
  return 0;
}
/*

50
奇数を出力します
41 67 69 
偶数を出力します
34 50 24 50
*/
