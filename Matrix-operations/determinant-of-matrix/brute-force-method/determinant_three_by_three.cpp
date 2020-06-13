/*
 * 
 * Author : Ankit Dhiman
 * 
 * C++ program to find determinant of 3x3 matrix
 * 
 * 
 */
#include<iostream>
#include <stdio.h>

using namespace std ;
#define SIZE 3 // Matrix size

int main()
{
    int A[SIZE][SIZE];
    int row, col;
    int a, b, c, d, e, f, g, h, i;
    long det;

    /* Input elements in matrix A from user */
    cout << ("\n\t\tDeterminant of a  3x3 Matrix: \n")
         << "\t----------------------------------------------------------------\n" ;
    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            A[row][col] = rand()%10 + 1 ;
        }
    }

    /*
     * Used as a temporary variables to make calculation easy
     * |         |
     * | a  b  c |
     * | d  e  f |
     * | g  h  i |
     * |         |
     */
    a = A[0][0];
    b = A[0][1];
    c = A[0][2];
    d = A[1][0];
    e = A[1][1];
    f = A[1][2];
    g = A[2][0];
    h = A[2][1];
    i = A[2][2];

    /*
     * det(A) = a(ei - fh) - b(di - fg) + c(dh - eg)
     */
    det = (a*(e*i - f*h)) - (b*(d*i - f*g)) + (c*(d*h - e*g));


    cout << "\n A \t  =   \t" ;

    for (int i = 0;i<SIZE;i++)
    {
     for(int j=0;j<SIZE;j++)
     {
     cout << A[i][j] << "\t";
    }
    cout << "\n  \t     \t"   ;
     }

    cout << "\n\n  det (A) =  \t " << det   << endl ;
    return 0;
}
