/*
    Runge-Kutta 4th order method is a numerical technique used to solve ordinary differential
    equation of the form
    dy/dx = f(x,y)   , y(xo) = yo
    So only first order ordinary differential equations can be solved by using the Runge-Kutta 4th
    order method.
    user can enter differential equation to be solved in f(x,y) function, and set the desired
    value of step size  h, which is defined as  h = x (i+1) - x (i)


    In this example differential equation  solved is :
        dy/dx  =  f(x,y)  = 1 + y^2 
        with known  solution  y = tan(x) . 

    Author : Ankit Dhiman
        
*/











//-------------------------------------------------------------------------------------------------//-------------------------------------------------------------------------------------------------



#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>

using namespace std                                             ; 


const double  pi = 3.14159265359                                ;
double         x = 0.0 , y = 0.0                                ;    
double        xn = 0.9*pi*0.5                               ; 
double         h = 0.0001                                       ;
    

double   f(double x, double y)                         ;
void     result(double x, double xn,double y, double h)         ;
double   rk4(double x, double y, double h)                    ;



//-------------------------------------------------------------------------------------------------
//        start of main function
//-------------------------------------------------------------------------------------------------
 

int main() 
{ 
   
   // ofstream myfile("solution.dat")                              ;
   // myfile<<  y<<  "\t" << x << endl                             ; 
    result(x, xn, y, h)                                          ; 
      
    return 0; 

    
} 




//-------------------------------------------------------------------------------------------------
// function which directs the x and y values to data file solution.dat.
//-------------------------------------------------------------------------------------------------



void result(double x, double xn,double y, double h) 
{   const double pi = 3.14159265;
    ofstream myfile("solution.dat")                              ;
	while (x <=xn) { 
		double x1 = x + h                                        ; 
		double y1 = rk4(x, y, h)                               ;     
                x = x1                                           ; 
                y = y1                                           ; 
	  
        myfile << setprecision(10)<<  x <<  "\t" << setprecision(10) << y << "\t"<< setprecision(10)<< tan(x)<< endl                         ; 
    }

 
	} 


	
	
//-------------------------------------------------------------------------------------------------
// fucntion which calculates y after each iteration using fourth order runge kutta method
//-------------------------------------------------------------------------------------------------





double rk4(double x, double y, double h) 
{ 
  double   k1 = f(x,y)                                                     ; 
  double   k2 = f( x +(h*0.5) ,y + k1*0.5*h )                              ;
  double   k3 = f(x + (h*0.5), y + k2*h*0.5 )                              ;
  double   k4 = f(x + (h)    , y + k3*h     )                              ;
    
	 double y1 = y + h*(k1 + 2.*k2 +2.*k3 +k4)/6.; 
	return y1; 
} 






//-------------------------------------------------------------------------------------------------
// function to define the differential equation to be solved
//-------------------------------------------------------------------------------------------------


double f(double x, double y) 
{ 
	double yp = 1+y*y    ;                 //              dy/dx = 1 + y*y 
	return yp; 
} 


//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------














