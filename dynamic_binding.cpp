#include <bits/stdc++.h>
using namespace std;

/*
    INHERITANCE HIERARCHY

        A
        ↑
        B
        ↑
        C

    Main concepts used:
    1. Inheritance
    2. Virtual functions
    3. Function overriding
    4. Function overloading
    5. Runtime binding
    6. Compile-time binding
*/

// ======================= CLASS A =======================
class A
{
public:
  /*
      virtual function

      If called using base-class pointer,
      actual object type decides which function runs.
  */
  virtual void f(int x)
  {
    cout << "A::f(int)" << endl;
  }

  /*
      Another virtual function
  */
  virtual void g(double x)
  {
    cout << "A::g(double)" << endl;
  }

  /*
      NON-VIRTUAL function

      Binding happens at compile time.
      Pointer type decides which function is called.
  */
  int h(A *a_obj)
  {
    cout << "A::h(A*)" << endl;
    return 0;
  }
};

// ======================= CLASS B =======================
class B : public A
{
public:
  /*
      Overrides A::f(int)

      Since A::f is virtual,
      this also becomes virtual automatically.
  */
  void f(int x) override
  {
    cout << "B::f(int)" << endl;
  }

  /*
      This is NOT overriding A::h(A*)

      Why?
      Because parameter type is different.

          A::h(A*)
          B::h(B*)

      Different signatures => function overloading
  */
  virtual int h(B *b_obj)
  {
    cout << "B::h(B*)" << endl;
    return 0;
  }
};

// ======================= CLASS C =======================
class C : public B
{
public:
  /*
      Overrides A::g(double)
  */
  void g(double x) override
  {
    cout << "C::g(double)" << endl;
  }

  /*
      Overrides B::h(B*)
  */
  int h(B *b_obj) override
  {
    cout << "C::h(B*)" << endl;
    return 0;
  }
};

// ======================= MAIN =======================
int main()
{

  // Creating objects
  A a;
  B b;
  C c;

  // Base-class pointer
  A *pA;

  // Derived-class pointer
  B *pB;

  // =========================================================
  //                  EXERCISE 1
  // =========================================================

  cout << "=============== EXERCISE 1 ===============" << endl;

  /*
      pA is A*

      Base pointer can point to:
      - A object
      - B object
      - C object

      This is UPCASTING.
  */

  // ---------------------------------------------------------
  // CASE 1 : pA points to A object
  // ---------------------------------------------------------

  pA = &a;

  cout << "\npA = &a" << endl;

  /*
      Virtual function

      Actual object = A
      So A::f() is called
  */
  pA->f(2);

  /*
      Virtual function

      Actual object = A
      So A::g() is called
  */
  pA->g(3.2);

  /*
      NON-VIRTUAL function

      Pointer type = A*
      So compiler chooses A::h(A*)
  */
  pA->h(&a);

  /*
      B* automatically converts to A*
      (upcasting allowed)

      Still pointer type is A*
      So A::h(A*) is called
  */
  pA->h(&b);

  // ---------------------------------------------------------
  // CASE 2 : pA points to B object
  // ---------------------------------------------------------

  pA = &b;

  cout << "\npA = &b" << endl;

  /*
      Virtual function

      Actual object = B
      So B::f() is called
  */
  pA->f(2);

  /*
      B did NOT override g()

      So inherited version from A is used
  */
  pA->g(3.2);

  /*
      NON-VIRTUAL function

      Pointer type = A*
      So A::h(A*) is called
  */
  pA->h(&a);

  /*
      Still A::h(A*)
  */
  pA->h(&b);

  // ---------------------------------------------------------
  // CASE 3 : pA points to C object
  // ---------------------------------------------------------

  pA = &c;

  cout << "\npA = &c" << endl;

  /*
      Virtual function

      C did NOT override f()

      But C inherited B::f()

      So B::f() is called
  */
  pA->f(2);

  /*
      Virtual function

      C overrides g()

      So C::g() is called
  */
  pA->g(3.2);

  /*
      NON-VIRTUAL function

      Pointer type = A*
      So A::h(A*) is called
  */
  pA->h(&a);

  /*
      Still A::h(A*)
  */
  pA->h(&b);

  // =========================================================
  //                  EXERCISE 2
  // =========================================================

  cout << "\n=============== EXERCISE 2 ===============" << endl;

  /*
      pB is B*

      B* can point to:
      - B object
      - C object

      But NOT A object

      Why?
      Because A is parent class.

      Downcasting is unsafe.
  */

  // ---------------------------------------------------------
  // CASE 1 : pB points to B object
  // ---------------------------------------------------------

  pB = &b;

  cout << "\npB = &b" << endl;

  /*
      Virtual function

      Actual object = B
      So B::f() is called
  */
  pB->f(2);

  /*
      B did NOT override g()

      So A::g() is used
  */
  pB->g(3.2);

  /*
      ERROR if uncommented

      h() expects B*
      but &a is A*

      Downcasting not allowed automatically
  */

  // pB->h(&a);

  /*
      Virtual function

      Actual object = B
      So B::h(B*) is called
  */
  pB->h(&b);

  // ---------------------------------------------------------
  // CASE 2 : pB points to C object
  // ---------------------------------------------------------

  pB = &c;

  cout << "\npB = &c" << endl;

  /*
      C inherited B::f()

      So B::f() is called
  */
  pB->f(2);

  /*
      C overrides g()

      So C::g() is called
  */
  pB->g(3.2);

  /*
      Virtual function

      Actual object = C
      So C::h(B*) is called
  */
  pB->h(&b);

  return 0;
}