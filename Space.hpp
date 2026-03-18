#pragma once
#include <string>

enum class SpaceType {
    START, COLLEGE, CAREER, MARRIAGE, HOUSE, BABY, STOCK, INSURANCE,
    PAYDAY, TAX_RETURN, VACATION, LAWSUIT, JOB_LOSS, RETIREMENT, CHANCE
};

struct Space {
    std::string name;
    SpaceType type;
};
