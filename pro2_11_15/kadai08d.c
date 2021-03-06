//課題08d 2019/11/15(FRI) 19d8104026j 可児憲太郎
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
double getLength(double x,double y){
  return sqrt((x-0.5)*(x-0.5)+(y-0.5)*(y-0.5));
}
double get_also_PI(int n){
  int i;
  int inner_point=0;
  for(i=0;i<n;i++){
    double x=(rand()+1.0)/((double)RAND_MAX+1.0);
    double y=(rand()+1.0)/((double)RAND_MAX+1.0);
    if(getLength(x,y)<0.5){
      inner_point++;
    }
  }
  return (double)inner_point/n*4;
  
}
int function(int n){
  printf("%d ",n);
  int i;
  double sum=0;
  double result[10];
  for(i=0;i<10;i++){
    double also_PI=get_also_PI(n);
    sum+=also_PI;
    result[i]=also_PI;
  }
  double ave=sum/10;
  //printf("%lf ",ave);
  double sum_=0;
  for(i=0;i<10;i++){
    sum_+=(result[i]-ave)*(result[i]-ave);
  }
  
  printf("%lf\n",sqrt(sum_/10));
  return 0;
}
int main(void){
  srand((unsigned int)time(NULL));

  int i;
  int n=1;
  for(i=0;i<6;i++){
    n*=10;
    function(n);
  }
}
    
/*
  iter      chisq       delta/lim  lambda   A             B            
   0 2.5881617618e+02   0.00e+00  2.84e+00    1.000000e+00   1.000000e+00
   1 1.9179747177e+00  -1.34e+07  2.84e-01   -4.571318e-01   5.832053e-01
   2 2.7733864884e-02  -6.82e+06  2.84e-02   -4.648599e-01   5.584316e-02
   3 2.6169602370e-02  -5.98e+03  2.84e-03   -4.563762e-01   1.905060e-02
   4 2.6169601519e-02  -3.25e-03  2.84e-04   -4.563699e-01   1.902345e-02
iter      chisq       delta/lim  lambda   A             B            

After 4 iterations the fit converged.
final sum of squares of residuals : 0.0261696
rel. change during last iteration : -3.25125e-08

degrees of freedom    (FIT_NDF)                        : 4
rms of residuals      (FIT_STDFIT) = sqrt(WSSR/ndf)    : 0.0808851
variance of residuals (reduced chisquare) = WSSR/ndf   : 0.0065424

Final set of parameters            Asymptotic Standard Error
=======================            ==========================
A               = -0.45637         +/- 0.01934      (4.237%)
B               = 0.0190235        +/- 0.0753       (395.8%)

correlation matrix of the fit parameters:
                A      B      
A               1.000 

y=10^{Alog_10(x)+B)であるから、
y=10^{-0.45637*log_10(x)+0.0190235}
である
*/
