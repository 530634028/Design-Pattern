#include <iostream>

using namespace std;

class Operation {
public:
  virtual int getResult() = 0;
  void set(int a, int b) {
    left = a;
    right = b;
  } 

protected:
  int left;
  int right;
};

class Multiply : public Operation {
public:
  int getResult() {
    return left * right;
  }
};

class Add : public Operation {
public:
  int getResult() {
    return left + right;
  }
};

class Subtract : public Operation {
public:
  int getResult() {
    return left - right;
  }
};

class Divide : public Operation {
public:
  int getResult() {
    if(right != 0) {
      return left / right;
    }
    else {
      return 0;
    }
  }
};

class SimpleFactory {
public:
  static Operation* CreateOperation(char type) {
    Operation* result = NULL;
    switch(type) {
      case '+':
      result = new Add();
      break;
      case '-':
      result = new Subtract();
      break;
      case '*':
      result = new Multiply();
      break;
      case '/':
      result = new Divide();
      break;
    }

    return result;
  }
};

int main() {
  int a, b;
  char type;
  cin>>a>>type>>b;

  Operation *oper = SimpleFactory::CreateOperation(type);
  oper->set(a,b);
  cout<<oper->getResult()<<endl;

  return 0;
}
