/*
Author : Ankit Dhiman 
date created : 11 June,2020
*/


#include <bits/stdc++.h> 

#define SIZE 20
using namespace std ;

void PrintMatrix(complex<double> Arr[][SIZE], int n) ;
void PrintMatrixConj(complex<double> Arr[][SIZE], int n) ;

int main()
{
  /* initialize random seed: */
  srand (time(NULL));
int a=-10 , b=20 , alpha ,beta ,n  ;
cout << "\nGive value for size of the matrix , n : 	\n? " ; 
cin  >> n   ;

//-------------------------------------------------
// INTIALIZE MATRICES A AND TRANSPOSE TO zero
//-------------------------------------------------


complex<double> matrix_A[SIZE][SIZE]={};
complex<double> matrix_transpose[SIZE][SIZE]={};
complex<double> conjugate_A[SIZE][SIZE]={};



//-------------------------------------------------
// INTIALIZING  MATRICES A TO SOME RANDOM VALUES
//-------------------------------------------------

for (int i = 0;i<n;i++){
  for(int j=0;j<n;j++){      
    
    alpha  = a + ( rand() %b )   ;
    beta   = a + ( rand() %b )   ;
    complex<double> z1(alpha,beta);
    matrix_A[i][j] = (z1) ;
  
  } }


cout << "\n matrix   (A) =  \n \t" ;
PrintMatrix(matrix_A,n) ;
cout << "\n conjugate(A) =  \n\t " ;
PrintMatrixConj(matrix_A,n) ;

cout << "\n\n" ;
return 0 ;
}


//-------------------------------------------------

void PrintMatrix(complex<double> Arr[][SIZE], int n) 
{ for (int i = 0;i<n;i++){
  for(int j=0;j<n;j++) {
  cout  <<setw(12)<< Arr[i][j] ;
 }
 cout << "\n     \t "  ;
}
    return; 
}

//-------------------------------------------------


void PrintMatrixConj(complex<double> Arr[][SIZE], int n) 
{ for (int i = 0;i<n;i++){
  for(int j=0;j<n;j++) {
  cout  <<setw(12)<< conj(Arr[i][j])  ;
 }
 cout << "\n     \t "  ;
}
    return; 
}


//-------------------------------------------------
 

