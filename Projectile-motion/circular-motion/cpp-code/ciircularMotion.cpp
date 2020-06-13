//...........................................................................
//      C I R C U L A R         M O T I O N
//...........................................................................



//  x(t)=x0 + R cos (ω(t − t0))
//  y(t)=y0 + R sin (ω(t − t0)) 
//  vx(t) = −ωR sin (ω(t − t0 ))
//  vy(t) = ωR cos (ω(t − t0)) 


#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<string>



using namespace std ;
#define pi  3.1415926535897932



int main () 

{
double X0, Y0 , R , x , y , Vx , Vy , T , T0 , Tf , dT ;
double theta , omega                                         ;

    cout <<"-----------------------------------------------------------------\n"
         <<"             M O T I O N      I N         A       P L A N E\n"
         <<"------------------------------------------------------------------\n\n"
         <<"Enter initial values for x and y coordinates (Xi,Yi),radius R, T0 , Tf , time increment dT ,angular velocity ,w :     followed by <return> \n" ;
         
    cin  >> X0 >> Y0 >> R >> T0 >> Tf >> dT >> omega ;
    
    cout << "\n # T =   " << (2.0*pi)/omega << endl ;
   
    ofstream myfile("circle.dat") ;
    myfile.precision(17) ;
    
   
    T = T0                                  ;
    while (T<=Tf)
    {
        
    theta =  omega*(T-T0)                   ;
     x    =  X0 + R*cos(theta)              ;
     y    =  Y0 + R*sin(theta)              ;
     Vx   =  -(omega*R*sin(theta))             ;
     Vy   =  omega*R*cos(theta)             ;
     myfile << T << " " << x << " " << y << " " << Vx << " " << Vy << endl ;    
     T = T + dT                             ;     
    }    
         
}         
