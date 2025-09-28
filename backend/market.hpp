#pragma once
#include <iostream>
#include <experimental/random>
#include <vector>
#include "events.hpp"
class Market {
 public:
  Market() : 
    bankRate(0.09),
    companies(0.14),
    stockRate(0.11) 
  {}
  
  void updateEvent(void) {
    eventsInThisMonth = {};
    for (int i = 0; i < 4; ++i) {
        auto ev = getRandomEvent();
        std::pair<std::string, std::pair<std::string, float>> event{ev.first.second, {ev.first.first, ev.second}}; 
        eventsInThisMonth.insert(event);
    }
  }

  void simulateMonth(void) {
    bankRate = bankRate * (std::experimental::randint(-5, 5) * 0.01f);
    companies = companies * (std::experimental::randint(-10, 10) * 0.001f);
    stockRate = stockRate * (std::experimental::randint(-5, 5) * 0.01f);
    updateEvent();
  }

  double bankRate;
  double companies;
  double stockRate;
  std::map<std::string, std::pair<std::string, float>> eventsInThisMonth;
};