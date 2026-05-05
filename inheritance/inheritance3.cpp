#include<bits/stdc++.h>
using namespace std;

/*
    Inheritance - III
    :Member Functions
        -Derived class inherits all member function of Base class
        -Derived class may "override" a member function of Base class by redefining it with the "same signature"
        -Derived class may "overload" a member function of Base class by redefining it with same name but "different signature"
        -Derived class may add new member functions

    Important Points:
    -Static Member Functions : Derived class does not inherit the static member functions of Base class
    -Friend Functions        : Derived class does not inherit the friend functions of Base class
    //Static member functions are inherited, but they belong to the class itself rather than objects.

    Two examples mentioned below
*/

//example 1
// class base{
//     public:
//     void f(int i){
//       cout << "base:" << i << endl;
//     }

//     void g(int i){
//       cout << "base:" << i << endl;
//     }
// };

// class derived:public base{
// };

// int main(){
//      base b;
//      derived d;

//      d.f(2); // base class function is inherited by derived class
//      d.g(25);
//      return 0;
// }

//example -2
class base{
  public:
  void f(int i){
    cout << "Base:" << i << endl;
  }

 static void g(string name){
    cout << "Base: " << name << endl;
  }
};

class derived:public base{
   public:
   void f(int i){ //overriding the function f
     cout << "from derived" << "Ankesh Kushwaha" << endl;
   }

   void g(int i){//overloading 
     cout << "from derived" << i << endl;
   }
   
};

int main(){
 base b;
 derived d;

 b.f(52);
 b.g("ankesh");

 d.f(5);
 d.g(56);
 return 0;
}