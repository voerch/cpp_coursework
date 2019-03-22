#ifndef ParabPDE_h
#define ParabPDE_h

class ParabPDE
{
   public:
      double T,xl,xu;

      virtual double a(double t, double x)=0;
      virtual double b(double t, double x)=0;
      virtual double c(double t, double x)=0;
      virtual double d(double t, double x)=0;

      virtual double f(double x)=0;
      virtual double fu(double t)=0;
      virtual double fl(double t)=0;
};

#endif
