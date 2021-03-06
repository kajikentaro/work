////課題07d 2019/11/8(FRI) 19d8104026j 可児憲太郎
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[1000000];
int b[1000000];

void make_array_r(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    a[i]=rand();
  }
}

void print_brunch(int a[],int n){
    int row_num=1;
    int cursor=0;
    while(cursor<n){
        for(int i=0;i<row_num;i++){
            printf("%d ",a[cursor]);
            cursor++;
            if(cursor==n)break;
        }
        putchar('\n');
        row_num*=2;
    }
    putchar('\n');
}
void print_array(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  putchar('\n');
}
void swap(int *x_ptr,int *y_ptr){
  int tmp=*x_ptr;
  *x_ptr=*y_ptr;
  *y_ptr=tmp;
}
void heap_sort(int a[],int b[],int n){
    //make-brunch-start
    for(int i=n-1;i>0;i--){
        if(a[i]>a[(i-1)/2]){
            swap(&a[i],&a[(i-1)/2]);
            //update-start
            int j=i;
            while(j*2+1<=n-1){
                //子が一つしかない場合
                if(j*2+1==n-1){
                    if(a[j*2+1]>a[j]){
                        swap(&a[j*2+1],&a[j]);
                        j=j*2+1;
                    }
                    break;
                }
                if(a[j*2+1]>a[j*2+2]){
                    if(a[j*2+1]>a[j]){
                        swap(&a[j*2+1],&a[j]);
                        j=j*2+1;
                    }else{
                        break;
                    }
                }else{
                    if(a[j*2+2]>a[j]){
                        swap(&a[j*2+2],&a[j]);
                        j=j*2+2;
                    }else{
                        break;
                    }
                }
            }
            //update-end
        }
    }
    //make-brunch-end

    for(int i=0;i<n;i++){
        b[i]=a[0];
        a[0]=a[n-i-1];
        //update-start
        int j=0;
        while(j*2+1<=(n-i)-1){
            //子が一つしかない場合
            if(j*2+1==(n-i)-1){
                if(a[j*2+1]>a[j]){
                    swap(&a[j*2+1],&a[j]);
                    j=j*2+1;
                }
                break;
            }
            if(a[j*2+1]>a[j*2+2]){
                if(a[j*2+1]>a[j]){
                    swap(&a[j*2+1],&a[j]);
                    j=j*2+1;
                }else{
                    break;
                }
            }else{
                if(a[j*2+2]>a[j]){
                    swap(&a[j*2+2],&a[j]);
                    j=j*2+2;
                }else{
                    break;
                }
            }
        }
        //update-end
    }

}
void heap_sort_parent(int n){

  
  //グローバル関数で定義された配列aにn個のランダムなデータを代入
  make_array_r(a,n);

  //aを出力
  //print_array(a,n);

  //時間計測開始
  int start=clock();
  
  //aを「ヒープソート」で整列
  heap_sort(a,b,n);

  //時間計測終了
  int end=clock();
  
  //bを出力
  //print_array(b,n);

  //経過時間を出力
  printf("ソートにかかった時間は %f 秒です\n",(double)(end-start)/CLOCKS_PER_SEC);
  
}

int main(void){
  int i;
  int twos=1;
  for(i=0;i<12;i++){
    twos*=2;
  }
  for(i=12;i<20;i++){
    printf("%dの時:",twos);
    heap_sort_parent(twos);
    twos*=2;
  }
  return 0;
}
/*
4096の時:ソートにかかった時間は 0.000000 秒です
8192の時:ソートにかかった時間は 0.000000 秒です
16384の時:ソートにかかった時間は 0.000000 秒です
32768の時:ソートにかかった時間は 0.010000 秒です
65536の時:ソートにかかった時間は 0.010000 秒です
131072の時:ソートにかかった時間は 0.030000 秒です
262144の時:ソートにかかった時間は 0.060000 秒です
524288の時:ソートにかかった時間は 0.120000 秒です
*/
