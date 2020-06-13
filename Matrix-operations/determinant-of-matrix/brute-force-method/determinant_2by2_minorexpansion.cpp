/**
 * C program to find determinant of 2*2 matrix 
 *  using brute force method
 */
#include<iostream>
#include<random>
#include<cmath>

using namespace std ;
#define SIZE 2 // Matrix size

int main()
{
    srand(time(NULL));
    int A[SIZE][SIZE];
    int M[SIZE-1][SIZE-1];
    int row, col;
    long det_A  = 0;





//------------------------------------------------------------------------------

cout << ("\n\t\t\t Determinant of a  2x2 Matrix: \n")
     << "\t----------------------------------------------------------------\n" ;


//-----------------------------------------------------------------------------
//             filling matrix A with random values using random function


    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            A[row][col] = rand()%9 + 1 ;
        }
    }
//-------------------------------------------------------------------------------


 M[1][1] = A[0][0] ;
 M[1][0] = A[0][1] ;
 M[0][1] = A[1][0] ;
 M[0][0] = A[1][1] ;


//-------------------------------------------------------------------------------

         row  = 0 ;
        for(col=0; col<SIZE; col++)
        {
           det_A  = det_A+  pow(-1 , ( row + col) ) * ( A[row][col]*M[row][col] )  ;
           }


//-------------------------------------------------------------------------------

    cout << "\n\n\n A \t  =   \t" ;
    for (int row = 0;row<SIZE;row++)
    {
     for(int col=0;col<SIZE;col++)
     {
     cout << A[row][col] << "\t";
    }
    cout << "\n  \t     \t"   ;
     }

    cout << "\n\n  det (A) =  \t " << det_A   << endl ;

//-------------------------------------------------------------------------------


    return 0;
}
