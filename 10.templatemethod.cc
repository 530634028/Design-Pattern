#include <iostream>

using namespace std;

class Abstract {
public:
  void show() {
    stepA();
    stepB();
  }

protected:
  virtual void stepA() {}
  virtual void stepB() {}
};

class ConcreteA : public Abstract {
  void stepA() {
    cout<<"concreteA stepA"<<endl;
  }

  void stepB() {
    cout<<"concreteA stepB"<<endl;
  }
};

class ConcreteB : public Abstract {
  void stepA() {
    cout<<"concreteB stepA"<<endl;
  }

  void stepB() {
    cout<<"concreteB stepB"<<endl;
  }
};

int main() {
  Abstract* pa = new ConcreteA;
  pa->show();

  cout<<endl;

  Abstract* pb = new ConcreteB;
  pb->show();

  return 0;
}





