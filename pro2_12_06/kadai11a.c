//2019/12/6 課題11a 19d8104026j 可児憲太郎
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
	int data[100];
	int next[100];
	int head_odd=-1;
	int head_even=-1;

	int tail_odd=-1;
	int tail_even=-1;
	int inew=0;

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
	return 0;


}
/*
1 2 3 4 5
2 4 
1 3 5 
*/
