#include<bits/stdc++.h>
using namespace std;
// deep copy -> A deep copy creates a completely separate copy of dynamically allocated memory
//the copied object get its own memory
class deepcopy{
  public:
    int *data;
    //deep copy constructor
    deepcopy(int val){
      data = new int(val);
    }

    deepcopy(deepcopy &c){
      data = new int(*c.data);
    }
};

int main(){
  deepcopy t1(20);
  deepcopy t2 = t1;

  cout << "before value change" << endl;
  cout << *t1.data << endl;
  cout << *t2.data << endl;
  cout << "value after change" << endl;
  *t2.data = 50;

  cout << *t1.data << endl;
  cout << *t2.data << endl;

  return 0;
}