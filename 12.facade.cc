#include <iostream>
using namespace std;

class A {
public:
  void methodA() {cout<<"invoke A's methodA"<<endl;}
};

class B {
public:
  void methodB() {cout<<"invoke B's methodB"<<endl;}  
};

class C {
public:
  void methodC() {cout<<"invoke C's methodC"<<endl;}
};

class Facade {
public:
  void methodA() {
    a.methodA();
    c.methodC();
  }

  void methodB() {
    b.methodB();
  }

private:
  A a;
  B b;
  C c;  
};

int main() {
  Facade f;
  f.methodA();
  cout<<endl;
  f.methodB();

  return 0;  
}


