#include <bits/stdc++.h>
using namespace std;

/*
    COPY CONSTRUCTOR vs COPY ASSIGNMENT OPERATOR

    -------------------------------------------------------
    1. Copy Constructor
    -------------------------------------------------------

    Used when a NEW object is created from another object.

    Example:
        Complex c3(c2);

    Here:
        - c3 does not exist yet
        - C++ creates c3 using c2

    So COPY CONSTRUCTOR is called.


    -------------------------------------------------------
    2. Copy Assignment Operator
    -------------------------------------------------------

    Used when an ALREADY EXISTING object gets values
    from another object.

    Example:
        c2 = c1;

    Here:
        - c2 already exists
        - only its data is replaced

    So COPY ASSIGNMENT OPERATOR is called.
*/

class Complex
{

public:
  double re_; // real part
  double im_; // imaginary part

public:
  /*
      NORMAL CONSTRUCTOR

      Called when object is created normally.
  */

  Complex(double re, double im)
      : re_(re), im_(im)
  {
    cout << "ctor: ";
    print();
  }

  /*
      COPY CONSTRUCTOR

      Called when a NEW object is created
      from another object.

      Example:
          Complex c3(c2);

      Here:
          c3 is being created using c2
  */

  Complex(const Complex &c)
      : re_(c.re_), im_(c.im_)
  {
    cout << "copy ctor: ";
    print();
  }

  /*
      DESTRUCTOR

      Called automatically when object dies.
  */

  ~Complex()
  {
    cout << "dtor: ";
    print();
  }

  /*
      COPY ASSIGNMENT OPERATOR

      Called when an EXISTING object receives
      values from another object.

      Example:
          c2 = c1;

      Here:
          c2 already exists.
          We only copy c1 data into c2.
  */

  Complex &operator=(const Complex &c)
  {

    /*
        Why const Complex& ?

        const
        -----
        We do not want to modify source object.

        &
        -
        Avoid unnecessary copying.
        Faster and memory efficient.
    */

    /*
        this -> pointer to current object

        &c   -> address of source object

        Why check this != &c ?

        To avoid self assignment.

        Example:
            c1 = c1;

        Self-copy is unnecessary.
    */

    if (this != &c)
    {

      // copy data members

      re_ = c.re_;
      im_ = c.im_;

      cout << "Copy Assignment: ";
      print();
    }

    /*
        Why return *this ?

        *this means current object.

        Returning current object allows:

            c1 = c2 = c3;

        because:

            (c2 = c3)

        itself becomes a valid expression.
    */

    return *this;
  }

  /*
      Calculates magnitude of complex number

      Formula:
          sqrt(re^2 + im^2)
  */

  double norm()
  {

    return sqrt(re_ * re_ + im_ * im_);
  }

  /*
      Prints complex number
  */

  void print()
  {

    cout << "|"
         << re_
         << "+j"
         << im_
         << "| = "
         << norm()
         << endl;
  }
};

int main()
{

  /*
      NORMAL CONSTRUCTOR CALL

      c1 is created normally.
  */

  Complex c1(4.2, 5.3);

  /*
      NORMAL CONSTRUCTOR CALL

      c2 is created normally.
  */

  Complex c2(7.9, 8.5);

  /*
      COPY CONSTRUCTOR CALL

      c3 does NOT exist yet.

      It is being created using c2.
  */

  Complex c3(c2);

  cout << endl;

  c1.print();
  c2.print();
  c3.print();

  cout << endl;

  /*
      COPY ASSIGNMENT OPERATOR CALL

      c2 already exists.

      We copy c1 data into c2.
  */

  c2 = c1;

  c2.print();

  cout << endl;

  /*
      COPY ASSIGNMENT CHAIN

      Step 1:
          c2 = c3

      Step 2:
          returned c2 assigned to c1

      Equivalent to:
          c1 = (c2 = c3)

      This works because operator=
      returns Complex&
  */

  c1 = c2 = c3;

  cout << endl;

  c1.print();
  c2.print();
  c3.print();

  return 0;
}