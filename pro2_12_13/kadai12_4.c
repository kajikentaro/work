//2019/12/11 課題12(4) 19D8104026J 可児憲太郎
#include <stdio.h>
#include "gnuplot.h"
void myprint(int start,int data[],int next[],double x[],double y[]){
	int cursor=start;
	do{
		printf("%d %lf %lf\n",data[cursor],x[data[cursor]],y[data[cursor]]);
		//printf("%lf %lf\n",x[data[cursor]],y[data[cursor]]);
		cursor=next[cursor];
	}while(cursor!=0);
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
			gnuplot_sleep(0.2);
			gnuplot_draw_polygon(x,y,data,next,start);
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
}
int main(void){
	gnuplot_init();
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
	int start=convexHull(head,data,next,x,y);
	myprint(start,data,next,x,y);
	output_by_gnuplot_12_4(x,y,data,next,start);
	gnuplot_cleanup();
	return 0;
}
/*
4 1.000000 0.000000
1 0.400000 0.500000
2 -0.600000 0.700000
3 -0.900000 0.550000
5 -0.600000 -0.300000
8 0.400000 -0.900000
*/
