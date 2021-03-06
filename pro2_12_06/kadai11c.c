//2019/12/6 課題11c 19d8104026j 可児憲太郎
#include<stdio.h>		
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
void print_list(int head,int data[],int next[]){
	int cursor=head;
	//printf("%d %d %d\n",cursor,next[cursor],head);
	while(-1!=cursor){
		printf("%d ",data[cursor]);
		cursor=next[cursor];
	}
	putchar('\n');
}
int main(void){
	int data[100]={-1,5,-3,-2,-9,-2};
	int next[100]={3,5,0,1,-1,4};
	int inew=6;
	int head=2;
	int tail=4;

	int i;
	print_list(head,data,next);
	
	int cursor=head;
	int pre_cursor=-1;
	while(-1!=cursor){
		if(data[cursor]<0){
			if(pre_cursor==-1){
				head=next[cursor];
			}else{
				next[pre_cursor]=next[cursor];
			}
		}else{
			pre_cursor=cursor;
		}
		cursor=next[cursor];
	}
	print_list(head,data,next);
	return 0;


}
/*
 *-3 -1 -2 5 -2 -9 
 *5
 */ 

