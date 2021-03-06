#include <stdio.h>
#include "gnuplot.h"

FILE* gnuplot_pipe;

void gnuplot_init(void)
{
    gnuplot_pipe = popen("gnuplot -persist", "w");
    fprintf(gnuplot_pipe, "set size ratio -1\n");
}

void gnuplot_cleanup(void)
{
    pclose(gnuplot_pipe);
}

void gnuplot_sleep(double sec)
{
    fprintf(gnuplot_pipe, "pause %f\n", sec);
}


void gnuplot_draw_points(double data_x[], double data_y[], int data[], int next[], int start)
{
    int idx;
    
    //fprintf(gnuplot_pipe, "plot '-' with lines lc rgb 'dark-violet' lw 3 notitle,");
    fprintf(gnuplot_pipe, "plot '-' with points lc rgb 'blue' ps 1.5 pt 7 notitle\n");
    
    idx = start;
    do {
        fprintf(gnuplot_pipe, "%f %f\n", data_x[data[idx]], data_y[data[idx]]);
        idx = next[idx];
    } while (idx != start);
    fprintf(gnuplot_pipe, "%f %f\n", data_x[data[start]], data_y[data[start]]);
    //fprintf(gnuplot_pipe, "e\n");
    
    idx = start;
    do {
        fprintf(gnuplot_pipe, "%f %f\n", data_x[data[idx]], data_y[data[idx]]);
        idx = next[idx];
    } while (idx != start);
    //fprintf(gnuplot_pipe, "e\n");
        fprintf(gnuplot_pipe,"quit \n");
    fflush(gnuplot_pipe);
}



void gnuplot_draw_polygon(double data_x[], double data_y[], int data[],int next[], int start)
{
    int idx;
    
    fprintf(gnuplot_pipe, "plot '-' with lines lc rgb 'dark-violet' lw 3 notitle,");
    fprintf(gnuplot_pipe, "     '-' with points lc rgb 'blue' ps 1.5 pt 7 notitle\n");
    
    idx = start;
    do {
        fprintf(gnuplot_pipe, "%f %f\n", data_x[data[idx]], data_y[data[idx]]);
        idx = next[idx];
    } while (idx != start);
    fprintf(gnuplot_pipe, "%f %f\n", data_x[data[start]], data_y[data[start]]);
    fprintf(gnuplot_pipe, "e\n");
    
    idx = start;
    do {
        fprintf(gnuplot_pipe, "%f %f\n", data_x[data[idx]], data_y[data[idx]]);
        idx = next[idx];
    } while (idx != start);
    fprintf(gnuplot_pipe, "e\n");
}



void output_by_gnuplot_12_4(double data_x[], double data_y[], int data[],int next[], int start)
{
    int idx;
    fprintf(gnuplot_pipe,"set terminal png\n");
    fprintf(gnuplot_pipe,"set output 'kadai12_4.png'\n");
    fprintf(gnuplot_pipe, "plot '-' with lines lc rgb 'dark-violet' lw 3 notitle,");
    fprintf(gnuplot_pipe, "     '-' with points lc rgb 'blue' ps 1.5 pt 7 notitle\n");
    
    idx = start;
    do {
        fprintf(gnuplot_pipe, "%f %f\n", data_x[data[idx]], data_y[data[idx]]);
        idx = next[idx];
    } while (idx != start);
    fprintf(gnuplot_pipe, "%f %f\n", data_x[data[start]], data_y[data[start]]);
    fprintf(gnuplot_pipe, "e\n");
    
    idx = start;
    do {
        fprintf(gnuplot_pipe, "%f %f\n", data_x[data[idx]], data_y[data[idx]]);
        idx = next[idx];
    } while (idx != start);
    fprintf(gnuplot_pipe, "e\n");


    fprintf(gnuplot_pipe,"quit \n");
    fflush(gnuplot_pipe);//おまじない
}


void output_by_gnuplot_13_4(double data_x[], double data_y[], int data[],int next[], int start)
{
    int idx;
    fprintf(gnuplot_pipe,"set terminal png\n");
    fprintf(gnuplot_pipe,"set output 'kadai13_4.png'\n");
    fprintf(gnuplot_pipe, "plot '-' with lines lc rgb 'dark-violet' lw 3 notitle,");
    fprintf(gnuplot_pipe, "     '-' with points lc rgb 'blue' ps 1.5 pt 7 notitle\n");
    
    idx = start;
    do {
        fprintf(gnuplot_pipe, "%f %f\n", data_x[data[idx]], data_y[data[idx]]);
        idx = next[idx];
    } while (idx != start);
    fprintf(gnuplot_pipe, "%f %f\n", data_x[data[start]], data_y[data[start]]);
    fprintf(gnuplot_pipe, "e\n");
    
    idx = start;
    do {
        fprintf(gnuplot_pipe, "%f %f\n", data_x[data[idx]], data_y[data[idx]]);
        idx = next[idx];
    } while (idx != start);
    fprintf(gnuplot_pipe, "e\n");


    fprintf(gnuplot_pipe,"quit \n");
    fflush(gnuplot_pipe);//おまじない
}

void output_points(double data_x[], double data_y[], int data[], int next[], int start)
{
    int idx;
    fprintf(gnuplot_pipe,"set terminal png\n");
    fprintf(gnuplot_pipe,"set output 'points.png'\n");
    fprintf(gnuplot_pipe, "plot '-' with points lc rgb 'blue' ps 1.5 pt 7 notitle\n");

    idx = start;
    do {
        fprintf(gnuplot_pipe, "%f %f\n", data_x[data[idx]], data_y[data[idx]]);
        idx = next[idx];
    } while (idx != start);
    fprintf(gnuplot_pipe, "%f %f\n", data_x[data[start]], data_y[data[start]]);
    //fprintf(gnuplot_pipe, "e\n");

    fprintf(gnuplot_pipe,"quit \n");
    fflush(gnuplot_pipe);
}

