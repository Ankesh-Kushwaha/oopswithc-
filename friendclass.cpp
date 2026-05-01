#include<bits/stdc++.h>
using namespace std;

/*
    Friend class of a class
    -(all members) has access to the private and protected members of the class(breaks encapsulation)
    -does not have its name qualified with the class scope (not a nested class)
    -can be declared friend in more than one class

    A friend class can be
    -class
    -class template

    In the Linked list example we saw before, if we had to create another function say delete() in List class.
    Then also, I need to make this displa() a friend of Node class as well. It's cumbersome.
    We can achieve this by using friend class easily.

    So, if a class has too many member functions to be made friend of, its better to go for friend class instead of friend
    function

    IMPORTANT POINTS:
    - If class A is a friend of class B, it doesn't mean class B is a friend of class A
    - If class A is a friend of class B and class B is a friend of class C, it doesn't mean class A is a friend of class C

    Now, we are aware of three kinds of visibilities:
    -public
    -private
    -friend : It breaks visibility structure and hence should be used judiciously in cases like :
        - A function needs to access the internals of two(or more) independent classes. Ex: Matrix-vector multiplication
        - A class is built on top of another class. Ex: List-Node access
        - Certain situations of operator overloading. Ex: streaming operators (Later we will study this too)
*/

class Node
{
  int data;
  Node *next;
  public:
  Node(int v){
    this->data = v;
    this->next = NULL;
  }

  friend class List; //now the list class can access the private and prtected member of this class
};

class List{
  Node *head;
  Node *tail;

  public:
  List(Node* h=NULL){
    this->head = h;
    this->tail = h;
  }

 void append(int val){
    if(!head){
      head = tail = new Node(val);
    }
    else {
      tail->next = new Node(val);
      tail = tail->next;
    }
 }

 void display(){
   Node *temp = head;
   while(temp){
     cout << temp->data << endl;
     temp = temp->next;
   }
 }
};


int main(){
  List ll;
  ll.append(1);
  ll.append(2);
  ll.append(3);
  ll.append(5);
  ll.display();
  return 0;
}