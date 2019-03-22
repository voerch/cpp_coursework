#ifndef BSEq_h
#define BSEq_h

#include "ParabPDE.h"
#include "BSModel01.h"
#include "Option.h"

class BSEq: public ParabPDE
{
   public:
      BSModel* PtrModel;
      Option* PtrOption;
      BSEq(BSModel* PtrModel_,Option* PtrOption_);

      double a(double t, double z);
      double b(double t, double z);
      double c(double t, double z);
      double d(double t, double z);

      double f(double z);
      double fl(double t);
      double fu(double t);
};

#endif
