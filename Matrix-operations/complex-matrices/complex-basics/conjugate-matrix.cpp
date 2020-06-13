/*
Author : Ankit Dhiman 
date created : 11 June,2020
*/


#include<iostream>
#include<iomanip>
#include<cmath>				// pow()
#include<time.h>			// for system time
#include<complex>			// for complex numbers
#include<cstdlib>			// includes def of RAND_MAX


using namespace std ;

int main()
{
  /* initialize random seed: */
  srand (time(NULL));
  
int a=-10 , b=20 , real_part , img_part ,n = 3 ;


//-------------------------------------------------
// INTIALIZE MATRICES A AND TRANSPOSE TO zero
//-------------------------------------------------


complex<double> matrix_A[10][10]={};
complex<double> matrix_transpose[10][10]={};
complex<double> conjugate_A[10][10]={};



//-------------------------------------------------
// INTIALIZING  MATRICES A TO SOME RANDOM VALUES
//-------------------------------------------------

for (int i = 0;i<=n;i++){
  for(int j=0;j<=n;j++){      
    
    real_part  = a + ( rand() %b )   ;
    img_part   = a + ( rand() %b )   ;
    complex<double> z1(real_part , img_part);
    matrix_A[i][j] = imag(z1) ;
  
  } }


//-------------------------------------------------
//  COMPUTING CONJUGATE T  OF MATRIX A
//-------------------------------------------------



for (int i = 0;i<=n;i++){
  for(int j=0;j<=n;j++) {
   if(imag(z1)!= 0) {
   conjugate_A[i][j] = -imag(matrix_A[i][j]);
 }
  else {conjugate_A[i][j]= imag(matrix_A[i][j] ;
  }}}

//-------------------------------------------------
//OUTPUT OF A , A^t
//-------------------------------------------------


cout << "\n matrix   (A) =  \n \t" ;

for (int i = 0;i<=n;i++){
  for(int j=0;j<=n;j++) {
  cout  <<setw(12)<< matrix_A[i][j] ;
 }
 cout << "\n     \t "  ;
}

//--------------------------------------------------

cout << "\n conj_trans(A) =  \n\t " ;

for (int i = 0;i<=n;i++){
  for(int j=0;j<=n;j++) {
  cout  <<setw(12) << conjugate_A[i][j];
 }
 cout << "\n      \t ";
}

cout << "\n\n" ;
return 0 ;
}


