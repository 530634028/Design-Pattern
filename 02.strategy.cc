#include <iostream>

using namespace std;

class Strategy {
public:
  virtual ~Strategy() {}
  virtual double getResult(double money)  = 0;
};

class StrategyNormal : public Strategy {
public:
  double getResult(double money) {
    return money;
  }  
};

class StrategyRebate : public Strategy {
public:
  StrategyRebate(double cond, double reb) : condition(cond), rebate(reb) {}
  double getResult(double money) {
    return money - int(money/condition) * rebate;
  }

private:
  double condition;
  double rebate;
};

class StrategyDiscount : public Strategy {
public:
  StrategyDiscount(double dis) : discount(dis) {}
  double getResult(double money) {
    return money * discount;
  }

private:
  double discount;
};

class Context {
public:
  Context(Strategy *stg) : strategy(stg) {}
  ~Context() {
    if(strategy) delete strategy;
  }

  double compute(double money) {
    return strategy->getResult(money);
  }

private:
  Strategy *strategy;
};

int main() {
  Context a(new StrategyNormal());
  Context b(new StrategyRebate(300, 100));
  Context c(new StrategyDiscount(0.8));

  int val = 600;

  cout<<a.compute(val)<<endl;
  cout<<b.compute(val)<<endl;
  cout<<c.compute(val)<<endl;
}
