#include <string>
#include <iostream>

using namespace std;

class Handler {
public:
  virtual ~Handler() {}
  void SetSuccessor(Handler* succ) {
    successor = succ;
  }
  
  virtual void HandleRequest(string request) = 0;

protected:
  Handler* successor;
};

class ConcreteHandlerA : public Handler {
public:
  void HandleRequest(string request) {
    if(request == "leave") {
      cout<<"ConcreteHandlerA handler it, value: "<<request<<endl;
    }
    else {
      if(successor) {
        successor->HandleRequest(request);
      }
    }
  }
};

class ConcreteHandlerB : public Handler {
public:
  void  HandleRequest(string request) {
    if(request == "promotion") {
      cout<<"ConcreteHandlerB handler it, value: "<<request<<endl;
    }
    else {
      if(successor) {
        successor->HandleRequest(request);
      }
    }
  }
};

class ConcreteHandlerC : public Handler {
public:
  void HandleRequest(string request) {
    cout<<"ConcreteHandlerC handle everything, value: "<<request<<endl;
  }
};

int main() {
  ConcreteHandlerA handlerA;
  ConcreteHandlerB handlerB;
  ConcreteHandlerC handlerC;

  handlerA.SetSuccessor(&handlerB);
  handlerB.SetSuccessor(&handlerC);

  handlerA.HandleRequest("leave");
  cout<<endl;

  handlerA.HandleRequest("promotion");
  cout<<endl;

  handlerA.HandleRequest("other");
}
