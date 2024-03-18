#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define lp 100

double c_od,c_do;

double f3(double x)
{
 return -1;      
}      
double f4(double x) {

 return 1;
}


double rand_float(double x, double y){
       double d;
       d = (double)rand()/RAND_MAX;
       d = d*(y-x) + x;
       return d;
};


double prostokaty(double( *f)(double))
{
       double krok=(c_do-c_od)/lp, sum=0, pos;

       for(pos=c_od+krok/2; pos<=c_do; pos+=krok){
              sum += f(pos);
       }
       sum *= krok;
       
return sum;
}

double trapezy(double (*f)(double))
{
       double krok=(c_do-c_od)/lp, sum=0, stop=c_do-krok, pos;

       for(pos=c_od+krok; pos<=stop; pos+=krok){
              sum += f(pos);
       }
       sum += (f(c_od) + f(c_do)) / 2;
       sum *= krok;

return sum;
}

double mc(double(*f)(double)){
       double sum, x, y, pos, krok, pole, target, max, min;
       krok = (c_do-c_od)/lp;
       target = 0;
       max = 0;
       min = 0;

       for(pos=c_od; pos<=c_do; pos+=krok){
              if( f(pos) > max ){
                     max = f(pos);
              }
              else if( f(pos) < min ){
                     min = f(pos);
              }
       }

       pole = (max-min)*(c_do-c_od);

       for(int try=0; try<=lp; try++){
              x = rand_float(c_od, c_do);
              y = rand_float(min, max);

              if( y >= 0 && f(x) >= y ){
                     ++target;
              }
              else if (f(x) <= y){
                     ++target;
              }
              
       }
}
