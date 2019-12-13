#ifndef GNUPLOT_H
#define GNUPLOT_H

void gnuplot_init(void);
void gnuplot_cleanup(void);
void gnuplot_draw_points(double data_x[], double data_y[], int data[],int next[], int start);
void gnuplot_draw_polygon(double data_x[], double data_y[], int data[],int next[], int start);
void gnuplot_sleep(double sec);
void output_by_gnuplot_12_4(double data_x[], double data_y[], int data[],int next[], int start);
void output_points(double data_x[], double data_y[], int data[],int next[], int start);
#endif
