
#include<iostream>
#include<iomanip>
#include<math.h>
#include<time.h>


using namespace std ;

int main()
{
  /* initialize random seed: */
  srand (time(NULL));


//-------------------------------------------------
// INTIALIZE MATRICES A AND B TO zero
//-------------------------------------------------



float matrix_A[3][3]={};
float matrix_B[3][3]={};
float matrix_sum[3][3]={};
float matrix_prod[3][3]={};
float sum = 0;


//-------------------------------------------------
// ENTERING ELEMENTS IN  MATRICES A AND B TO SOME RANDOM VALUES
//-------------------------------------------------

for (int i = 0;i<3;i++)
{
  for(int j=0;j<3;j++)
  {
    matrix_A[i][j] = rand()%10 ;
    matrix_B[i][j] = rand()%10 ;
  }
 }

//-------------------------------------------------
//  COMPUTING SUM  OF MATRICES A AND B
//-------------------------------------------------



for (int i = 0;i<3;i++)
{
 for(int j=0;j<3;j++)
 {
   matrix_sum[i][j] = matrix_A[i][j] + matrix_B[i][j];
 }
}

//-------------------------------------------------
//  COMPUTING PRODUCT  OF MATRICES A AND B
//-------------------------------------------------



for (int i = 0;i<3;i++)
{
 for(int j=0;j<3;j++)
 {
  for (int k = 0; k<3;k++)
  {
    matrix_prod[i][j] = matrix_prod[i][j] + matrix_A[i][k]* matrix_B[k][j] ;

  }
 }
}


//-------------------------------------------------
//OUTPUT OF A , B  AND C
//-------------------------------------------------


cout << "\n A  =  \t " << endl;

for (int i = 0;i<3;i++)
{
 for(int j=0;j<3;j++)
 {
  cout << "\t"<< setw(3) << matrix_A[i][j];
 }
 cout << endl;
}

//-------------------------------------------------

cout << "\n B =  \t " << endl;

for (int i = 0;i<3;i++)
{
 for(int j=0;j<3;j++)
 {
  cout << "\t"<< setw(3) << matrix_B[i][j];
 }
 cout << endl;

}
cout << endl;

//-------------------------------------------------

cout << "\nA  + B =  \t " << endl;

for (int i = 0;i<3;i++)
{
 for(int j=0;j<3;j++)
 {
  cout << "\t"<< setw(3) << matrix_sum[i][j];
 }
 cout << endl;

}

//-------------------------------------------------

cout << "\nA * B =  \t " << endl;

for (int i = 0;i<3;i++)
{
 for(int j=0;j<3;j++)
 {
  cout << "\t"<< setw(3) << matrix_prod[i][j];
 }
 cout << endl;

}


return 0 ;

}
