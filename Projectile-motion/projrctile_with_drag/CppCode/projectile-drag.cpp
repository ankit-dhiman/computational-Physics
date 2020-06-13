// ......................................................................................................//
// Study of projectile motion:
// User will enter the values for launch speed and launch angle at t = 0 seconds.
// Generalized case of projectile motion
// The body is assumed to be spherical in shape .
// Air resistance is considered
// c = 0.47
// Vtermianl = m*g/c
//........................................................................................................//




#include<iostream>
#include<cmath>
#include<fstream>
#include<string>

using namespace std                                         ;

int main() 

{

double  Vi,Vx,Vy,x_distance,y_distance,t,Tf,ft,Range,MaxHieght,theta_rad  ,Vterm ,Vt   ;
const double g = 9.81                                       ;
double pi = 3.14159265                                      ;
const float  c = 0.47 , m = 50                              ;
const int launch_angle = 45                                 ;
 
 
 



cout     << "            P R O J E C T I L E         M O T I O N        P A R T  II    (WITH AIR DRAG)         \n "
         << "\t*************************************************************************************   "
         << endl
         << endl;
         
cout << "\n A spherical body having mass  " << m << " kg " << "  is projected with the launch angle of  " << launch_angle << " degrees . \n " ;   
            
         
         
         //   cout  <<" Give Initial velocity  (ms)   :      "         ;
//   cin   >> Vi                                              ;
//   cout  << " Give launch angle  (degrees) :      "         ;
//   cin   >> launch_angle                                    ;   
 
/*   if((launch_angle>90)||(launch_angle<=0)||(Vi<0)){
    cout << "illegal input \n ! "                           ;
    exit(1)                                                 ;
    }
*/   

   Vterm    = m*g/c                                                ;
   theta_rad = (launch_angle*pi)/180                               ;
   ofstream myfile("drag45.dat")                                   ;      
   myfile.precision(10)                                            ;
   
   x_distance = 0.0                                                ;
   y_distance = 0.0                                                ;         
  
   for(Vi = 25 ;Vi<225; Vi+=25)
   {
       Tf = (2*Vi*sin(theta_rad))/g                                    ;
       for(t=0;t<Tf;t=t+0.1)
    {
        ft = -((g*t)/Vterm)   ;
        Vx=Vi*cos(theta_rad)*exp(ft)                              ;   
        Vy=Vi*sin(theta_rad)*exp(ft)-(Vterm*(1-exp(ft)))          ;
        Vt=sqrt(Vx*Vx+Vy*Vy)                                      ;
        x_distance = (Vi*Vterm*cos(theta_rad)*(1-exp(ft)))/g      ;
        y_distance = (Vterm*(Vi*sin(theta_rad)+Vterm)*(1-exp(ft)))/g-(Vterm*t)                                      ;
        myfile << t << " " << x_distance << " " << y_distance << " " << Vt  << "\n"                                          ;
     }
    
    myfile << "\n\n" << "# Initial Velocity :    "<<Vi<< " meters per second ." << " \n"                                                      ;
   }     
  
   
}
     

     
 
