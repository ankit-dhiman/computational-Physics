







#include<bits/stdc++.h>



using namespace std                                          ; 

double f(double x, double y , double z)                		 ;
double g(double x, double y , double z)                 	 ;
void   rk4(double x, double xn,double y, double h,double z)  ;                


//--------------------------------------------------------------------
double         x= 0.0 , 
               y = 3  ,                 // intial value y(0) = 3
               z = 1            ;       // initial values y'(0) = 1
double         xn = 1           ;       //final value
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
    ofstream myfile("solution.dat")                             ;
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



//-----------------------------------------------------------------------------------
/*
 * 
 *  differential equation is : 
 *   x'' + w**2(x) = 0                      .....................(1)
 *
 *  dx/dt = z = f(t, x, z)                   .....................(2)
 * 
 *  dz/dt = d/dt(dx/dt) = g(t, x, z)         .....................(3)
 *  
 *  Then  using eq 2 and eq 3 
 * 
 *   we have two first order odes as below
 *   
 *  
 */

double f(double x, double y , double z) { return z; } 
double g(double x, double y , double z) {
    return  6*y-z ;} 
    
    
    //-----------------------------------------------------------------------------------
    
