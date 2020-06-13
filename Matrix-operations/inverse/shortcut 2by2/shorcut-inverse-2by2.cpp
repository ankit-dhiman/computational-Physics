
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


//-------------------------------------------------

int  i,j,k;
int n = 2 ;
float temp1 ,temp2 ;

cout << setprecision(3) << setw(10) ;
float matrix_A[SIZE][SIZE]={};
float matrix_B[SIZE][SIZE]={};
float matrix_I[SIZE][SIZE]={};
float sum = 0;

float determinant_A = 0;
cout << "\n ********** Shortcut to find inverse of a second order matrix **************\n";

//-------------------------------------------------
//             Matrix A definition


for (int i =0;i<n;i++)
{
  for(int j=0;j<n;j++)
  {
    matrix_A[i][j] = rand()%9 + 1;
  }
 }

 //---------------------------------------------------------
 //      printing  matrix A

 cout << "\n       Matrix  A \t =  " ;
 for (int i = 0;i<n;i++) {
    for(int j=0;j<n;j++)   {

         cout  << "\t" << matrix_A[i][j] ;
   }
   cout <<"\n                      \t   " ;
 }


 determinant_A = matrix_A[0][0]*matrix_A[1][1]-matrix_A[0][1]*matrix_A[1][0] ;
temp1 = matrix_A[0][0] ;
matrix_B[0][0] = matrix_A[1][1] ;
matrix_B[1][1] = temp1 ;



//----------------------------------------------------------------
//          display inverse of A

cout << "\n\nSwitch the elements on the main diagonal ";
cout << "\n       Matrix  A \t =  " ;
for (int i = 0;i<n;i++)
{
 for(int j=0 ;j<n;j++)
  {
     cout << "\t" << matrix_A[i][j]  ;
  }
  cout <<"\n \t \t\t  " ;
}

matrix_B[0][1] = -1*matrix_A[0][1];
matrix_B[1][0] = -1*matrix_A[1][0];
//----------------------------------------------------------------
//          display inverse of A

cout << "\n\ntake the opposite of the other two elements " ;
cout << "\n       Matrix  A \t =  " ;
for (int i = 0;i<n;i++)
{
 for(int j=0 ;j<n;j++)
  {
     cout << "\t" << matrix_A[i][j]  ;
  }
  cout <<"\n \t \t\t  " ;
}

//-----------------------------------------------------------------------
cout << "\n\nDivide all the values by the determinant of the matrix " ;

for(i=0;i<n;i++){for (j=0;j<n;j++){
  matrix_B[i][j]/=determinant_A ;
}}


//-----------------------------------------------------

cout << "\n       inv  ( A ) \t =  " ;
for (int i = 0;i<n;i++){
 for(int j=0 ;j<n;j++)  {
     cout << "\t" << matrix_B[i][j]  ;
  }
  cout <<"\n \t \t\t  " ;}

cout << endl << endl ;


//-----------------------------------------------------

cout << "\n\n      A * inv ( A )  =   " ;
for (int i = 0;i<n;i++){ for(int j=0;j<n;j++) {  for (int k = 0; k<n;k++)  {
    matrix_I[i][j] += matrix_A[i][k]* matrix_B[k][j] ;  } }}

    for (int i = 0;i<2;i++) {     for(int j=0;j<2;j++)
     {      cout << "\t" << matrix_I[i][j];   }
     cout << "\n \t\t\t";    }

return 0 ;
}
