//課題08c(2) 2019/11/15(FRI) 19d8104026j 可児憲太郎
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int change_door();
int open_door();
int select_door();
int door_num;
int main(void){

  printf("扉の枚数を入力してください:");
  scanf("%d",&door_num);
  
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
int open_door(int pre_door){
  //引数pre_door と 1(正解)以外の扉を選ぶ。
  int i;
  double x=my_rand();
  int able_num=door_num-2;
  
  for(i=1;i<=able_num;i++){
    if(x<=(double)i/(able_num)){
      int answer=i;
      //1の場合を除く
      answer++;

      //pre_doorの場合を除く
      if(answer>=pre_door)answer++;
      return answer;
    }
  }
}
int change_door(int pre_door){
  //引数pre_door と open_door以外から選ぶ
  int opened=open_door(pre_door);

  int exclude1,exclude2;
  if(pre_door>opened){
    exclude1=opened;
    exclude2=pre_door;
  }else{
    exclude1=pre_door;
    exclude2=opened;
  }
  
  int i;
  double x=my_rand();
  int able_num=door_num-2;
  for(i=1;i<=able_num;i++){
    if(x<=(double)i/(able_num)){
      int answer=i;

      if(answer>=exclude1){
	answer++;
      }
      if(answer>=exclude2){
	answer++;
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
