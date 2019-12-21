//2019/12/20 課題13b 19D8104026J 可児憲太郎
#include <stdio.h>
void myprint(int start,int data[],int next[],double x[],double y[]){
	int cursor=start;
	do{
		printf("%d %lf %lf\n",data[cursor],x[data[cursor]],y[data[cursor]]);
		cursor=next[cursor];
	}while(cursor!=start);
}
int ccw(double x0,double y0,double x1,double y1,double x2,double y2){
	double vecx1 =x1-x0;
	double vecy1 =y1-y0;
	double vecx2 =x2-x0;
	double vecy2 =y2-y0;
	double outer=vecx1*vecy2-vecx2*vecy1;
	//printf("%lf\n",outer);
	if(outer>=0)return 1;
	if(outer<0)return 0;
}
void myDelete(int next[],int cursor){
	next[cursor]=next[next[cursor]];
}
int convexHull(int start,int data[],int next[],double x[],double y[]){
	int cursor=start;
	int flag=start;
	int delete_num;
	do{
		delete_num=0;
	do{
		int isLeft=ccw(x[data[cursor]],y[data[cursor]],x[data[next[cursor]]],y[data[next[cursor]]],x[data[next[next[cursor]]]],y[data[next[next[cursor]]]]);
		if(isLeft){
			cursor=next[cursor];
		}else{
			//delete			
			delete_num++;
			//printf("%d \n",cursor);
			if(next[cursor]==flag){
				flag=next[next[cursor]];
			}
			myDelete(next,cursor);
		}
	}while(flag!=cursor);
	}while(delete_num>0);
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
}/*
int main(void){
	gnuplot_init();
	int head=-1,tail=-1;
	int inew=0;
	int i;
	for(i=0;i<10;i++){
		insert(seq[i],&head,&tail,&inew,data,next);
	}
	int start=convexHull(head,data,next,x,y);
	myprint(start,data,next,x,y);
	output_by_gnuplot_12_4(x,y,data,next,start);
	gnuplot_cleanup();
	return 0;
}

*/

int main(void){
	FILE *input;
	input=fopen("points_10.txt","r");
	int n;
	fscanf(input,"%d",&n);
	int i;
	double x[1024],y[1024];
	int seq[1024],data[1024],next[1024];
	int head=-1,tail=-1;
	int inew=0;
	int x_min,x_position;
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
