//課題3a(2) 2019/10/4 19D8104026J 可児憲太郎
#include<stdio.h>
int digit_sum();
int main(void){
    int num;
    printf("10桁以下の非負整数を入力してください:");
    scanf("%d",&num);
    
    printf("%d\n",digit_sum(num));
}
int digit_sum(int x){
    int i;
    int sum=0;
    for(i=0;i<10;i++){
        sum+=x%10;
        x/=10;
    }
    return sum;
}
/*
10桁以下の非負整数を入力してください:123456789
45

*/
