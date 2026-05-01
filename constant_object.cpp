#include <bits/stdc++.h>
using namespace std;

/*
    CONSTANT OBJECT CONCEPT

    If an object is declared using const:

        const ClassName obj;

    then the object becomes READ-ONLY after creation.

    Meaning:
    -----------------------------------
    ❌ Data members cannot be modified
    ❌ Non-const member functions cannot be called
    ✅ Only const member functions can be called

    Why?

    Because non-const functions MAY modify object data,
    so C++ does not allow constant objects to call them.
*/

class constant_object_demo
{

  int private_value;

public:
  int public_value;

  constant_object_demo(int priV, int pubV)
  {

    this->private_value = priV;
    this->public_value = pubV;
  }

  // NON-CONST FUNCTION
  // This function modifies object data
  // Therefore constant objects cannot call it

  void setPriValue(int val)
  {
    private_value = val;
  }

  // NON-CONST FUNCTION
  // Modifies object data

  void setPublicValue(int val)
  {
    public_value = val;
  }

  // NON-CONST FUNCTION
  // Even though it only returns data,
  // C++ still treats it as unsafe because
  // it is not marked const

  int getPrivateVal() const
  {
    return private_value;
  }

  // NON-CONST FUNCTION

  int getPublicValue() const
  {
    return public_value;
  }

  // CONST MEMBER FUNCTION
  // This function promises:
  // "I will NOT modify object data"

  void print() const
  {

    cout << "private: "
         << private_value
         << " public: "
         << public_value
         << endl;
  }
};

int main()
{

  // CONSTANT OBJECT
  // After creation, object becomes READ-ONLY

  const constant_object_demo obj1(5, 4);

  // ERROR
  // Cannot call non-const function using const object
  // because this function may modify object data

  //obj1.setPriValue(10);

  // ERROR
  // Non-const function

  //obj1.setPublicValue(45);

  // ERROR
  // getPrivateVal() is not marked const
  // C++ assumes it may modify object

  cout << obj1.getPrivateVal() << endl;

  // ERROR
  // getPublicValue() is also non-const

  cout << obj1.getPublicValue() << endl;

  // WORKS
  // print() is a const member function

  obj1.print();

  return 0;
}