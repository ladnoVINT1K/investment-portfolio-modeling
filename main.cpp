#include <QApplication>
#include <QMainWindow>
#include "backend/deposit.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    Bank T(bank::BankOfEngland);
    std::cout << T.getName();
}
