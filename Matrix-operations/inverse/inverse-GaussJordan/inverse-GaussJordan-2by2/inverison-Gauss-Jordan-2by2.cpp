/*
 * 
 *             Inverse of a 2 * 2 matrix  using Gauss Jordan Elimination 
 * 
 * This works only for order 2 matrix.
 * Author        :  Ankit Dhiman
 * Last Modified : 2 June , 2020
 * 
 * Make a copy before making changes
 */

#include<iostream>
#include<iomanip>
#include<math.h>
#include<ctime>


#define SIZE 10

using namespace std ;


//-------------------------------------------------


void PrintMatrix(float matrix[SIZE][SIZE] ,int row , int col ){
 cout << "\n       Matrix  A \t =  " ;
 for (int i = 0;i<row;i++) {
    for(int j=0;j<col;j++)   {

         cout  << "\t" << matrix[i][j] ;
   }
   cout <<"\n                      \t   " ;

 }
    return ;
}

//-------------------------------------------------


void PrintAugmentedMatrix(float matrix[SIZE][SIZE] ,int row , int col ){
cout << "\n Augmented Matrix  A' \t =  " ;
for (int i = 0;i<row;i++) {
   for(int j=0;j<col+col;j++)   {
     if (j>1 && j<3) {
       cout << "\t | \t" << matrix[i][j] ;}
       else if (j>3) {
        cout  << "\t" << matrix[i][j]  ;  }
       else {
        cout  << "\t" << matrix[i][j] ;   }
  }
  cout <<"\n                      \t   " ;
}}


//-------------------------------------------------
//-------------------------------------------------







