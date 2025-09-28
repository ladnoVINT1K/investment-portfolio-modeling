#include <iostream>

class Market {
 public:
  Market(double depositBaseRate = 0.12) : depositRate(depositBaseRate) {}
  
  double depositRate;
};