#include<bits/stdc++.h>
using namespace std;

class calculateArea{
  int length;
  int breadth;
  public:
  calculateArea(int l,int b){
     this->length=l;
     this->breadth = b;

     cout << "normal constructor call" << endl;
     printArea();
  }

  //copy constructor 
  calculateArea(calculateArea &c){
    this->length = c.length;
    this->breadth = c.breadth;

    cout << "copy constructor called" << endl;
    printArea();
  }

  // assignment_operator_constructor;
  calculateArea &operator=(const calculateArea&c){
      if(this!=&c){//return the address of c as this point to that meory location
        this->length = c.length;
        this->breadth = c.breadth;

        cout << "assignment constructor called" << endl;
        printArea();
      }
  }

  void printArea(){
    cout << "Area :" << length * breadth << endl;
  }
};

int main(){
  calculateArea c1(4, 5);
  calculateArea c2(9, 6);
  calculateArea c3(c2); //copy constructor called 

  c1 = c2=c3; //assignment constructor called
  

  // c1.printArea();
  // c2.printArea();
  // c3.printArea();
  return 0;
}