int main()                                                                  /* Main driver code */
{ srand (time(NULL));                                                      /*initialize random seed */

//-------------------------------------------------

int  i,j,k;
int const n = 2 ;

float matrix_A[SIZE][SIZE]={};
float temp_A[SIZE][SIZE]={};
float temp_B[SIZE][SIZE] = {} ;
float determinant_A = 0 ;

cout << setprecision(2) << fixed ;


//-------------------------------------------------
//             Matrix A definition


for (int i =0;i<n;i++)
{
  for(int j=0;j<n;j++)
  {
    matrix_A[i][j] = rand()% 9 ;

  }
 }

 //---------------------------------------------------------


determinant_A = matrix_A[0][0]*matrix_A[1][1]-matrix_A[0][1]*matrix_A[1][0] ;
PrintMatrix(matrix_A,n,n)  ;                      //      printing  matrix A

 //---------------------------------------------------------
 
 for (int i = 0;i<n;i++) {
     for(int j=0;j<n;j++)   {
      if(determinant_A==0){
          cout << "\n     Error , determinant of A is zero! Inverse does not exist. try again!\n\n" ;
        goto  a ;}
      }
  }

//-------------------------------------------------
//            Augmenting identity matrix


for (int i = 0;i<n;i++)
{
 for(int j=0;j<n;j++)
 {
   if (i==j) {
     matrix_A[i][j+n] = 1.0 ;
   }
   else {
     matrix_A[i][j+n] = 0.0 ;
   }
 }
}


//---------------------------------------------------------
//      row 1 / first element
 for(i=0;i<n-1;i++){
   cout << "\n dividing row 1 by \t "  << matrix_A[0][0] ;
    for(j=0;j<2*n;j++) {
    temp_A[i][j] = matrix_A[i][j]/(matrix_A[0][0]);
      }
  }

  //---------------------------------------------------------
 //       output matrix

 cout << "\n\n A'          becomes \t =  " ;
  for (int i = 0;i<n-1;i++) {
     for(int j=0;j<n+n;j++)   {
       if (j>1 && j<3) {
         cout << "\t | \t" << temp_A[i][j] ;}
         else if (j>3) {
          cout  << "\t" << temp_A[i][j]  ;  }
         else {
          cout  << "\t" << temp_A[i][j] ;   }
    }
    cout <<"\n                      \t   " ;
  }

  for (int i = 1;i<n;i++) {
     for(int j=0;j<n+n;j++)   {
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

cout << "\n\n subtracting  "  << matrix_A[1][0]  << "* row 1 from row 2" ;
  for (i=1 ; i<n;i++){
    for(j=0;j<2*n;j++) {
    temp_A[i][j] = matrix_A[i][j]-(matrix_A[i][0]*(temp_A[0][j]));

  }}

  //---------------------------------------------------------


  //---------------------------------------------------------
  //        output matrix A
  cout << "\n\n Matrix   becomes \t =  " ;
  for (int i =0 ;i<n;i++) {
     for(int j=0;j<n+n;j++)   {
       if (j>1 && j<3) {
         cout << "\t | \t" << temp_A[i][j] ;}
         else if (j>3) {
          cout  << "\t" << temp_A[i][j]  ;  }
         else {
          cout  << "\t" << temp_A[i][j] ;   }
    }
    cout <<"\n                      \t   " ;
  }

  //---------------------------------------------------------
  //   dividing row 2 by 4 th element to make 1 at 4 th place
  cout << "\n\n dividing row 2 by " << temp_A[1][1]   ;
 for (i=1 ;i<n ; i++) {
 for(j=0;j<2*n;j++) {
  temp_B[i][j] = temp_A[i][j]/temp_A[1][1];
}}
  //---------------------------------------------------------

    cout << "\n\n Matrix   becomes \t =  " ;
  for (int i =0 ;i<n-1;i++) {
     for(int j=0;j<n+n;j++)   {
       if (j>1 && j<3) {
         cout << "\t | \t" << temp_A[i][j] ;}
         else if (j>3) {
          cout  << "\t" << temp_A[i][j]  ;  }
         else {
          cout  << "\t" << temp_A[i][j] ;   }
    }
    cout <<"\n                      \t   " ;
  }

  for (int i =1 ;i<n;i++) {
     for(int j=0;j<n+n;j++)   {
       if (j>1 && j<3) {
         cout << "\t | \t" << temp_B[i][j] ;}
         else if (j>3) {
          cout  << "\t" << temp_B[i][j]  ;  }
         else {
          cout  << "\t" << temp_B[i][j] ;   }
    }
    cout <<"\n                      \t   " ;
  }

  //---------------------------------------------------------
  //Row[1] − 2 element × Row[2]cout << "\n\n dividing row 2 by " << temp_A[1][1]   ;
  cout << "\n\n row 1 - " << temp_A[0][1] << "* row 2\t"   ;
for (i=0 ;i<n-1 ; i++) {
for(j=0;j<n+n;j++) {
 temp_B[0][j] = temp_A[0][j]-(temp_A[i][1]*(temp_B[1][j]));
}}

  //---------------------------------------------------------
  //---------------------------------------------------------

  for (int i =0 ;i<n;i++) {
     for(int j=0;j<n+n;j++)   {
       if (j>1 && j<3) {
         cout << "\t | \t" << temp_B[i][j] ;}
         else if (j>3) {
          cout  << "\t" << temp_B[i][j]  ;  }
         else {
          cout  << "\t" << temp_B[i][j] ;   }
    }
    cout <<"\n                  \t    " ;
  }

  //---------------------------------------------------------

//---------------------------------------------------------
//      printing augmented matrix A' after gauss jordan operations



cout << "\n New Augmented Matrix  A' after gauss jordan \t =  " ;
for (int i = 0;i<n;i++) {
   for(int j=0;j<n+n;j++)   {
     if (j>1 && j<3) {
       cout << "\t | \t" << temp_B[i][j] ;}
       else if (j>3) {
        cout  << "\t" << temp_B[i][j]  ;  }
       else {
        cout  << "\t" << temp_B[i][j] ;   }
  }
  cout <<"\n                                            \t   " ;
}



//----------------------------------------------------------------
//          display inverse of A


cout << "\n\t inv( A ) \t =  " ;
for (int i = 0;i<n;i++)
{
 for(int j=n;j<n+n;j++)
  {
     cout << "\t" << temp_B[i][j]  ;
  }
  cout <<"\n \t \t\t  " ;
}

//-----------------------------------------------------------------------

cout << endl << endl ;
a:return 0 ;
}
