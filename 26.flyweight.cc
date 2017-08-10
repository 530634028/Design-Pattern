#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class FlyWeight {
public:
  virtual void Operation(int extrinc) = 0;  
};

class ConcreteFlyWeight : public FlyWeight {
public:
  void Operation(int extrinc) {
    cout<<"ConcreteFlyWeight do some action according to extrinc: "<<extrinc<<endl;
  }
};

class UnsharedConcreteFlyWeight : public FlyWeight {
public:
  void Operation(int extrinc) {
    cout<<"UnsharedConcreteFlyWeight do some action according to extrinc: "<<extrinc<<endl;
  }
};

class FlyWeightFactory {
public:
  FlyWeight* GetFlyWeight(string key) {
    if(FlyWeight_map.count(key) == 0) {
      FlyWeight_map[key] = new ConcreteFlyWeight;
    }
    return FlyWeight_map[key];
  }

  size_t Count() {
    return FlyWeight_map.size();
  }

private:
  unordered_map<string, FlyWeight*> FlyWeight_map;
};

int main() {
  int extrinc = 50;
  FlyWeightFactory ff;
  cout<<"size is "<<ff.Count()<<endl;
  FlyWeight* f1 = ff.GetFlyWeight("haha");
  f1->Operation(extrinc);
  cout<<"size is "<<ff.Count()<<endl;

  FlyWeight* f2 = ff.GetFlyWeight("haha");
  f2->Operation(extrinc);
  cout<<"size is "<<ff.Count()<<endl;

  FlyWeight* f3 = ff.GetFlyWeight("wowo");
  f3->Operation(extrinc);
  cout<<"size is "<<ff.Count()<<endl;

  FlyWeight* f4 = ff.GetFlyWeight("wowo");
  f4->Operation(extrinc);
  cout<<"size is "<<ff.Count()<<endl;

  FlyWeight* f5 = ff.GetFlyWeight("haha");
  f5->Operation(extrinc);
  cout<<"size is "<<ff.Count()<<endl;

  FlyWeight* f6 = ff.GetFlyWeight("wowo");
  f6->Operation(extrinc);
  cout<<"size is "<<ff.Count()<<endl;

  return 0;
}
