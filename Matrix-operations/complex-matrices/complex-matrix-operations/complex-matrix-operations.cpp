/*
Author : Ankit Dhiman 
date created : 11 June,2020
*/



#include<bits/stdc++.h>

using namespace std					 ;
#define SIZE 10

void PrintMatrix(complex<double> Arr[][SIZE], int n)     ;
void PrintAdjoint(complex<double> Arr[][SIZE], int n) 	 ;
void PrintTrace(complex<double> Arr[][SIZE], int n)	 ; 

int main()
{  
srand (time(NULL))					;
int 	a=-10 	  					,
	b=20  	  					,
	real_part 					,
	img_part  					,
	n = 2	  					;


// INTIALIZE MATRICES A AND TRANSPOSE TO zero
complex<double> matrix_A[SIZE][SIZE]={}			, 
		matrix_transpose[SIZE][SIZE]={}		,
		conjugate_transpose[SIZE][SIZE]={}	;


// INTIALIZING  MATRICES A TO SOME RANDOM VALUES
for (int i = 1;i<=n;i++){
  for(int j=1;j<=n;j++){      
    
    real_part  = a + ( rand() %b ) 		        ;
    img_part   = a + ( rand() %b )   		        ;
    complex<double> z1(real_part , img_part)	        ;
    matrix_A[i-1][j-1] = z1 				;
  
  } }

//  COMPUTING TRANSPOSE  OF MATRIX A



for (int i = 1;i<=n;i++){
  for(int j=1;j<=n;j++) {
   matrix_transpose[j-1][i-1] = matrix_A[i-1][j-1]	;
 }}

//-------------------------------------------------

cout << "\n   (A)	    =  \n \t"   		;
PrintMatrix(matrix_A,n) 				;
PrintTrace(matrix_A,n) 					;
cout << "\n Transpose (A)   =  \n \t"   		;
PrintMatrix(matrix_transpose,n)  			;
PrintAdjoint(matrix_transpose,n) 			;


cout << "\n\n" 						;


return 0 						;

}





//-------------------------------------------------
//-------------------------------------------------





void PrintMatrix(complex<double> Arr[][SIZE], int n) 
{ 
  for (int i = 0;i<n;i++){
  for(int j=0;j<n;j++) {
  cout  <<setw(12)<< Arr[i][j] 				;
 }
 cout << "\n     \t "  					;
}
    return						; 
}

//-------------------------------------------------


void PrintAdjoint(complex<double> Arr[][SIZE], int n) 
{cout << "\n Adjoint (A)    =  \n \t" 			;
 for (int i = 0;i<n;i++){
  for(int j=0;j<n;j++) {
  cout  <<setw(12)<< conj(Arr[i][j])  			;
 }
 cout << "\n     \t "  					;
}
    return						; 
}

//-------------------------------------------------


void PrintTrace(complex<double> Arr[][SIZE], int n) 
{  complex<double> trace ;
  for (int i = 0;i<n;i++){
  for(int j=0;j<n;j++) {
  if(i==j){
    trace +=Arr[i][j]  					;
 }}}
 cout << "\n Trace =\t " << trace  			;
    return; 
}



