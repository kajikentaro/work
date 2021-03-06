//2019/12/20 課題13b 19D8104026J 可児憲太郎
#include <stdio.h>
void myprint(int start,int data[],int next[],double x[],double y[]){
	int cursor=start;
	do{
		printf("%d %lf %lf\n",data[cursor],x[data[cursor]],y[data[cursor]]);
		cursor=next[cursor];
	}while(cursor!=start);
}
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
int main(void){
	FILE *input;
	input=fopen("points_1000.txt","r");
	int n;
	fscanf(input,"%d",&n);
	int i;
	double x[1024],y[1024];
	int seq[1024],data[1024],next[1024];
	int head=-1,tail=-1;
	int inew=0;
	double x_min;
	int x_position;
	for(i=0;i<n;i++){
		fscanf(input,"%lf %lf",&x[i],&y[i]);
		if(i==0||x_min>x[i]){
			x_min=x[i];
			x_position=i;
		}
	}
	for(i=0;i<n;i++){
		fscanf(input,"%d",&seq[i]);
	}
	int start;
	for(i=0;i<n;i++){
		if(seq[i]==x_position){
			start=inew;
		}
		insert(seq[i],&head,&tail,&inew,data,next);
	}
	printf("startとなる点はdata[%d]=%dです\n",start,data[start]);
	puts("startから出力します");
	myprint(start,data,next,x,y);
	fclose(input);
	return 0;
}
