#include "Player.hpp"

void Player::move(int spaces, int boardSize) {
    position = (position + spaces) % boardSize;
}

void Player::payday() {
    cash += salary;
}

void Player::takeLoan(int amount) {
    loanAmount += amount;
    cash += amount;
}

int Player::calculateNetWorth() const {
    int stockValue = static_cast<int>(stocks.size()) * 10000;
    return cash + houseValue + (salary * 5) + stockValue - loanAmount;
}
