#include<bits/stdc++.h>
using namespace std;

class overloading{
 public:

  int add(int a,int b){
    return a + b;
  }

  int add(double a,double b){
    return a + b;
  }

  int add(int a){
    return 1 + a;
  }
};

int main(){
  /*
     Why Function Overloading (Static Polymorphism) is required at all ?
     Ans: Same functionality but takes different argument types

     Overload Resolution ?
     Ans: Function selection by compiler is called Overload Resolution (done in compile time)

     Note:
       - Binding happens at compile time.
       - Two functions having same signature but different return types cannot be overloaded (ALERT !!!)
       - Overloading allows "Static Polymorphism" (Explained in Polymorphism section)
     Types :
         - Same      # of parameters but of different types
         - Different # of parameters
 */

  overloading a;

  cout << a.add(1, 6) << endl;
  cout << a.add(5.1, 8.1) << endl;
  cout << a.add(8) << endl;
  return 0;
}