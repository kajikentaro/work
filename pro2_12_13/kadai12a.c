//2019/12/11 課題12a 19D8104026J 可児憲太郎
#include <stdio.h>
#define size 10
void myprint(double x[],double y[],int next[]){
	int cursor=0;
	do{
		printf("%lf %lf\n",x[cursor],y[cursor]);
		cursor=next[cursor];
	}while(cursor!=0);
}
int main(void){
	double x[]={-0.42,0.4,-0.6,-0.9,1.0,-0.6,0.05,-0.1,0.4,-0.4};
	double y[]={0.2,0.5,0.7,0.55,0.0,-0.3,0.4,-0.03,-0.9,-0.1};
	int next[size];
	int i;
	for(i=0;i<size;i++){
		if(i==size-1){
			next[i]=0;
		}else{
			next[i]=i+1;
		}
	}
	myprint(x,y,next);
	return 0;

}
