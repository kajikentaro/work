//課題4a 2019/10/11 19D8104026J 可児憲太郎
#include<stdio.h>
int main(void){
  int x=1,y=2;
  int *x_pt;
  printf("xのアドレス             (&x):%p\n",&x);
  printf("xの値                    (x):%d\n",x);

  x_pt=&x;
  printf("ポインタx_ptの値      (x_pt):%p\n",x_pt);
  printf("x_ptが指すメモリの値 (*x_pt):%d\n",*x_pt);

  y=*x_pt; 
  printf("xの値                    (x):%d\n",x);
  printf("yの値                    (y):%d\n",y);

  *x_pt=0;
  printf("xの値                    (x):%d\n",x);
  printf("yの値                    (y):%d\n",y);
  printf("x_ptが指すメモリの値 (*x_pt):%d\n",*x_pt);
  return 0;
}
/*
xの値が変化した。
x_ptにはxのアドレスが格納されていて、*x_ptでxにアクセスすることができ、値が0に書き換えられるから。
*/
/*
xのアドレス             (&x):0x7fffaa97738c
xの値                    (x):1
ポインタx_ptの値      (x_pt):0x7fffaa97738c
x_ptが指すメモリの値 (*x_pt):1
xの値                    (x):1
yの値                    (y):1
xの値                    (x):0
yの値                    (y):1
x_ptが指すメモリの値 (*x_pt):0
*/
