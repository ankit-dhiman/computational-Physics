
/*   
 *               Study of projectile motion with neglible air resistance 
********************************************************************************************* 
 * 
 *  User will enter the values for launch speed and launch angle at t = 0 seconds.
 *  Program will give final Range, max height achieved by projectile,total time of flight and more 
 *  Air resistance is Neglected in this model.
 * 
 * Author : Ankit Dhiman
 * Last Modified : 1 june, 2020
 * 
 */

 


#include<iostream>
#include<cmath>
#include<fstream>
#include<string>

using namespace std ;

int main() 

{

double  Vi,Vx,Vy,x_distance,y_distance,t,Tf,Range,MaxHieght,launch_angle,theta_rad  ,Hieghtt2  ,  V_final   ;
const double g = 9.81    ;
double pi = 3.14159265  ;

    cout << "            \t\t   P R O J E C T I L E         M O T I O N       \n  "
         << "           \t------------------------------------------------------------------   "
         << endl
         << endl 
         << " Give Initial velocity Vi (m/s)  "     ;
   cin   >> Vi                         ;
   
   cout<< "\nLaunch speed                            :   " << float(Vi)        <<     "\t meters per second.\n" ;
   if(Vi<0){
    cout << "illegal input \n ! "                    ;
    exit(1)                                          ;
    }
   

   ofstream myfile("ideal_1.dat")          ;  
   myfile.precision(10)                             ;
   
  
   x_distance = 0.0                                 ;
   y_distance = 0.0                                 ;      
   launch_angle = 15.0;
   
  for(launch_angle = 15.0 ; launch_angle<=90.0; launch_angle+=15.0) 
  {
      
      theta_rad = (launch_angle*pi)/180                ; 
      Tf = (2*Vi*sin(theta_rad))/g                     ;   
      for(t=0;t<=Tf;t=t+0.05)
      {
        Vx=Vi*cos(theta_rad)                             ;   
        Vy=Vi*sin(theta_rad)-(g*t)                       ;
        x_distance = Vi*cos(theta_rad)*t                 ;
        y_distance = (Vi*sin(theta_rad))*t-(0.5*g*t*t)     ;
        V_final = sqrt(Vx*Vx + Vy*Vy)                    ;
        myfile << t << " " << x_distance << " "  << y_distance << "\n"                             ;
    }
        
    myfile << "\n\n"<< "# launch angle :    "<<launch_angle<<"\n";
    

   
   cout << "\n\nLaunch angle                            :   " << float(launch_angle)        <<     "\t degrees.\n"
        << "Time of flight                          :   " << Tf        <<     "\t seconds. \n"
        << "Range of Projectile                     :   " << x_distance     <<     "\t meters . \n"
        << "final velocity                          :   " << V_final   <<      "\t meters per seconds .";
        
     }

} 
     
  
