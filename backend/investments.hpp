#pragma once
#include <string>
#include <iostream>
#include "market.hpp"

class Investments {
 public:
  virtual double calculateMonthlyReturn() = 0;
  virtual void updateConditions(const Market& market) = 0;
  virtual ~Investments() {}
};
