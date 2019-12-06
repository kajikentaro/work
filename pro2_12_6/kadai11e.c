//2019/12/6 課題11e 19d8104026j 可児憲太郎
#include<stdio.h>		
#define MAX 1000
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
void myRemove(int data[],int next[],int m){
	int counter=0;
	int cursor=0;
	int pre_cursor;
	while(1){
		pre_cursor=cursor;
		cursor=next[cursor];
		counter++;
		if(counter%m==0){
			next[pre_cursor]=next[cursor];
			if(next[cursor]==cursor)break;
		}
	}
	printf("%d\n",data[cursor]);
}
void print_list(int data[],int next[]){
	int cursor=0;
	int first_cursor=cursor;
	do{
		printf("%d ",data[cursor]);
		cursor=next[cursor];
	}while(cursor!=first_cursor);
	putchar('\n');
}
int main(void){
	int data[MAX];
	int next[MAX];
	int N;
	printf("Nを入力");
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++){
		data[i]=i+1;
		next[i]=i+1;
	}
	next[N-1]=0;
	print_list(data,next);
	int m;
	printf("Mを入力");
	scanf("%d",&m);
	myRemove(data,next,m);
	return 0;


}
/*
 * Nを入力100
 * 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
 * Mを入力4
 * 35
 * */
