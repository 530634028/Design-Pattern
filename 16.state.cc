#include <iostream>
using namespace std;

class State;
class StepA;
class StepB;
class StepC;

class Job {
public:
  Job();
  void Do();
  void SetState(State *state);
  int step_;

private:
  State *state_;
};

class State {
public:
  virtual ~State() {}
  virtual void Do(Job *jb) = 0;
};

class StepA : public State {
public:
  void Do(Job *jb);
};

class StepB : public State {
public:
  void Do(Job *jb);
};

class StepC : public State {
public:
  void Do(Job *jb);
};

Job::Job() {
  state_ = new StepA;
}

void Job::Do() {
  if(state_)
    state_->Do(this);
}

void Job::SetState(State *state) {
  if(state_) delete state_;
  state_ = state;
}

void StepA::Do(Job *jb) {
  if(jb->step_ == 1) cout<<"now it is step one"<<endl;
  else {
    jb->SetState(new StepB);
    jb->Do();
  }
}

void StepB::Do(Job *jb) {
  if(jb->step_ == 2) cout<<"now it is step two"<<endl;
  else {
    jb->SetState(new StepC);
    jb->Do();
  }
}

void StepC::Do(Job *jb) {
  cout<<"now it is step default"<<endl;
}

int main() {
  Job job;
  job.step_ = 1;
  job.Do();

  job.step_ = 2;
  job.Do();

  job.step_ = 3;
  job.Do();
  return 0;
}

