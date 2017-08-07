#include <iostream>

using namespace std;

class Receiver {
public:
  void Action() {
    cout<<"Receiver do the work"<<endl;
  }  
};

class Command {
public:
  Command(Receiver* receiver) : receiver_(receiver) {}
  virtual void Execute() = 0;

protected:
  Receiver* receiver_;
};

class ConcreteCommand : public Command {
public:
  ConcreteCommand(Receiver* receiver) : Command(receiver) {}
  void Execute() {
    receiver_->Action();
  }
};

class Invoker {
public:
  void SetCommand(Command* command) {
    command_ = command;
  }

  void ExecuteCommand() {
    command_->Execute();
  }
private:
  Command* command_;  
};

int main() {
  Receiver receiver;
  ConcreteCommand ccom(&receiver);

  Invoker invoker;
  invoker.SetCommand(&ccom);
  invoker.ExecuteCommand();

  return 0;
}


