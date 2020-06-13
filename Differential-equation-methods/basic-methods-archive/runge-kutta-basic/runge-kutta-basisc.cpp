//  RUNGE KUTTA METHOD 
//  SOLN OF DIFF EQN USING RUNGE-KUTTA (RK4) METHOD

#include<iostream>
#include<cmath>
#include<fstream>

using namespace std ;

int main()
{
   double x,y,t,h,f,a,b ,xo,yo,f1,f2,f3,f4,fo;
   const double e = 2.7182818285 ;
   int   n , k = 1                     ;
   cout << "\n\tRUNGE KUTTA (RK4) NUMERICAL SOLUTION FOR DIFFERENTIAL EQUATIONS\n\t*********************************************************\n"   ;
   cout << " *************************************************************************\n \t"
        << endl 
        << endl
        << " FORMULA   :      y ( x + h ) = y ( x ) + ( F_1 + 2 F_2 + 2 F_3 + F_4 )/6  \n"
        << "\n Let's say ,We have the following differential equation  :  \n "
        << "\t    dy/dx  = - k*x. \n "
        << "With initial condition  y ( 0 )  =  1 . \n"
        << "\nGive step size , h :    ? \n"                  ;
    
  cin  >>   h                                                ;     
  xo   =    0.0000000                                        ;
  yo   =    0.0000000                                        ;
  n    =    20                                               ;
  a    =    xo                                               ;
  b    =    a + n*h                                          ;
  x    =    xo                                               ;
  y    =   yo                                                ;                        
  fo   =   -x                         ;
  f    =   fo                                                ;
  ofstream myfile("runge2.dat ")                             ;
  myfile.precision(15)                                       ;
  myfile << "" << x << "   " << y << "   " << h*f << "   " << x + h/2 << "  " << "\n" ;
     
   for(t=a ;t<=1;t=t+h)
   {
     f = (5*x*x-y)/exp(x+y)         ;
     f1 = h*f                       ;
     f2 = h*((5*(x+ (h/2))*(x + (h/2)))-y)/(exp(x+h/2 + (y+f1/2)))  ;
     f3 = h*(5*(x+h/2)*(x+h/2)-y)/(exp(x+h/2 + (y+f2/2)))  ;
     f4 = h*(5*(x+h)*(x+h)-y)/(exp(x+h + (y+f3/2)))  ;
     y = y + (f1 +2*f2 + 2*f3 +f4)/6                ;
     x = x + h                  ;
     myfile << "" << x << "   " << y << "   " << f1 << "   " << x + h/2 << "  " << "\n" ;
     
   }
   
   }  
