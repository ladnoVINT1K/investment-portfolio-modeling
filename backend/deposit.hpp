#include "investments.hpp"
#include "market.hpp"
#include <exception>
class Deposit : public Investments {
 public:
  Deposit(double initSum) : 
    sum(initSum),
    depositRate(0.0)
  {}
  
  double calculateMonthlyReturn(void) override {
    return sum + (sum * depositRate / 12.0);
  }
  
  void updateConditions(const Market& market) override {
    depositRate = market.depositRate;
    return;
  }

  void addCapital(double addMore) {
    sum += addMore;
    return;
  }

  void withdrawCapital(double takeSome) {
    if (takeSome > sum) throw(std::runtime_error("You can't take more than tou have!"));
    else {
        sum -= takeSome;
    }
  }

 private:
  double sum;
  float depositRate;
};