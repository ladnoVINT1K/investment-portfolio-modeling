#pragma once
#include <iostream>
#include <experimental/random>
#include <vector>
#include "events.hpp"

class Market {
 public:
  Market(double bankBaseRate = 0.12) : bankRate(bankBaseRate) {}
  
  void updateEvent(void) {
    for (int i = 0; i < 4; ++i) {
        auto ev = getRandomEvent();
        std::pair<std::string, std::pair<std::string, float>> event{ev.first.first, {ev.first.second, ev.second}};
    }
  }

  void simulateMonth(void) {
    bankRate = bankRate * (std::experimental::randint(-5, 5) * 0.01f);
    companies = companies * (std::experimental::randint(-10, 10) * 0.001f);
    stockRate = stockRate * (std::experimental::randint(-5, 5) * 0.01f);
  }

  double bankRate;
  double companies;
  double stockRate;
  std::vector< std::pair<std::string, std::pair<std::string, float>> > eventsInThisMonth();
};