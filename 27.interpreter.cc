#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Context {
public:
  string input;
  string output;  
};

class Interpreter {
public:
  virtual void Interprete(Context& context) = 0;
};

class TerminalExpression : public Interpreter {
public:
  void Interprete(Context& context) {
    cout<<"TerminalExpression interprete"<<endl;
  }
};

class NonTerminalExpression : public Interpreter {
public:
  void Interprete(Context& context) {
    cout<<"NonTerminalExpression interprete"<<endl;
  }
};

int main() {
  Context context;
  vector<Interpreter* > interpreter_worklist;
  interpreter_worklist.push_back(new TerminalExpression);
  interpreter_worklist.push_back(new TerminalExpression);
  interpreter_worklist.push_back(new NonTerminalExpression);
  interpreter_worklist.push_back(new TerminalExpression);

  for(auto work : interpreter_worklist) {
    work->Interprete(context);
  }

  return 0;
}
