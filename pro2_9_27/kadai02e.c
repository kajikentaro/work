//課題2e 2019-9-27 19d8104026j 可児憲太郎
#include<stdio.h>
#include<math.h>
int sosu(int input){
  int tmp=1;
  int i;
  if(input==1)return 0;
  if(input==2)return 1;
  for(i=2;i<=(int)sqrt(input)+1;i++){
    if(input%i==0){
      tmp=0;
      break;
    }
  }
  return tmp;
}
int main(void){
  int i;
  int sum;
  int year=0;
  for(i=1989;i<=2019;i++){
    sum=0;
    sum+=i%10+(i/10)%10+(i/100)%10+i/1000;
    if(sosu(sum)){
      printf("年:%d\n",i);
      printf("各桁の和:%d\n",sum);
      year++;
    }
  }
  printf("素数となった年の個数:%d\n",year);
  return 0;
}
/*

年:1990
各桁の和:19
年:1994
各桁の和:23
年:2000
各桁の和:2
年:2001
各桁の和:3
年:2003
各桁の和:5
年:2005
各桁の和:7
年:2009
各桁の和:11
年:2010
各桁の和:3
年:2012
各桁の和:5
年:2014
各桁の和:7
年:2018
各桁の和:11
素数となった年の個数:11
*/
