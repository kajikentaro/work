//課題08e 2019/11/15(FRI) 19d8104026j 可児憲太郎
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int change_door();
int open_door();
int select_door();
int door_num;
int open_num;
void bubble_sort(int a[] ,int n){
  for(int i=0;i<n;i++){
    for(int j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
	int tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
      }
    }
  }
}
int main(void){

  printf("扉の枚数を入力してください:");
  scanf("%d",&door_num);

  printf("司会者が開ける扉の枚数を指定してください:");
  scanf("%d",&open_num);
  
  int n;
  printf("何回試行しますか:");
  scanf("%d",&n);
  
  int do_change;
  printf("最初の選択を変更しますか(1 or 0):");
  scanf("%d",&do_change);
  
  
  srand((unsigned)time(NULL));
  int i;
  int success_num=0;
  int failure_num=0;
  for(i=0;i<n;i++){
    int door=select_door();
    //printf("最初に選んだ数字　%d\n",door);
    if(door==1){
      if(do_change){
	failure_num++;
      }else{
	success_num++;
      }
    }else{
      if(do_change){
	door=change_door(door);
	//printf("次に選んだ数字　%d\n",door);
	if(door==1){
	  success_num++;
	}else{
	  failure_num++;
	}
      }else{
	failure_num++;
      }
    }
    //putchar('\n');
  }
  printf("正解:%d 失敗:%d 正答率:%.1lf\n",success_num,failure_num,(double)success_num/n*100);
}
double my_rand(){
  return ((double)rand()+1.0)/((double)RAND_MAX+1.0);
}
int select_door(){
  //扉を一つ選ぶ
  double x=my_rand();
  int i;
  for(i=1;i<=door_num;i++){
    if(x<=(double)i/door_num){
      return i;
    }
  }
}
int open_door(int banned_door[],int banned_num){
  //引数banned_door[] と 1(正解)以外の扉を選ぶ。
  int i;
  double x=my_rand();
  int able_num=door_num-banned_num-1;
  
  for(i=1;i<=able_num;i++){
    if(x<=(double)i/(able_num)){
      int answer=i;

      int j;
      answer++;
      for(j=0;j<banned_num;j++){
	if(answer>=banned_door[i])answer++;
      }
      
      return answer;
    }
  }
}
int change_door(int pre_door){
  int banned_door[1000]={};
  banned_door[0]=pre_door;

  int banned_num=1;
  int i;
  for(i=1;i<=open_num;i++){
    banned_door[i]=open_door(banned_door,i);
    bubble_sort(banned_door,i+1);
  }
  
  
  double x=my_rand();
  int able_num=door_num-2;
  for(i=1;i<=able_num;i++){
    if(x<=(double)i/(able_num)){
      int answer=i;

      int j;
      //open_num+1となっているのは、最初に自分が開けた扉と、司会者が開けた扉の合計ため
      for(j=0;j<open_num+1;j++){
	if(answer>=banned_door[i])answer++;
      }
      
      return answer;
    }
  }
}
/*
扉の枚数を入力してください:3
何回試行しますか:1000000
最初の選択を変更しますか(1 or 0):1
正解:666233 失敗:333767 正答率:66.6
[19D8104026J@ISE51c pro2_11_15]$ ./a.out
扉の枚数を入力してください:10
何回試行しますか:1000000
最初の選択を変更しますか(1 or 0):1
正解:112768 失敗:887232 正答率:11.3


*/
