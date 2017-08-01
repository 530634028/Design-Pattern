#include <iostream>

using namespace std;

class Target {
public:
  virtual void show() = 0;
};

class Adaptee {
public:
  void showhello() {cout<<"hello"<<endl;}  
};

class Adaptor : public Target {
public:
  Adaptor() : ad(new Adaptee) {}
  ~Adaptor() {delete ad;}

  void show() {
    ad->showhello();
  }

private:
  Adaptee* ad;  
  
};

int main() {
  Adaptor adp;
  adp.show();

  return 0;
}
