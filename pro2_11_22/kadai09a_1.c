//課題09a(1) 2019/11/22(FRI) 19d8104026j 可児憲太郎
#include<stdio.h>
#include<stdlib.h>
int is1k(){
    double tmp=(rand()+1.0)/(RAND_MAX+1.0);
    if(tmp>0.4){
        return 1;
    }else{
        return 0;
    }
}
int main(void){
    int a;
    scanf("%d",&a);
    int people=20;
    int i;
    for(i=1;i<=people;i++){
        if(is1k()){
            a--;
        }else{
            a++;
        }
        if(a<=0){
            break;
        }
    }
    printf("%d\n",i);
}

