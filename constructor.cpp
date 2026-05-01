#include<bits/stdc++.h>
using namespace std;

/*
    Constructors in C++
    Constructor is used for construction of an object(i.e. initialization). Hence, It doesn't have return type.
    We can do initialization using initializer list as well.
    - We can have parameterized constructor (default parameters can also be used)
    - We can have overloaded constructors as well
    - NOTE: If you are declaring an array of objects (Complex c[3]; then you must have a default constructor because if we don't have default constructor, then
      it will require the parameters to be passed and with statement Complex c[3], you can't do that)
*/

class constructor_practice{
  public:
    // unparameterised contructor;
    constructor_practice()
    {
      cout << "constructor_called" << endl;
    }
    
    //parameterised constructor
    //contructor overloading
    constructor_practice(int n){
      cout <<"constructor with int value called : "<< n << endl;
    }

    constructor_practice(double val){
      cout <<"contructor with double value called : "<<val << endl;
    }
};

int main(){
  constructor_practice obj1(2.5555);

  return 0;
}