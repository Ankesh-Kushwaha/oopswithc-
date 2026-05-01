#include<bits/stdc++.h>
using namespace std;
// swallow copy -> A shallow copy copies all member values as they are.
// If an object contains a pointer, only the pointer address is copied 
//— not the actual data it points to.
//in swallow copy both the object points to the same memory location

class myClass{
  public:
  int *data;
  myClass(int v){
    data = new int(v);
  }
};

int main(){
  myClass c1(10);
  myClass c2 = c1;
  
  //value before change
  cout << "before chnage" << endl;
  cout << *c1.data << endl;
  cout << *c2.data << endl;
  //value after change
  cout << " after change" << endl;
  //since both are pointing to the same memory location the value change at one place reflected
  //at other place it can be dangerous in various location
  *c1.data = 50;
  cout << *c1.data << endl;
  cout << *c2.data << endl;

  return 0;
}