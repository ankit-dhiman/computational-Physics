
#include<iostream>
#include<iomanip>
#include<cmath>
#include<time.h>


using namespace std ;

int main()
{
  /* initialize random seed: */
  srand (time(NULL));

int rows , colms ;
rows = 2   ;
colms = 2  ;
//-------------------------------------------------
// INTIALIZE MATRICES A AND TRANSPOSE TO zero
//-------------------------------------------------



float matrix_A[10][10]={};
float matrix_transpose[10][10]={};
float sum = 0;


//-------------------------------------------------
// INTIALIZING  MATRICES A TO SOME RANDOM VALUES
//-------------------------------------------------

for (int i = 1;i<=rows;i++)
{
  for(int j=1;j<=colms;j++)
  {
    matrix_A[i-1][j-1] = rand()%10 ;
  }
 }

//-------------------------------------------------
//  COMPUTING TRANSPOSE  OF MATRICES A
//-------------------------------------------------



for (int i = 1;i<=rows;i++)
{
  for(int j=1;j<=colms;j++)
 {
   matrix_transpose[j-1][i-1] = matrix_A[i-1][j-1];
 }
}

//-------------------------------------------------
//OUTPUT OF A , A^t
//-------------------------------------------------


cout << "\n A  =  \t " << endl;

for (int i = 1;i<=rows;i++)
{
  for(int j=1;j<=colms;j++)
 {
  cout << "\t"<< setw(3) << matrix_A[i-1][j-1];
 }
 cout << endl;
}

//-------------------------------------------------

cout << "\n transpose(A) =  \t " << endl;

for (int i = 1;i<=rows;i++)
{
  for(int j=1;j<=colms;j++)
 {
  cout << "\t"<< setw(3) << matrix_transpose[i-1][j-1];
 }
 cout << endl;

}


return 0 ;

}
