#include <iostream>
using namespace std;

class Product {
public:
  virtual void show() = 0;
};

class ConcreteProductA : public Product {
public:
  void show() {
    cout<<"ConcreteProductA thing"<<endl;
  }
};

///////////////////////

class Factory {
public:
  virtual Product* createProduct() = 0;
};

class ConcreteProductAFactory : public Factory {
public:
  Product* createProduct() {
    return new ConcreteProductA();
  }
};

int main() {
  Factory* f = new ConcreteProductAFactory();
  Product* p = f->createProduct();
  p->show();

  return 0;
}





