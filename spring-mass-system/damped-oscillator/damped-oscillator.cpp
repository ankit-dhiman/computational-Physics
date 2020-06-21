





#include<bits/stdc++.h>
# define PI 3.1415926536                                    ;


using namespace std                                          ; 

double f(double x, double y , double z)                		 ;
double g(double x, double y , double z)                 	 ;
void   rk4(double x, double xn,double y, double h,double z)  ;                


//--------------------------------------------------------------------
double         x= 0.0 , 
               y = 2 ,                 // intial value y(0) = 3
               z = 0          ;       // initial values y'(0) = 1
double         xn = 10           ;       //final value
double         h = 0.001        ;
int         steps = int((xn)/h) ;

int main() 
{     
    rk4(x,xn,y,h,z)             ; 
    return 0					; 
} 

//-------------------------------------------------------------------


void rk4(double x, double xn,double y, double h,double z) 
{   
    ofstream myfile("solution2.dat")                             ;
    cout <<   myfile.precision(10) << fixed			            ;
    myfile <<"#x"<<setw(25) <<"y" <<setw(25) << "z" << "\n"    	;
   for(int i=0;i<steps;i++)
    { 
        
        double k1 = h*f(x,y,z)				              	;
        double l1 = h*g(x,y,z)					            ;
        double k2 = h*f( x+0.5*h, y+0.5*k1, z+0.5*l1  )		;
        double l2 = h*g( x+0.5*h, y+0.5*k1, z+0.5*l1  ) 	;
        double k3 = h*f( x+0.5*h, y+0.5*k2, z+0.5*l2 )		;
        double l3 = h*g( x+0.5*h, y+0.5*k2, z+0.5*l2 )		;
        double k4 = h*f( x+h, y+k3,z+l3)			        ;
        double l4 = h*g( x+h, y+k3,z+l3)			        ;
        double y1 = y + (k1+2*k2+2*k3+k4)/6.0			        ;
        double z1 = z + (l1+2*l2+2*l3+l4)/6.0			      ;
        double x1 = x + h        	                        ; 
        
        myfile << x1 <<  setw(25) <<  y1 <<setw(25) <<z1 <<"\n" ;
        x = x1                                          	;	 
        y = y1                                          	; 
        z = z1                                          	;
        
    }
} 

//-----------------------------------------------------------------------------------



//-------------                 CASE   1                    ------------------------
//                          Overdamped case
/*
 *   A 2-kg mass is attached to a spring with spring constant 24 N/m. The system is then immersed in a medium imparting a damping force equal to 16 times the instantaneous velocity of the mass. Find the equation of motion if it is released from rest at a point 40 cm below equilibrium.

 *  differential equation is : 
 *   mx''+bx'+kx=0.                            .....................(1)
 * 
 *   2x'' +26x' + 24x = 0
 *  m = 2
 *  b = 16
 *  k = 24
 *  
 *  b**2 = 25  
 *  4*m*k =24
 *  dx/dt = z = f(t, x, z)                   .....................(2)
 * 
 *  dz/dt = d/dt(dx/dt) = g(t, x, z)         .....................(3)
 *  
 *  Then  using eq 2 and eq 3 
 * 
 *   we have two first order odes as below
 *   
 *


double f(double x, double y , double z) { return z; } 
double g(double x, double y , double z) {
    return   -12*y-13*z ;} 
 */  
    
 
//-----------------------------------------------------------------------------------
    
//-------------                 CASE   2                    ------------------------
//                         critically damped  case
/*
 * A 1-kg mass stretches a spring 20 cm. The system is attached to a dashpot that imparts a damping force equal     to 14 times the   instantaneous velocity of the mass. Find the equation of motion if the mass is released from equilibrium with an upward velocity of 3 m/sec.

 *  differential equation is : 
 *   mx''+bx'+kx=0.                            .....................(1)
 * 
 *   x'' +5x' + 6x = 0
 *  m = 2
 *  b = 5
 *  k = 6
 *  
 *  b**2 = 25  
 *  4*m*k =24
 *  dx/dt = z = f(t, x, z)                   .....................(2)
 * 
 *  dz/dt = d/dt(dx/dt) = g(t, x, z)         .....................(3)
 *  
 *  Then  using eq 2 and eq 3 
 * 
 *   we have two first order odes as below
 *   
 *  
 *
 *
double f(double x, double y , double z) { return z; } 
double g(double x, double y , double z) {
    return   -49*y - 14*z ;} 
      */ 



//-------------                 CASE   3                    ------------------------
//                         under damped  case
/*
 * A 1-kg mass stretches a spring 49 cm. The system is immersed in a medium that imparts a damping force equal to four times the
 instantaneous velocity of the mass. Find the equation of motion if the mass is released from rest at a point 24 cm above equilibrium.


 *  differential equation is : 
 *   mx''+bx'+kx=0.                            .....................(1)
 * 
 *   x'' +4x' + 200x = 0
 *  m = 1
 *  b = 4
 *  k = 200
 *  
 *  b**2 = 16
 *  4*m*k =800
 *  dx/dt = z = f(t, x, z)                   .....................(2)
 * 
 *  dz/dt = d/dt(dx/dt) = g(t, x, z)         .....................(3)
 *  
 *  Then  using eq 2 and eq 3 
 * 
 *   we have two first order odes as below
 *   
 *  
 *
 */ 

double f(double x, double y , double z) { return z; } 
double g(double x, double y , double z) {
    return   -200*y - 4*z ;} 
