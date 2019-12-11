//2019/12/6 課題11b 19d8104026j 可児憲太郎
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
void myRemove(int target,int head,int data[],int next[]){
	int cursor=head;
	int pre_cursor=-1;
	while(-1!=cursor){
		if(data[cursor]==target){
			//remove function
			next[pre_cursor]=next[cursor];
		}else{
			pre_cursor=cursor;
		}
		cursor=next[cursor];
	}
}
int main(void){
	int data[100]={41,67,34,50,69,24};
	int next[100]={1,4,3,5,-1,-1};
	int head_odd=0;
	int head_even=2;

	int tail_odd=4;
	int tail_even=5;
	int inew=6;

	int i;
	for(i=0;i<5;i++){
		int input;
		scanf("%d",&input);
		if(input%2==0){
			//even num
			insert(input,&head_even,&tail_even,&inew,data,next);
		}else{
			//odd num
			insert(input,&head_odd,&tail_odd,&inew,data,next);
		}
	}
	print_list(head_even,data,next);
	print_list(head_odd,data,next);
	
	int target;
	printf("消したい数を入力してください");
	scanf("%d",&target);
	if(target%2==0){
		//even num
		myRemove(target,head_even,data,next);
	}else{
		myRemove(target,head_odd,data,next);
	}
	print_list(head_even,data,next);
	print_list(head_odd,data,next);
	return 0;


}
/*
 * 1 2 3 4 5
 * 34 50 24 2 4 
 * 41 67 69 1 3 5 
 * 消したい数を入力してください4
 * 34 50 24 2 
 * 41 67 69 1 3 5 
 * */
