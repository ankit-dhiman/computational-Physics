
/*
 *We have learned Euler's and Runge-Kutta methods to solve first order differential equations 
 *of the form :
 *          dy/dx = f(x,y) ,y(0) = yo 
 *
 * to solve simultaneous (coupled) differential equations, or differential
 * equations that are higher than first order, we will write them as set of first order differential 
 * equations and solve them using either Euler's method or Runge-Kutta method.For example an n th order *differential equation.
 * 
 *
 */


//-----------------------------------------------------------------------------------


/*  In this code , we will take the following second order differential equation as  
 * f(x,y)      =    d^2 y/ dt^ 2  + 2.dy/dt + 5.y = exp(-t)    , y(0) = 1  and y'(0) = 2
 * 
 * we will solve it using Euler's method and later Runge-kutta 4 th order method.
 * The ordinary diff eqn would be written as follows. Assume
 *      dy/dt      =   z   .
 * then:
 *      d^2y/dt^2  =  dz/dt   
 * substitute these values in above differential eqns and on rearrangment,we obtain:
 *  dz/dt +2.z +y = exp(-t) ;
 *  dz/dt  =  exp(-t) - 2z - y.
 * 
 * 
 * So the two simultaneous first order differential equations are  
      
 *       Author : Ankit Dhiman
 */
 //-----------------------------------------------------------------------------------







//                      START  OF  MAIN  PROGRAM
//----------------------------------------------------------------------------------


#include<bits/stdc++.h>


//----------------------------------------------------------------------------------

using namespace std                                           ; 


double yt(double t, double y , double z)                      ;
double zt(double t, double y , double z)                      ;
double eulerFirst(double t, double y, double h,double z)      ;
double eulerSecond(double t, double y, double h,double z)     ;
void   result(double t, double tn,double y, double h,double z)         ;
                    



//-----------------------------------------------------------------------------------
 

int main() 
{ 
   double         t= 0.0 , y = 1.0 ,z =1.0                     ;    
   double        tn = 1.0	                                ; 
   double         h = 0.000100                                    ;
   int 	      steps  = (tn - t) / h				;
   result(t, tn, y, h,z)                                        ; 
   return 0; 

    
} 

//-----------------------------------------------------------------------------------



void result(double t, double tn,double y, double h,double z) 
{   const double pi = 3.14159265;
    ofstream myfile("solution.dat")                      ;
	while (t <=tn)
	{ 
	double t1 = t + h                                ; 
	double y1 = eulerFirst(t, y, h,z)                ;     
        double z1 = eulerSecond(t, y, h,z)               ;     
        t = t1                                           ; 
        y = y1                                           ; 
        z = z1                                           ;
	myfile << setprecision(10)<<  t <<  "\t" 
	       << setprecision(10) << y << "\t"
	       << setprecision(10)<< z << endl           ; 
        }
    
        cout << "\n The value of y at t  =   " << t <<" is " <<setw(10) <<y <<endl<<endl ;

} 


//-----------------------------------------------------------------------------------


double eulerFirst(double t, double y, double h,double z) 
{ 
	// value of next y(predicted) is returned 
	double y1 = y + h * yt(t, y,z); 
	return y1; 
} 



//-----------------------------------------------------------------------------------

double eulerSecond(double t, double y, double h,double z) 
{ 
	// value of next y(predicted) is returned 
	double z1 = z + h * yt(t, y,z); 
	return z1; 
} 



//-----------------------------------------------------------------------------------


double yt(double t, double y, double z) 
{   //y'(t) = z 
	double ypt = z    ; 
	return ypt; 
} 


//-----------------------------------------------------------------------------------


double zt(double t, double y, double z) 
{    //z'(t)
	double ztp =  exp(t)   ; 
	return ztp; 
} 


//-----------------------------------------------------------------------------------










