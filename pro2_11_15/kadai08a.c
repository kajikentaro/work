//課題08a 2019/11/15(FRI) 19d8104026j 可児憲太郎
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(void){
    srand((unsigned)time(NULL));
    double x=((double)rand()+1.0)/((double)RAND_MAX+1.0);
    int i;
    for(i=1;i<=6;i++){
        x-=1.0/6.0;
        if(x<=0){
            printf("%d\n",i);
            break;
        }
    }
}  
/*
1
*/
