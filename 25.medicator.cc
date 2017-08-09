#include <iostream>

using namespace std;

class Colleague;

class Medicator {
public:
  virtual void Send(const string& message, Colleague* colleague) = 0;  
};

class Colleague {
public:
  Colleague(Medicator& medi) : medicator(medi) {}
  void Send(const string& message) {
    medicator.Send(message, this);
  }

protected:
  Medicator& medicator;
};

class ConcreteColleagueA : public Colleague {
public:
  ConcreteColleagueA(Medicator& medi) : Colleague(medi) {}
  void Notify(const string& message) {
    cout<<"ConcreteColleagueA get message: "<<message<<endl;
  }
};

class ConcreteColleagueB : public Colleague {
public:
  ConcreteColleagueB(Medicator& medi) : Colleague(medi) {}
  void Notify(const string& message) {
    cout<<"ConcreteColleagueB get message: "<<message<<endl;
  }
};

class ConcreteMedicator : public Medicator {
public:
  void Send(const string& message, Colleague* colleague) {
    if(colleague == colleagueA) {
      colleagueB->Notify(message);
    }
    else if(colleague == colleagueB) {
      colleagueA->Notify(message);
    }
  }

  void SetColleagueA(ConcreteColleagueA* ca) {
    colleagueA = ca;
  }

  void SetColleagueB(ConcreteColleagueB* cb) {
    colleagueB = cb;
  }

private:
  ConcreteColleagueA* colleagueA;
  ConcreteColleagueB* colleagueB;
};

int main() {
  ConcreteMedicator cm;
  ConcreteColleagueA cA(cm);
  ConcreteColleagueB cB(cm);

  cm.SetColleagueA(&cA);
  cm.SetColleagueB(&cB);

  cA.Send("how are you");
  cB.Send("I'm fine, and you");

  return 0;
}
