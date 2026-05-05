#include<bits/stdc++.h>
using namespace std;

/*
    Inheritance - II
    :Data Members
        -Deriver class inherits all data members of Base class
        -Derived class may add data members of its own

    :Object Layout
        -Derived class layout contains an instance of the Base class
        -Further, Derived class layout will have data members of its own
        -C++ does not guarantee the relative position of the Base class instance and Derived class members
*/

class base{
  int data1;
  public:
    int data2;
};

class derived: public base{
  int info_der; //inherit both data1 and data 2
  // derived class can only access public property. here this derived class can only access data2.
  // so, inherit both private , protected and public but can access only public data members;
};

int main(){
  derived d;

  //derived class structure
  /*
     data1,data2,info_der
  */
  base b;
  /* base class contain data1,data2*/
  return 0;
}