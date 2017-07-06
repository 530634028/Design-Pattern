#include <iostream>
using namespace std;

class Component {
public:
  virtual void show() = 0;
};

class ConcreteComponent : public Component {
public:
  void show() {cout<<"ConcreteComponent thing"<<endl;}
};

class Decorator : public Component {
public:
  void SetComponent(Component *comp) {
    pcomp = comp;
  }

  void show() {pcomp->show();}

private:
  Component *pcomp;
};

class ConcreteDecoratorA : public Decorator {
public:
  void show() {
    cout<<"ConcreteDecoratorA before"<<endl;
    Decorator::show();
    cout<<"ConcreteDecoratorA after"<<endl;
  }
};

class ConcreteDecoratorB : public Decorator {
public:
  void show() {
    cout<<"ConcreteDecoratorB before"<<endl;
    Decorator::show();
  }
};

class ConcreteDecoratorC : public Decorator {
public:
  void show() {
    Decorator::show();
    cout<<"ConcreteDecoratorC after"<<endl;
  }
};


int main() {
  ConcreteComponent com;
  ConcreteDecoratorA deca;
  ConcreteDecoratorB decb;
  ConcreteDecoratorC decc;

  deca.SetComponent(&com);
  decb.SetComponent(&deca);
  decc.SetComponent(&decb);

  decc.show();

  return 0;
}
