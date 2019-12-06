//課題2b 2019-9-27 19d8104026j 可児憲太郎
#include<stdio.h>
int main(void){
    printf("自然数nを入力してください");
    int n;
    scanf("%d",&n);
    int i;
    int sum=0;
    for(i=0;i<n;i++){
        int input;
	printf("%d番目の整数値を入力:",i+1);
        scanf("%d",&input);
        sum+=input;
    }
    printf("平均値は%fです\n",(double)sum/n);
    return 0;
}
/*
自然数nを入力してください5
1番目の整数値を入力:1
2番目の整数値を入力:2
3番目の整数値を入力:3
4番目の整数値を入力:4
5番目の整数値を入力:5
平均値は3.000000です
*/
