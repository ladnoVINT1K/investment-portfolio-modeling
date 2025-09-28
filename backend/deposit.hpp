#pragma once
#include "investments.hpp"
#include "market.hpp"
#include <exception>
#include "events.hpp"

enum class bank {
    FederalReserve,
    LehmanBrothers,
    JPMorgan,
    GoldmanSachs,
    CreditSuisse,
    DeutscheBank,
    UBS,
    SwissNationalBank,
    EuropeanCentralBank,
    BankOfEngland,
    BankOfJapan,
    HSBC,
    Barclays,
    MorganStanley,
    WellsFargo,
    Citigroup,
    BNPParibas,
    SocieteGenerale,
    ING,
    Santander
};

inline std::string toString(bank b) {
    switch (b) {
        case bank::FederalReserve: return "Federal Reserve";
        case bank::LehmanBrothers: return "Lehman Brothers";
        case bank::JPMorgan: return "JP Morgan";
        case bank::GoldmanSachs: return "Goldman Sachs";
        case bank::CreditSuisse: return "Credit Suisse";
        case bank::DeutscheBank: return "Deutsche Bank";
        case bank::UBS: return "UBS";
        case bank::SwissNationalBank: return "Swiss National Bank";
        case bank::EuropeanCentralBank: return "European Central Bank";
        case bank::BankOfEngland: return "Bank of England";
        case bank::BankOfJapan: return "Bank of Japan";
        case bank::HSBC: return "HSBC";
        case bank::Barclays: return "Barclays";
        case bank::MorganStanley: return "Morgan Stanley";
        case bank::WellsFargo: return "Wells Fargo";
        case bank::Citigroup: return "Citigroup";
        case bank::BNPParibas: return "BNP Paribas";
        case bank::SocieteGenerale: return "Societe Generale";
        case bank::ING: return "ING";
        case bank::Santander: return "Santander";
    }
}
class Bank : public Investments {
 public:
  Bank(bank n, double initSum = 0) : 
    sum(initSum),
    bankRate(0.0),
    name(n)
  {}
  
  ~Bank() override {}

  double getSum() {
    return sum;
  }

  double getRate() {
    return bankRate;
  }

  std::string getName(void) {
    return toString(name);
  }
  
  double calculateMonthlyReturn(void) override {
    return sum + (sum * bankRate / 12.0000);
  }
  
  void updateConditions(const Market& market) override {
    float eventCoef = 0.0f;
    auto ptr = market.eventsInThisMonth.find(toString(name));
    if (ptr != market.eventsInThisMonth.end()) {
        eventCoef = ptr->second.second;
    }
    bankRate = market.bankRate + eventCoef;
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
  bank name;
  double sum;
  double bankRate;
};
