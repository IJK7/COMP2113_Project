#pragma once
#include <vector>
#include <string>
#include "Card.hpp"

class Deck {
    std::vector<Card> cards;
    size_t currentIndex = 0;

public:
    void shuffle();
    Card drawCard();
    void replenish();
    void loadFromFile(const std::string& path, CardType type);
};
