#include<stdio.h>
#define MAX 102
int main(void){
    int zahlen[MAX]={1,1};
    int i,j;
    for(i=2;i<MAX;i++){
        if(!zahlen[i]){
            for(j=i*2;j<MAX;j+=i){
                zahlen[j]=1;
            }
        }
    }
    for(i=4;i<MAX;i++){
        if(!zahlen[i]&&!zahlen[i-2]){
            printf("(%d,%d),",i-2,i);
        }
    }
    puts("");
}
/*
(3,5),(5,7),(11,13),(17,19),(29,31),(41,43),(59,61),(71,73),
*/
