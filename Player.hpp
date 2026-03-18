#pragma once
#include <string>
#include <vector>

struct Player {
    std::string name;
    int position = 0;
    int cash = 10000;
    int salary = 0;
    std::string career = "Unemployed";
    bool hasCollege = false;
    bool isMarried = false;
    int children = 0;
    bool hasHouse = false;
    int houseValue = 0;
    bool hasInsurance = false;
    std::vector<std::string> stocks;
    int loanAmount = 0;
    bool retired = false;
    int colorPair = 5;

    void move(int spaces, int boardSize);
    void payday();
    void takeLoan(int amount);
    int calculateNetWorth() const;
};
