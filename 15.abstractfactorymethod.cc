#include <iostream>

using namespace std;

class ProductA {
public:
  virtual void show() = 0;
};

class ConcreteAProductA : public ProductA {
public:
  void show() {
    cout<<"this is concreteA created productA"<<endl;
  }
};

class ConcreteBProductA : public ProductA {
  void show() {
    cout<<"this is concreteB created productA"<<endl;
  }
};

class ProductB {
public:
  virtual void display() = 0;  
};

class ConcreteAProductB : public ProductB {
public:
  void display() {
    cout<<"this is concreteA created productB"<<endl;
  }  
};

class ConcreteBProductB : public ProductB {
public:
  void display() {
    cout<<"this is concreteB created productB"<<endl;
  }  
};

class Factory {
public:
  virtual ProductA* createProductA() = 0;
  virtual ProductB* createProductB() = 0;
};

class ConcreteAFactory : public Factory {
public:
  ProductA* createProductA() {
    return new ConcreteAProductA;
  }

  ProductB* createProductB() {
    return new ConcreteAProductB;
  }
};

class ConcreteBFactory : public Factory {
public:
  ProductA* createProductA() {
    return new ConcreteBProductA;
  }

  ProductB* createProductB() {
    return new ConcreteBProductB;
  }
};

int main() {
  Factory* factoryA = new ConcreteAFactory;
  ProductA* productAa = factoryA->createProductA();
  ProductB* productBa = factoryA->createProductB();
  productAa->show();
  productBa->display();

  cout<<"------------------------"<<endl;

  Factory* factoryB = new ConcreteBFactory;
  ProductA* productAb = factoryB->createProductA();
  ProductB* productBb = factoryB->createProductB();
  productAb->show();
  productBb->display();

  return 0;
}


