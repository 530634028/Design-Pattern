#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Component {
public:
  Component(string na) : name(na) {}
  virtual void Add(Component *) {};
  virtual void Remove(Component *) {};
  virtual void Display(int depth) {};

protected:
  string name;
};

class Leaf : public Component {
public:
  Leaf(string na) : Component(na) {}
  
  void Add(Component * comp) {
    cout<<"leaf can't add"<<endl;
  }

  void Remove(Component *comp) {
    cout<<"leaf can't remove"<<endl;
  }

  void Display(int depth) {
    string bf(depth, '-');
    cout<<bf<<name<<endl;
  }
};

class Composite : public Component {
public:
  Composite(string na) : Component(na) {}

  void Add(Component* comp) {
    child.push_back(comp);
  }

  void Remove(Component* comp) {
    for(int i = 0; i < child.size(); ++i) {
      if(child[i] == comp) {
        child.erase(child.begin() + i);
        break;
      }
    }
  }

  void Display(int depth) {
    string bf(depth, '-');
    cout<<bf<<name<<endl;

    for(int i = 0; i < child.size(); ++i) {
      child[i]->Display(depth + 2);
    }
  }

private:
  vector<Component*> child;
};

int main() {
  Composite* head = new Composite("headquarter");
  Leaf *finance = new Leaf("finance department");
  Leaf *hr = new Leaf("human resource");

  head->Add(finance);
  head->Add(hr);

  Composite* branchA = new Composite("sz branch");
  Leaf *szf = new Leaf("sz finance");
  Leaf *szhr = new Leaf("sz human resouce");

  branchA->Add(szf);
  branchA->Add(szhr);

  head->Add(branchA);

  head->Display(1);

  cout<<endl;
  branchA->Remove(szf);
  head->Display(1);
  return 0;
}
