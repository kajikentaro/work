//2019/12/6 課題11d 19d8104026j 可児憲太郎
#include<stdio.h>
#define NONLINKED -1000

void print_polygon(int x[],int y[],int next[],int head){
	int cursor=head;
	while(cursor!=-1){
		printf("%d %d\n",x[cursor],y[cursor]);
		cursor=next[cursor];
	}
}
int main(void){
	int x[12]={0,0,1,1,2,2,2,3,3,4,4,4};
	int y[12]={3,1,2,3,1,3,0,4,2,3,0,1};
	int next[100]={2,NONLINKED,4,0,-1,NONLINKED,8,3,9,7,NONLINKED,NONLINKED};
	int head=6;
	int tail=4;

	print_polygon(x,y,next,head);
	printf("%d %d\n",x[head],y[head]);
	return 0;
}
/*
 * 2 0
 * 3 2
 * 4 3
 * 3 4
 * 1 3
 * 0 3
 * 1 2
 * 2 1
 * 2 0
 * */
