//2019/12/11 課題12(1) 19D8104026J 可児憲太郎
#include <stdio.h>
void insert(int x,int *head,int *tail,int *inew,int data[],int next[]){
	data[*inew]=x;
	next[*inew]=-1;
	if(*head==-1){
		*head=*inew;
	}else{
		next[*tail]=*inew;
	}
	*tail=*inew;
	*inew+=1;
}

void myprint(int start,int data[],int next[],double x[],double y[]){
	int cursor=start;
	do{
		printf("%d %lf %lf\n",cursor,x[data[cursor]],y[data[cursor]]);
		//printf("%lf %lf\n",x[data[cursor]],y[data[cursor]]);
		cursor=next[cursor];
	}while(cursor!=0);
}
int main(void){
	double x[10]={-0.42,0.4,-0.6,-0.9,1.0,-0.6,0.05,-0.1,0.4,-0.4};
	double y[10]={0.2,0.5,0.7,0.55,0.0,-0.3,0.4,-0.03,-0.9,-0.1};
	int seq[10]={4,1,6,2,3,0,7,9,5,8};
	int data[100],next[100];
	int head=-1,tail=-1;
	int inew=0;
	int i;
	for(i=0;i<10;i++){
	  insert(seq[i],&head,&tail,&inew,data,next);
	}
	next[tail]=head;
	myprint(head,data,next,x,y);
	return 0;

}
/*
0 1.000000 0.000000
1 0.400000 0.500000
2 0.050000 0.400000
3 -0.600000 0.700000
4 -0.900000 0.550000
5 -0.420000 0.200000
6 -0.100000 -0.030000
7 -0.400000 -0.100000
8 -0.600000 -0.300000
9 0.400000 -0.900000
*/
