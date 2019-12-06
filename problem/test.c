#include<stdio.h>
int main(void){
  int a[3];
  for(int i=0;i<3;i++){
    scanf("%d",&a[i]);
  }
  for(int i=0;i<3;i++){
    a[i]=a[i]*a[i]*a[i];
  }
  int result=0;
  for(int i=0;i<3;i++){
    result+=a[i];
  }
  printf("%d",result);
  return 0;
}
