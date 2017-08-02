#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class IteratorS {
public:
  virtual T First() = 0;
  virtual T Next() = 0;
  virtual bool IsDone() = 0;
  virtual T CurrentItem() = 0;
};

template <typename T>
class Aggregator {
public:
  virtual IteratorS<T>* CreateIterator() = 0;
};

template <typename T> class ConcreteAggregator;

template <typename T>
class ConcreteIterator : public IteratorS<T> {
public:
  ConcreteIterator(ConcreteAggregator<T>* aggr) : aggregate(aggr) {
    current = 0;
  }
  
  T First() {
    return (*aggregate)[0];
  }

  T Next() {
    ++current;
    if(current < aggregate->CountN()) {
      return (*aggregate)[current];
    }
  }

  bool IsDone() {
    return current >= aggregate->CountN() ? true : false;
  }

  T CurrentItem() {
    return (*aggregate)[current];
  }

private:
  ConcreteAggregator<T>* aggregate;
  int current;
};

template <typename T>
class ConcreteAggregator : public Aggregator<T> {
public:
  IteratorS<T>* CreateIterator() {
    return new ConcreteIterator<T>(this);
  }

  void Add(T item) {
    items.push_back(item);
  }

  T& operator[](int index) {
    if(index < items.size()) {
      return items[index];
    }
  }

  int CountN() {
    return items.size();
  }

private:
  vector<T> items;  
};

int main() {
  ConcreteAggregator<string> string_aggre;
  string_aggre.Add("hello");
  string_aggre.Add("hi");
  string_aggre.Add("what");

  IteratorS<string>* it = string_aggre.CreateIterator();

  while(!it->IsDone()) {
    cout<<it->CurrentItem()<<endl;
    it->Next();
  }

  return 0;
}


