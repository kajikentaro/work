//2019/12/11 課題12b 19D8104026J 可児憲太郎
#include <stdio.h>
#define size 10
void myprint(double x[],double y[],int next[]){
	int cursor=0;
	do{
		printf("%lf %lf\n",x[cursor],y[cursor]);
		cursor=next[cursor];
	}while(cursor!=0);
}
int ccw(double x0,double y0,double x1,double y1,double x2,double y2){
	double vecx1 =x1-x0;
	double vecy1 =y1-y0;
	double vecx2 =x2-x0;
	double vecy2 =y2-y0;
	double outer=vecx1*vecy2-vecx2*vecy1;
	printf("%lf\n",outer);
	if(outer>=0)return 1;
	if(outer<0)return 0;
}
void myDelete(double x[],double y[],int next[],int cursor){
	next[cursor]=next[next[cursor]];
}
void convexHull(double x[],double y[],int next[]){
	int cursor=0;
	int flag=0;
	do{
		int isLeft=ccw(x[cursor],y[cursor],x[cursor+1],y[cursor+1],x[cursor+2],y[cursor+2]);
		if(isLeft){
			cursor=next[cursor];
		}else{
			//delete			
			if(next[cursor]==flag){
				flag=next[next[cursor]];
			}
			myDelete(x,y,next,cursor);
		}
		cursor=next[cursor];
	}while(flag!=cursor);
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
	convexHull(x,y,next);
	myprint(x,y,next);
	return 0;

}
