/*
  Author        : Ankit Dhiman
  Last Modified : 1 june, 2020

  This program solves first ordinary differential equations using Euler's Method
  Functions are used to keep the program short.

*/



#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>

using namespace std                                           ;


double f(double x, double y)                                  ;
void result(double x, double xn,double y, double h)           ;
double euler(double x, double y, double h)                    ;


//--------------------------------------------------------------------------------------------------------
const double  pi = 3.14159265                                ;
double         x = 0.0 , y = 0.0                             ;
double        xn = 0.99999*pi*0.5                            ;
double         h = 0.001000000000                            ;

int main(){

 // ofstream myfile("solution.dat")                            ;
 // myfile<<  y<<  "\t" << x << endl                           ;
  result(x, xn, y, h)                                          ;
  return 0;
}

//---------------------------------------------------------------------------------------------------



void result(double x, double xn,double y, double h)
{ ofstream myfile("solution.dat")                              ;
	while (x <=xn) {
		double x1 = x + h                                        ;
		double y1 = euler(x, y, h)                               ;
                x = x1                                           ;
                y = y1                                           ;

        myfile << setprecision(10)<<  x <<  "\t" << setprecision(10) << y << "\t"<< setprecision(10)<< tan(x)<< endl                         ;
  }	}


//----------------------------------------------------------------------------------------------------


double euler(double x, double y, double h)
{
	// value of next y(predicted) is returned
	double y1 = y + h * f(x, y);
	return y1;
}



//----------------------------------------------------------------------------------------------------


double f(double x, double y)
{
	double yp = 1+y*y    ;
	return yp;
}


//-----------------------------------------------------------------------------------------------------
