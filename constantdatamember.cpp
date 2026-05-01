/*
    constant data members in class
    - A constant data member cannot be changed even in a non-constant object. Therefore, it must be set at the time of initialization
      of the object
*/
 
#include<bits/stdc++.h>
using namespace std;

class constant_data_member{
  const int const_private_value;
  int private_value;

public:
  const int const_public_value;
  int public_value;

  constant_data_member(int cpri_v,int p_v,int cpub_v,int pub_v){
   // this->const_private_value = cpri_v; // the value cannot be modifiable;
    this->private_value = p_v;
    //this->const_public_value = cpub_v;
    this->public_value = pub_v;
  }
};

int main(){

  return 0;
}