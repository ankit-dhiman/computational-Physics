

#include<iostream>
#include<math.h>
#include<time.h>
#include<random>


//-------------------------------------------------
using namespace std;
#define SIZE 100

//-------------------------------------------------

int determinant( int matrix[SIZE][SIZE], int n) {

   int det = 0;
   int submatrix[SIZE][SIZE];

   if (n == 2) {
      return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1])); }
   else {
      for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
               int subj = 0;
               for (int j = 0; j < n; j++) {
                  if (j == x)
                  continue;
                  submatrix[subi][subj] = matrix[i][j];
                  subj++;
               }
               subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
      }
   }


   return det;
}



//***************************************************************************
//              start of main program
//***************************************************************************



int main() {
    srand(time(NULL));
   int n = 3 , i, j;
   int A[SIZE][SIZE];


   cout << "\n\t***************** Determiant of the matrix*****************:\n";
     for (i = 0; i < n; i++) {
     for (j = 0; j < n; j++) {
      A[i][j] = rand()%10 + 1;
     }
   }

//***************************************************************************

   cout << "\nA = \t ";
   for (i = 0; i < n; i++) {
   for (j = 0; j < n; j++) {
    cout << "\t" << A[i][j] << "  ";
   }
   cout << "   \n\t" ;
 }

//***************************************************************************

   cout<<"\n\nDet ( A ) :  \t"
       << determinant(A, n) << endl << endl;

   return 0;
}
