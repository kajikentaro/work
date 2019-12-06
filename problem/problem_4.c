#include<stdio.h>
#include<math.h>
#define MAX 50
int main(void){
  int i,j;
  for(i=1;i<=50;i++){
    for(j=i+1;j<=50;j++){
      int tmp=(int)sqrt(i*i+j*j);
      double tmp_=(double)sqrt(i*i+j*j);
      if(tmp<MAX+0.1){
	if(tmp*tmp==tmp_*tmp_)printf("(%d,%d,%d),",i,j,tmp);
	if((tmp+1)*(tmp+1)==tmp_*tmp_)printf("誤差修正有(%d,%d,%d),",i,j,tmp+1);
      }
    }
  }
  puts("");
  return 0;
}
/*

(3,4,5),(5,12,13),(6,8,10),(7,24,25),(8,15,17),(9,12,15),(9,40,41),(10,24,26),(12,16,20),(12,35,37),(14,48,50),(15,20,25),(15,36,39),(16,30,34),(18,24,30),(20,21,29),(21,28,35),(24,32,40),(27,36,45),(30,40,50),

*/
