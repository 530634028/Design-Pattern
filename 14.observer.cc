#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Subject;

class Observer {
public:
  Observer(Subject& sub) : subject(sub) {}
  virtual void update() = 0;

protected:
  Subject& subject;
};

class Subject {
public:
  virtual void add(Observer* ob) = 0;
  virtual void remove(Observer* ob) = 0;
  virtual void notifyAll() = 0;
  virtual void setState(string state) {
    state_ = state;
  }

  string state_;
};


class ConcreteSubjectA : public Subject {
public:  
  void add(Observer* ob) {
    all_observers.push_back(ob);
  }

  void remove(Observer* ob) {
    for(int i = 0; i < all_observers.size(); ++i) {
      if(all_observers[i] == ob) {
        all_observers.erase(all_observers.begin() + i);
        break;
      }
    }
  }

  void notifyAll() {
    for(int i = 0; i < all_observers.size(); ++i) {
      all_observers[i]->update();
    }
  }

private:
  vector<Observer*> all_observers;
};


class ConcreteSubjectB : public Subject {
public:  
  void add(Observer* ob) {
    all_observers.push_back(ob);
  }

  void remove(Observer* ob) {
    for(int i = 0; i < all_observers.size(); ++i) {
      if(all_observers[i] == ob) {
        all_observers.erase(all_observers.begin() + i);
        break;
      }
    }
  }

  void notifyAll() {
    for(int i = all_observers.size() - 1; i >= 0 ; --i) {
      all_observers[i]->update();
    }
  }

private:
  vector<Observer*> all_observers;
};



class ConcreteObserverA : public Observer {
public:
  ConcreteObserverA(Subject& sub) : Observer(sub) {}
  void update() {
    cout<<subject.state_<<" ";
    cout<<"update ConcreteObserverA"<<endl;
  }
};

class ConcreteObserverB : public Observer {
public:
  ConcreteObserverB(Subject& sub) : Observer(sub) {}
  void update() {
    cout<<subject.state_<<" ";
    cout<<"update ConcreteObserverB"<<endl;
  }

};



int main() {
  ConcreteSubjectB subjectB;

  ConcreteObserverA obA(subjectB);
  ConcreteObserverB obB(subjectB);

  subjectB.add(&obA);
  subjectB.add(&obB);

  subjectB.setState("haha, come back");

  subjectB.notifyAll();

  subjectB.remove(&obA);
  subjectB.notifyAll();

  return 0;
}


