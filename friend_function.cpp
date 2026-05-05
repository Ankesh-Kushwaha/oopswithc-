#include<bits/stdc++.h>
using namespace std;

/*
    Friend function
    -Has access to the private and protected members of the class (breaks encapsulation)
    -must have its prototype included withing the scope of the class prefixed with the keyword friend
    -does not have its name qualified with the class scope (MyClass:: is not required)
    -is not called with an invoking object of the class
    -can be declared friend in more than one class

    -It can be a global function
    -Any member function of a different class could also be a friend of a class
    -It can be a function template
*/

class Test{
  int x;
  public:
  Test(int v){
    this->x = v;
  }

  friend void show(Test obj);
};

void show(Test obj){
  cout << obj.x << endl;
}

int main(){
  Test t(10);

  show(t);
  return 0;
}