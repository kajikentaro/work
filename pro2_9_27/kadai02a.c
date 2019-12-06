//課題2a 2019-9-27 19d8104026j 可児憲太郎
#include<stdio.h>
int main(void){
    int i;
    int sum=0;
    for(i=0;i<3;i++){
      printf("%dつ目の整数値を入力してください:",i+1);
      int input;
      scanf("%d",&input);
      sum+=input;
    }
    printf("平均値は%fです\n",  (double)sum/3);
    return 0;
}
/*
1つ目の整数値を入力してください:-10
2つ目の整数値を入力してください:5
3つ目の整数値を入力してください:5
平均値は0.000000です
*/
