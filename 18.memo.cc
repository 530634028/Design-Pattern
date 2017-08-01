#include <iostream>

using namespace std;

class Momento {
public:
  Momento(int st) : state(st) {}
  int state;
};

class Originator {
public:
  void SetState(int st) {
    state = st;
  }

  Momento* CreateMemo() {
    Momento* memo = new Momento(state);
    return memo;
  }

  void Restore(Momento* memo) {
    state = memo->state;
  }

  void Show() {
    cout<<"current state is "<<state<<endl;
  }

private:
  int state;
};

class CareMemo {
public:
  Momento* memo;
};


int main() {
  Originator org;
  org.SetState(100);
  org.Show();

  CareMemo cm;
  cm.memo = org.CreateMemo();

  org.SetState(59);
  org.Show();

  org.Restore(cm.memo);
  org.Show();

  return 0;
}

