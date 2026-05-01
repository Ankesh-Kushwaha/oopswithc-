#include<bits/stdc++.h>
using namespace std;

/*
    Copy Constructor:
    It takes an object of the same type and constructs a copy.

    Why do we need Copy Constructor ?
    Ans : For system defined data types, copy was easy (call-by-value OR return-by-value)
          but for UDT, we need Copy Constructor
          Also copy constructor is needed for initializing the data members of a UDT from an existing value.

    Why the parameter of copy constructor is Call-by-Reference ?
*/

class Complex{
  int re_;
  int im_;

  public:
  Complex(int re,int im){
    this->re_ = re;
    this->im_ = im;
    cout << "normal constructor called" << endl;
    print();
  }

  // copy constructor: Parameter should be passed as reference only
  /*
          When you pass an object by value in C++, a copy of the entire object is made and passed to the function.
          For a copy constructor, this means creating a copy of the object being passed, which involves invoking the
          copy constructor again. This process can lead to infinite recursion and a stack overflow.
  */

  Complex(Complex &c){
    this->im_ = c.im_;
    this->re_ = c.re_;

    cout << "copy constructor called" << endl;
    c.print();
  }

  
  int normalize(){
    return sqrt(re_ * re_ + im_ * im_);
  }

  void print(){
    cout << re_ << '+' << im_ << "j"<<": " << normalize() << endl;
  }

};
int main(){
  Complex c1(2, 4);
  Complex c2(4, 5);
  Complex c3(c2);
  return 0;
}