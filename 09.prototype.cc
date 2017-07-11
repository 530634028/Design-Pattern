#include <iostream>
#include <string>
using namespace std;

class Prototype {
public:
  virtual Prototype* Clone() = 0;  
};

class ConcretePrototypeA : public Prototype {
public:
  Prototype* Clone() {
    ConcretePrototypeA* p = new ConcretePrototypeA;
    p->Set(name_, address_);
    return p;
  }

  void Set(string name, string address) {
    name_ = name;
    address_ = address;
  }

  void Show() {
    cout<<name_<<endl;
    cout<<address_<<endl;
  }

private:
  string name_;
  string address_;
};

int main() {
  ConcretePrototypeA p1;
  p1.Set("hello", "world");

  ConcretePrototypeA* p = (ConcretePrototypeA*)p1.Clone();
  p->Show();


  return 0;
}





