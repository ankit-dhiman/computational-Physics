/*  Inverse of a matrix using Gauss-Jordan elimination
   Author : Ankit dhiman
   last modified : May 29 ,2020
*/



#include<iostream>
#include<iomanip>
#include<math.h>
#include<ctime>


#define SIZE 10
using namespace std ;

int main()
{
  /*      initialize random seed:          */
srand (time(NULL));


int rows  ,i,j,k ,  colms  ;

float matrix_A[SIZE][SIZE]={};
float x[SIZE] , ratio ;
//cout << setprecision(4) << fixed ;
float determinant_A = 0;


//-------------------------------------------------
//             Matrix A definition
//-------------------------------------------------
cout << setprecision(3) << fixed ;
cout << "\n\t\tInverse of a square matrix using Gauss-Jordan elimination \n\n"
     << "Enter the size of randomly generated squre matrix .\n  " ;

cin  >> rows ;  
colms = rows ;
for (int i =0;i<rows;i++)
{
  for(int j=0;j<colms;j++)
  {
    matrix_A[i][j] = rand()%5 + 1;
  }
 }

 //---------------------------------------------------------
 //      printing  matrix A
 //-------------------------------------------------



 cout << "\n       Matrix  A \t =  " ;
 for (int i = 0;i<rows;i++) {
    for(int j=0;j<colms;j++)   {
         cout  << "\t" << matrix_A[i][j] ;
   }
   cout <<"\n                      \t   " ;
 }

//-------------------------------------------------
//            Augmenting identity matrix
//-------------------------------------------------


for (int i = 0;i<rows;i++)
{
 for(int j=0;j<colms;j++)
 {
   if (i==j) {
     matrix_A[i][j+colms] = 1.0 ;
   }
   else {
     matrix_A[i][j+colms] = 0.0 ;
   }
 }
}


//---------------------------------------------------------
//      printing augmented matrix A'
//-------------------------------------------------



cout << "\n Augmented Matrix  A' \t =  " ;
for (int i = 0;i<rows;i++) {
   for(int j=0;j<colms+colms;j++)   {
     if (j>(colms -1)  && j<colms) {
       cout << "\t | \t" << matrix_A[i][j] ;}
       else if (j>(2*colms-1)) {
        cout  << "\t" << matrix_A[i][j]  ;  }
       else {
        cout  << "\t" << matrix_A[i][j] ;   }
  }
  cout <<"\n                      \t   " ;
}


//---------------------------------------------------------
//               Applying gauss jordan elimination
//-------------------------------------------------

for (i=0 ;i<rows;i++) {
 if ( matrix_A[i][i]== 0 ){
   //This matrix is not invertible.
      cout << "Mathematical Error !This matrix is not invertible.\n" ;
    exit(0) ;   }
 for (j=0;j<colms;j++) {
  if(i!=j)   {
    ratio = matrix_A[j][i]/matrix_A[i][i] ;
    for (int k= 0 ; k<2*colms ;k++ )     {
      matrix_A[j][k] = matrix_A[j][k] - ratio*matrix_A[i][k];
    }
  }
 }
}

//---------------------------------------------------------------


/* Row Operation to Make Principal Diagonal to 1 */
		 for(i=0;i<=rows;i++) 		 {
			  for(j=colms+1;j<2*colms;j++)  {
			   	matrix_A[i][j] = matrix_A[i][j]/matrix_A[i][i];
			  }
		 }



//----------------------------------------------------------------
//          display inverse of A


cout << "\n\t inv( A ) \t =  " ;
for (int i = 0;i<rows;i++)
{
 for(int j=colms;j<colms+colms;j++)
  {
     cout << "\t" << matrix_A[i][j]  ;
  }
  cout <<"\n \t \t\t  " ;
}

//-----------------------------------------------------------------------

cout << endl << endl ;
return 0 ;
}


/*//              display augmented matrix

//--------------------------------------------------------------------
*/
