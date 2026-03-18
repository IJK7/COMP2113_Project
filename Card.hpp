#pragma once
#include <string>

enum class CardType { CHANCE, CAREER, HOUSE };

struct Card {
    CardType type = CardType::CHANCE;
    std::string title;
    std::string description;

    int amount = 0;
    int salary = 0;
    bool requiresDegree = false;
    int price = 0;
    int value = 0;
};
