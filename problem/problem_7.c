#include<stdio.h>
int main(void){
    int sum_max=0;
    int table_max=0;
    int chair_max=0;

    int table;
    int chair;
    for(chair=0;(7-2*chair)/2>=0&&(14-5*chair)/3>=0;chair++){
        for(table=0;table<=(7-2*chair)/2&&table<=(14-5*chair);table++){
            if(sum_max<table*4+chair*5){
                sum_max=table*4+chair*5;
                table_max=table;
                chair_max=chair;
            }
        }
    }
    printf("一日にテーブルとチェアをそれぞれ、%d個、%d個製造すればよい\n",table_max,chair_max);
}
/*

一日にテーブルとチェアをそれぞれ、1個、2個製造すればよい
*/
