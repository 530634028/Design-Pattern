#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor {
public:
  virtual void visitConcreteElementA(ConcreteElementA* ) = 0;
  virtual void visitConcreteElementB(ConcreteElementB* ) = 0;
};

class Element {
public:
  virtual void accept(Visitor* ) = 0;
};

class ConcreteElementA : public Element {
public:
  ConcreteElementA(string name) : name_(name) {}
  void accept(Visitor* visitor) {
    visitor->visitConcreteElementA(this);
  }

  string name_;
};

class ConcreteElementB : public Element {
public:
  ConcreteElementB(string name) : name_(name) {}
  void accept(Visitor* visitor) {
    visitor->visitConcreteElementB(this);
  }

  string name_;
};

class ConcreteVisitor1 : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA* ce) {
      cout<<"this is visitor1, visit A "<<ce->name_<<endl;
    }
    void visitConcreteElementB(ConcreteElementB* ce) {
      cout<<"this is visitor1, visit B "<<ce->name_<<endl;
    }
};

class ConcreteVisitor2 : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA* ce) {
      cout<<"this is visitor2, visit A "<<ce->name_<<endl;
    }
    void visitConcreteElementB(ConcreteElementB* ce) {
      cout<<"this is visitor2, visit B "<<ce->name_<<endl;
    }
};

class ElementCollection {
public:
  void Add(Element* element) {
    collect.push_back(element);
  }

  void Accept(Visitor* visitor) {
    for(auto it : collect) {
      it->accept(visitor);
    }
  }

private:
  vector<Element*> collect;  
};


int main() {
  ElementCollection ecollect;
  ConcreteElementA ela("haha");
  ConcreteElementB elb("wowo");

  ecollect.Add(&ela);
  ecollect.Add(&elb);

  ConcreteVisitor1 visitor1;
  ConcreteVisitor2 visitor2;

  ecollect.Accept(&visitor1);
  ecollect.Accept(&visitor2);

  return 0;
}
