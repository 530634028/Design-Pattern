#include <iostream>

using namespace std;

class Singleton {
public:
  static Singleton* GetInstance() {
    if(!s) {
      s = new Singleton;
    }
    return s;
  }

private:
  Singleton() {};
  static Singleton* s;
};

class SingletonTwo {
public:
  static SingletonTwo& GetInstance() {
    static SingletonTwo st;
    return st;
  }

private:
  SingletonTwo() {};
};

Singleton* Singleton::s = NULL;

int main() {
  Singleton* s1 = Singleton::GetInstance();
  Singleton* s2 = Singleton::GetInstance();

  if(s1 == s2) cout<<"get the same Singleton"<<endl;
  cout<<endl;

  SingletonTwo& stwo1 = SingletonTwo::GetInstance();
  SingletonTwo& stwo2 = SingletonTwo::GetInstance();

  if(&stwo1 == &stwo2) cout<<"get the same SingletonTwo"<<endl;

  return 0;
}
