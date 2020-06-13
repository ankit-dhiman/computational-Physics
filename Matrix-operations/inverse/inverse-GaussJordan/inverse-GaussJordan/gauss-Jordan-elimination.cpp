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
cout << setprecision(2)<< fixed << setw(5) << fixed ;

int rows =  2 ,i,j,k;
int colms = 2 ;

float matrix_A[SIZE][SIZE]={};
float x[SIZE] , ratio ;
//cout << setprecision(4) << fixed ;
float determinant_A = 0;


//-------------------------------------------------
//             Matrix A definition
//-------------------------------------------------


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
     if (j>1 && j<3) {
       cout << "\t | \t" << matrix_A[i][j] ;}
       else if (j>3) {
        cout  << "\t" << matrix_A[i][j]  ;  }
       else {
        cout  << "\t" << matrix_A[i][j] ;   }
  }
  cout <<"\n                      \t   " ;
}


//---------------------------------------------------------
//               Applying gauss jordan elimination
//-------------------------------------------------

cout << "\n"<<setw(10)<< "i"   << setw(10)<< "j"  << setw(15) <<"   A[j][i]/A[i][i]" << setw(10)<<"ratio" << setw(10) << "k"<<setw(25)<< "A[j]k]" <<setw(20)<< "    A[j][k]"
     << endl << endl
     << "***************************************************************************************************************\n\n" ;



for (i=0 ;i<rows;i++)
 {
   if ( matrix_A[i][i]== 0 )
   {   //This matrix is not invertible.
      cout << "Mathematical Error !This matrix is not invertible.\n" ;
    exit(0) ;
   }
//---------------------------------------------


 for (j=0;j<colms;j++)
  {
    if(i!=j)
     {
       ratio = matrix_A[j][i]/matrix_A[i][i] ;
       cout <<setw(10) << i << setw(10)<< j << setw(15) << matrix_A[j][i]<<"/"<<matrix_A[i][i] <<setw(10)<< ratio<< setw(8)  ;
       for (int k= 0 ; k<2*colms ;k++ )
        {
          matrix_A[j][k] = matrix_A[j][k] - ratio*matrix_A[i][k];
          cout << k << setw(25)<< "A[ " <<j << " ][" << k<< "] - "<< ratio <<" * A[" <<i << "][" << k << "]" << setw(10)<<matrix_A[j][k]<<endl << setw(58) ;
        }
    cout << endl ;
    }
  }
}

//---------------------------------------------------------------


/* Row Operation to Make Principal Diagonal to 1 */
		 for(i=0;i<rows;i++) 		 {
			  for(j=colms;j<2*colms;j++)  {
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
