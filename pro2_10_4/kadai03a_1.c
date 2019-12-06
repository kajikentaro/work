//課題3a(1) 2019/10/4 19D8104026J 可児憲太郎
#include<stdio.h>
int main(void){
    int num;
    printf("10桁以下の非負整数を入力してください:");
    scanf("%d",&num);
    int i;
    int sum=0;
    for(i=0;i<10;i++){
        sum+=num%10;
        num/=10;
    }
    printf("%d\n",sum);
}
/*
10桁以下の非負整数を入力してください:123456789
45

*/
