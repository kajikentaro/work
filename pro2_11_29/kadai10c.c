//2020/11/29 課題10c 19d8104026j 可児憲太郎
#include<stdio.h>
void insert_back(int x,int *tail,int *inew,int data[],int next[]){
  data[*inew]=x;
  next[*inew]=-1;
  next[*tail]=*inew;
  *tail=*inew;
  *inew++;
}
void print_list(int head,int data[],int next[]){
  int cursor=head;
  while(-1!=cursor){
    printf("%d ",data[cursor]);
    cursor=next[cursor];
  }
  putchar('\n');
}
int main(void){
  int data[100]={41,67,34,50,69,24};
  int next[100]={1,4,3,5,-1,-1};
  int head_odd=0;
  int head_even=2;
  int tail_odd=4;
  int tail_even=5;
  int inew=6;
  int x;
  scanf("%d",&x);
  if(1==x%2){
    insert_back(x,&tail_odd,&inew,data,next);
  }else{
    insert_back(x,&tail_even,&inew,data,next);
  }
  puts("奇数を出力します");
  print_list(head_odd,data,next);
  puts("偶数を出力します");
  print_list(head_even,data,next);
  return 0;
}
/*
6
奇数を出力します
41 67 69 
偶数を出力します
34 50 24 6 
*/
