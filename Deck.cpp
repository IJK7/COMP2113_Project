#include "Deck.hpp"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
    currentIndex = 0;
}

Card Deck::drawCard() {
    if (cards.empty()) return Card{};
    if (currentIndex >= cards.size()) currentIndex = 0;
    return cards[currentIndex++];
}

void Deck::replenish() {
    currentIndex = 0;
}

void Deck::loadFromFile(const std::string& path, CardType type) {
    cards.clear();
    std::ifstream in(path);
    if (!in.good()) return;

    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        Card c;
        c.type = type;

        if (type == CardType::CAREER) {
            std::string title, salaryStr, baseStr, reqStr;
            std::getline(ss, title, ',');
            std::getline(ss, salaryStr, ',');
            std::getline(ss, baseStr, ',');
            std::getline(ss, reqStr, ',');
            c.title = title;
            c.salary = std::stoi(salaryStr);
            c.requiresDegree = (reqStr.find("degree") != std::string::npos || reqStr == "1");
        } else if (type == CardType::HOUSE) {
            std::string title, priceStr, valueStr;
            std::getline(ss, title, ',');
            std::getline(ss, priceStr, ',');
            std::getline(ss, valueStr, ',');
            c.title = title;
            c.price = std::stoi(priceStr);
            c.value = std::stoi(valueStr);
        } else {
            std::string title, desc, amt;
            std::getline(ss, title, ',');
            std::getline(ss, desc, ',');
            std::getline(ss, amt, ',');
            c.title = title;
            c.description = desc;
            c.amount = std::stoi(amt);
        }

        cards.push_back(c);
    }
}
