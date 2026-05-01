#include<bits/stdc++.h>
using namespace std;

class Complex{
  int re_;
  int im_;
  public:

  Complex(int re,int im) : re_(re),im_(im){
    cout << "normal constructor called";
    print();
  }
  
  int normalize(){
    return sqrt(re_ * re_ + im_ * im_);
  }

  void print(){
    cout << re_ << "+" << im_ << "j" << ": " << normalize() << endl;
  }

  void display_call_by_value(Complex c){
    c.print();
    cout << "call by value constructor called" << endl;
  }

  void display_call_by_refrence(Complex &c){
    c.print();
    cout << "call by refrence constructor called" << endl;
  }

  ~Complex(){
    cout << "destructor is called" << endl;
  }
};

int main(){
  Complex c1(4, 5);
  Complex c2(2, 5);

  Complex c3(c2);
  return 0;
}