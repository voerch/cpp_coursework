#include <iostream>
#include <conio.h>
#include "BSModel01.h"
#include "Option.h"
#include "Exe6-4_CallOption.h"
#include "BSEq.h"
#include "ExplicitMethod.h"
#include "EurCall.h"

int testStability(BSEq &BSPDE,Call &EuropeanCall, int imax, int jmax)
{
   ExplicitMethod Method(&BSPDE, imax, jmax);
   Method.SolvePDE();

   double FDPrice = Method.v(0.0,BSPDE.PtrModel->S0);
   cout << "FD Call Price = " << FDPrice << endl;

   EurCall BSCall(EuropeanCall.T,EuropeanCall.K);
   double BSPrice = BSCall.PriceByBSFormula
                     (BSPDE.PtrModel->S0,BSPDE.PtrModel->sigma,BSPDE.PtrModel->r);
   cout << "BS Call Price = " << BSPrice << endl;

   cout << "dt/(dx^2) = " << Method.dt/(Method.dx*Method.dx) << endl;

   return 0;
}

int main()
{
   double S0=100.0, r=0.05, sigma=0.2;
   BSModel Model(S0,r,sigma);

   double K=100.0, T=1./12., zl=0.0, zu=2.0*S0;
   Call EuropeanCall(K,T,zl,zu);

   BSEq BSPDE(&Model,&EuropeanCall);

   int imax, jmax;
   cout << "Enter imax: "; cin >> imax; cout << endl;

   unsigned char key;
   do
   {
      cout << "Enter jmax: "; cin >> jmax;
      testStability(BSPDE,EuropeanCall,imax,jmax);
      cout << endl <<"press Esc to exit the program, or any other key to continue with tests." << endl<< endl;
      key = getch();
   }while( key != 27 );

   return 0;
}

