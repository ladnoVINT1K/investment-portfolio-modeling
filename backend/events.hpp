#pragma once
#include <random>
#include <ctime>
#include <map>
#include <string>
#include <iostream>

std::map<std::pair<std::string, std::string>, float> events = {
    // ===== 1. BANKS =====
    {{"Federal Reserve raised interest rates", "Federal Reserve"}, -0.05f},
    {{"Federal Reserve cut interest rates", "Federal Reserve"}, 0.07f},
    {{"Lehman Brothers collapsed", "Lehman Brothers"}, -0.45f},
    {{"JP Morgan posted record profits", "JP Morgan"}, 0.12f},
    {{"Goldman Sachs fined by regulators", "Goldman Sachs"}, -0.08f},
    {{"Credit Suisse announced restructuring", "Credit Suisse"}, -0.04f},
    {{"Deutsche Bank recovered after crisis", "Deutsche Bank"}, 0.05f},
    {{"UBS acquired Credit Suisse", "UBS"}, 0.09f},
    {{"Swiss National Bank intervened in market", "Swiss National Bank"}, -0.03f},
    {{"European Central Bank boosted liquidity", "European Central Bank"}, 0.06f},
    {{"Bank of England tightened monetary policy", "Bank of England"}, -0.04f},
    {{"Bank of Japan expanded stimulus", "Bank of Japan"}, 0.08f},
    {{"HSBC expanded into Asia", "HSBC"}, 0.07f},
    {{"Barclays faced money laundering scandal", "Barclays"}, -0.06f},
    {{"Morgan Stanley increased investment banking revenue", "Morgan Stanley"}, 0.10f},
    {{"Wells Fargo faced fake accounts scandal", "Wells Fargo"}, -0.09f},
    {{"Citigroup increased dividends", "Citigroup"}, 0.05f},
    {{"BNP Paribas settled sanctions violations", "BNP Paribas"}, -0.07f},
    {{"Societe Generale faced derivative losses", "Societe Generale"}, -0.08f},
    {{"ING Bank invested in green finance", "ING"}, 0.06f},
    {{"Santander expanded digital banking", "Santander"}, 0.07f},

    // ===== 2. COMPANIES =====
    {{"Bill Gates secured funding", "Microsoft"}, 0.06f},
    {{"Microsoft acquired LinkedIn", "Microsoft"}, 0.08f},
    {{"Apple launched the first iPhone", "Apple"}, 0.25f},
    {{"Apple lost a major lawsuit", "Apple"}, -0.09f},
    {{"Google announced Android", "Google"}, 0.18f},
    {{"Google faced antitrust lawsuit", "Google"}, -0.07f},
    {{"Tesla unveiled new electric car", "Tesla"}, 0.15f},
    {{"Tesla recalled faulty batteries", "Tesla"}, -0.12f},
    {{"Amazon expanded cloud services", "Amazon"}, 0.14f},
    {{"Amazon faced worker strike", "Amazon"}, -0.06f},
    {{"Facebook rebranded to Meta", "Meta"}, 0.09f},
    {{"Meta faced privacy scandal", "Meta"}, -0.10f},
    {{"Netflix grew subscriber base", "Netflix"}, 0.12f},
    {{"Netflix stock fell after weak earnings", "Netflix"}, -0.08f},
    {{"Pfizer approved COVID-19 vaccine", "Pfizer"}, 0.22f},
    {{"Pfizer faced supply chain issues", "Pfizer"}, -0.05f},
    {{"ExxonMobil expanded oil drilling", "ExxonMobil"}, 0.07f},
    {{"ExxonMobil faced environmental lawsuit", "ExxonMobil"}, -0.11f},
    {{"Boeing launched new aircraft", "Boeing"}, 0.10f},
    {{"Boeing grounded planes after crashes", "Boeing"}, -0.20f},
    {{"Nvidia unveiled new GPUs", "Nvidia"}, 0.16f},
    {{"Intel delayed chip production", "Intel"}, -0.12f},

    // ===== 3. CURRENCIES & GOLD =====
    {{"US improved trade relations", "USD"}, 0.08f},
    {{"US imposed tariffs on China", "USD"}, -0.09f},
    {{"Brexit referendum passed", "GBP"}, -0.12f},
    {{"Brexit trade deal signed", "GBP"}, 0.07f},
    {{"Japan increased exports", "JPY"}, 0.04f},
    {{"Japan faced natural disaster", "JPY"}, -0.10f},
    {{"India boosted IT exports", "INR"}, 0.09f},
    {{"India banned certain imports", "INR"}, -0.05f},
    {{"Germany led EU economic growth", "EUR"}, 0.06f},
    {{"France faced pension strikes", "EUR"}, -0.04f},
    {{"Oil crisis hit markets", "Brent"}, -0.12f},
    {{"OPEC cut oil production", "Brent"}, 0.10f},
    {{"Russia increased gas exports", "RUB"}, 0.07f},
    {{"Russia faced sanctions on oil", "RUB"}, -0.15f},
    {{"Saudi Arabia expanded oil output", "SAR"}, -0.05f},
    {{"China launched digital yuan", "CNY"}, 0.11f},
    {{"Brazil boosted soybean exports", "BRL"}, 0.09f},
    {{"Australia expanded mining sector", "AUD"}, 0.07f},
    {{"Gold prices surged during crisis", "XAU"}, 0.11f},
    {{"Turkey faced currency crisis", "TRY"}, -0.28f},
    {{"Turkey stabilized interest rates", "TRY"}, 0.10f},
    {{"Argentina defaulted on debt", "ARS"}, -0.22f},
    {{"Argentina secured IMF bailout", "ARS"}, 0.08f},
    {{"South Africa boosted gold exports", "ZAR"}, 0.07f},
    {{"Mexico signed new trade agreement", "MXN"}, 0.11f},
    {{"Canada expanded energy exports", "CAD"}, 0.09f},
    {{"Canada faced housing bubble risks", "CAD"}, -0.06f},
    {{"South Korea expanded semiconductor exports", "KRW"}, 0.13f},
    {{"South Korea faced cyberattack", "KRW"}, -0.08f},
    {{"Crypto market crashed", "BTC"}, -0.25f},
    {{"Crypto market recovered", "BTC"}, 0.19f},
    {{"Ethereum upgraded to Proof of Stake", "ETH"}, 0.16f},
    {{"FTX exchange collapsed", "Crypto"}, -0.32f}
};

std::pair<std::pair<std::string, std::string>, float> getRandomEvent() {
    static std::mt19937 gen(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution<> dist(0, events.size() - 1);

    int randomIndex = dist(gen);

    auto it = events.begin();
    std::advance(it, randomIndex); 
    return *it;
}
