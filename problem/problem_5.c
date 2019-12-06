#include<stdio.h>
#define max 3000
#define target 966
int main(void){
  int i,j,k;
  int iTmp;
  int jTmp;
  printf("%dから%dまでで総当たりを試みます\n",-max,max);
  for(i=-max;i<=max;i++){
    iTmp=i*i*i;
    for(j=i;j<=max;j++){
      jTmp=j*j*j;
      for(k=j;k<=max;k++){
	if(iTmp+jTmp+k*k*k==target)printf("(%d,%d,%d),",i,j,k);
      }
    }
  }
  puts("");
  return 0;
}
/*
-3000から3000までで総当たりを試みます
(-2826,349,1017),(-2501,-965,2548),(-2166,179,1803),(-1880,39,2479),(-1615,-1363,1348),(343,807,2002),
*/
