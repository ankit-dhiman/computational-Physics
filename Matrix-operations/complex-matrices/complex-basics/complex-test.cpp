

#include<iostream>
#include<complex>
#include<ctime>
#include<cstdlib>


using namespace std ;

int main()
{
        int a , b , real_part , img_part ;
        srand((unsigned) time(0)) ;
        a = -10;
        b = 20;             // generate random numbers between -10 and 10
        real_part  = a + ( rand() %b )   ;
        img_part   = a + ( rand() %b )   ;

        complex<double> mycomplex(real_part , img_part);

    cout << "Real part: " << real(mycomplex) << endl;
    cout << "Imaginary part: " << imag(mycomplex) << endl;
    cout << "cp: " << mycomplex << endl;

    return 0;
}
