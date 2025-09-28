#include <QApplication>
#include <QMainWindow>
#include "backend/deposit.hpp"
#include "backend/events.hpp"
#include "backend/market.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    Market MAIN;

    std::cout << "FIRST MONTH" << std::endl;
    MAIN.simulateMonth();
    for (auto i : MAIN.eventsInThisMonth) {
        std::cout << i.first << " " << i.second.first << " " << i.second.second;
    }

    Bank BankOfJapan(bank::BankOfJapan, 100.0);
    std::cout << std::endl << MAIN.bankRate << std::endl;
    BankOfJapan.updateConditions(MAIN);
    std::cout << BankOfJapan.calculateMonthlyReturn() << ' ' << BankOfJapan.getRate();
}
