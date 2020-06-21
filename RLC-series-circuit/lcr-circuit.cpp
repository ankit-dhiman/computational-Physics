
//-----------------------------------------------------------------------------------
/* Problem description
 * Find the charge on the capacitor in an RLC series circuit where L = 5/3 H, R = 10Ω , C = 1/30 F, and E(t) = 300 
 * V. Assume the initial charge on the capacitor is 0 C and the initial current is 9 A. What happens to the charge 
 * on the capacitor over time?
*/

#include<bits/stdc++.h>



using namespace std                                          ; 

double f(double t, double q , double z)                		 ;
double g(double t, double q , double z)                 	 ;
void   rk4(double t, double tn,double q, double h,double z)  ;                


//--------------------------------------------------------------------
double         t= 0.0 , 
               q = 0  ,                 // 
               z = 9            ;       // initial charge on the capacitor is 0 C 
double         tn = 5           ;       //and the initial current is 9 A
double         h = 0.001        ;
int         steps = int((tn)/h) ;

int main() 
{     
    rk4(t,tn,q,h,z)             ; 
    return 0					; 
} 

//-------------------------------------------------------------------


void rk4(double t, double tn,double q, double h,double z) 
{   
    ofstream myfile("solution.dat")                             ;
    cout <<   myfile.precision(10) << fixed			            ;
    myfile <<"#t(seconds)"<<setw(20) <<"q(columbs)" <<setw(20) << "i (Amperes)" << "\n"    	;
   for(int i=0;i<steps;i++)
    { 
        
        double k1 = h*f(t,q,z)				              	;
        double l1 = h*g(t,q,z)					            ;
        double k2 = h*f( t+0.5*h, q+0.5*k1, z+0.5*l1  )		;
        double l2 = h*g( t+0.5*h, q+0.5*k1, z+0.5*l1  ) 	;
        double k3 = h*f( t+0.5*h, q+0.5*k2, z+0.5*l2 )		;
        double l3 = h*g( t+0.5*h, q+0.5*k2, z+0.5*l2 )		;
        double k4 = h*f( t+h, q+k3,z+l3)			        ;
        double l4 = h*g( t+h, q+k3,z+l3)			        ;
        double q1 = q + (k1+2*k2+2*k3+k4)/6.0			        ;
        double z1 = z + (l1+2*l2+2*l3+l4)/6.0			      ;
        double t1 = t + h        	                        ; 
        
        myfile << t1 <<  setw(20) <<  q1 <<setw(20) <<z1 <<"\n" ;
        t = t1                                          	;	 
        q = q1                                          	; 
        z = z1                                          	;
        
    }
} 

 
//-----------------------------------------------------------------------------------
/*
 *  di/dt = z = f(t, q, z)                   .....................(1)
 *  dz/dt = d/dt(di/dt) = g(t, q, z)         .....................(2)
 *  
 *  differential equation is : 
 *   Lq''(t) + Rq'(t) + q(t)/C =   E(t)
 *  
 *   L  = 5/3  H
 *   R  = 10  Ohm
 *   C  = 1/30 F
 *  E(t)= 300
 *   we have two first order odes as below
 *   
 *   dq/dt  =  z  = f(t, q,, z)
 *   dz/dt  = g(t,q,z)  
 */

double f(double t, double q, double z) { return z; } 
double g(double t, double q, double z) {
return  180 -18*q-6*z   ;} 


//-----------------------------------------------------------------------------------
