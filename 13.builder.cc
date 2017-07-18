#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Product {
public:
  void addComponent(string com) {
    components.push_back(com);
  }

  void show() {
    for(int i = 0; i < components.size(); ++i) {
      cout<<components[i]<<endl;
    }
  }

private:
  vector<string> components;  
};

class Build {
public:
  virtual void buildPartA() = 0;
  virtual void buildPartB() = 0;

  Product getProduct() {return product;}

protected:
  Product product;  
};

class ConcreteBuildA : public Build {
public:
    void buildPartA() {
      product.addComponent("concreteA build part A");
    }

    void buildPartB() {
      product.addComponent("concreteA build part B");
    }
};

class ConcreteBuildB : public Build {
public:
    void buildPartA() {
      product.addComponent("concreteB build part A");
    }

    void buildPartB() {
      product.addComponent("concreteB build part B");
    }
};

class Director {
public:
  Product buildProduct(Build* build) {
    build->buildPartA();
    build->buildPartB();
    
    return build->getProduct();
  }
};

int main() {
  ConcreteBuildA buildA;
  ConcreteBuildB buildB;
  Director direct;

  Product pA = direct.buildProduct(&buildA);
  pA.show();

  Product pB = direct.buildProduct(&buildB);
  pB.show();

  return 0;
}
