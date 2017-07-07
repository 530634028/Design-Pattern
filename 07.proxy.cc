#include <iostream>
using namespace std;

class Subject {
public:
  virtual void request() = 0;
};

class ConcreteSubject : public Subject {
public:
  void request() {cout<<"ConcreteSubject thing"<<endl;}  
};

class Proxy : public Subject {
public:
  Proxy() : subject_(NULL) {}

  void request() {
    if(!subject_) {
      subject_ = new ConcreteSubject();
      cout<<"subject initialized"<<endl;
    }
    subject_->request();
  }

private:
  ConcreteSubject* subject_;
};

int main() {
  Proxy proxy;
  proxy.request();
  proxy.request();

  return 0;
}
