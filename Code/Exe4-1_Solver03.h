#ifndef Exe4_1_Solver03_h
#define Exe4_1_Solver03_h

template<typename Function> double SolveByBisect
   (Function& Fct,
   double Tgt, double LEnd, double REnd, double Acc)
{
   double left=LEnd, right=REnd, mid=(left+right)/2;
   double y_left=Fct.Value(left)-Tgt, y_mid=Fct.Value(mid)-Tgt;
   while (mid-left>Acc)
   {
      if ((y_left>0 && y_mid>0)||(y_left<0 && y_mid<0))
         {left=mid; y_left=y_mid;}
      else right=mid;
      mid=(left+right)/2;
      y_mid=Fct.Value(mid)-Tgt;
   }
   return mid;
}

template<typename Function> double SolveByNR
   (Function& Fct,
   double Tgt, double Guess, double Acc)
{
   double x_prev=Guess;
   double x_next=x_prev
      -(Fct.Value(x_prev)-Tgt)/Fct.Deriv(x_prev);
   while (x_next-x_prev>Acc || x_prev-x_next>Acc)
   {
      x_prev=x_next;
      x_next=x_prev
         -(Fct.Value(x_prev)-Tgt)/Fct.Deriv(x_prev);
   }
   return x_next;
}

#endif
