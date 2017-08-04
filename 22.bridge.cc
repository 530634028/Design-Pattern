#include <iostream>

using namespace std;

class Implementor {
public:
  virtual void Operation() = 0;  
};

class ConcreteImplementorA : public Implementor {
public:
  void Operation() {
    cout<<"ConcreteA's implemantation"<<endl;
  }  
};

class ConcreteImplementorB : public Implementor {
public:
  void Operation() {
    cout<<"ConcreteB's implemantation"<<endl;
  }  
};

class Abstract {
public:
  virtual void Operation() {
    imple->Operation();
  }
  void SetImplementor(Implementor* imp) {
    imple = imp;
  }

protected:
  Implementor* imple;
};

class RefinedAbstract : public Abstract {
 
};

int main () {
  Abstract *ab = new RefinedAbstract;

  ConcreteImplementorA impA;
  ab->SetImplementor(&impA);
  ab->Operation();

  ConcreteImplementorB impB;
  ab->SetImplementor(&impB);
  ab->Operation();

  return 0;
}
