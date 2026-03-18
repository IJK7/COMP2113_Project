#include "Board.hpp"

void Board::loadBoard() {
    spaces.clear();
    path.clear();
    width = 72;
    height = 18;

    // Outer loop rectangle.
    for (int x = 2; x <= 66; ++x) path.push_back({1, x});
    for (int y = 2; y <= 14; ++y) path.push_back({y, 66});
    for (int x = 65; x >= 2; --x) path.push_back({14, x});
    for (int y = 13; y >= 4; --y) path.push_back({y, 2});

    // Inner loop rectangle.
    for (int x = 8; x <= 58; ++x) path.push_back({4, x});
    for (int y = 5; y <= 10; ++y) path.push_back({y, 58});
    for (int x = 57; x >= 8; --x) path.push_back({10, x});
    for (int y = 9; y >= 6; --y) path.push_back({y, 8});

    // Connector to "retirement" center.
    for (int x = 12; x <= 30; ++x) path.push_back({7, x});
    for (int y = 7; y <= 12; ++y) path.push_back({y, 30});
    for (int x = 30; x <= 40; ++x) path.push_back({12, x});

    std::vector<SpaceType> pattern = {
        SpaceType::START, SpaceType::COLLEGE, SpaceType::CAREER, SpaceType::PAYDAY,
        SpaceType::MARRIAGE, SpaceType::BABY, SpaceType::CHANCE, SpaceType::HOUSE,
        SpaceType::PAYDAY, SpaceType::STOCK, SpaceType::INSURANCE, SpaceType::VACATION,
        SpaceType::CHANCE, SpaceType::LAWSUIT, SpaceType::JOB_LOSS, SpaceType::PAYDAY,
        SpaceType::TAX_RETURN, SpaceType::HOUSE, SpaceType::CHANCE, SpaceType::CAREER
    };

    for (size_t i = 0; i < path.size(); ++i) {
        SpaceType t = pattern[i % pattern.size()];
        std::string name = "SPACE";
        switch (t) {
            case SpaceType::START: name = "START"; break;
            case SpaceType::COLLEGE: name = "COLLEGE"; break;
            case SpaceType::CAREER: name = "CAREER"; break;
            case SpaceType::MARRIAGE: name = "MARRIAGE"; break;
            case SpaceType::HOUSE: name = "HOUSE"; break;
            case SpaceType::BABY: name = "BABY"; break;
            case SpaceType::STOCK: name = "STOCK"; break;
            case SpaceType::INSURANCE: name = "INSURANCE"; break;
            case SpaceType::PAYDAY: name = "PAYDAY"; break;
            case SpaceType::TAX_RETURN: name = "TAX"; break;
            case SpaceType::VACATION: name = "VACATION"; break;
            case SpaceType::LAWSUIT: name = "LAWSUIT"; break;
            case SpaceType::JOB_LOSS: name = "JOB LOSS"; break;
            case SpaceType::RETIREMENT: name = "RETIRE"; break;
            case SpaceType::CHANCE: name = "CHANCE"; break;
        }
        spaces.push_back({name, t});
    }

    if (!spaces.empty()) {
        spaces.back() = {"RETIRE", SpaceType::RETIREMENT};
    }
}

void Board::display(WINDOW* win, const std::vector<Player>& players) {
    werase(win);
    box(win, 0, 0);

    // Draw board path.
    for (size_t i = 0; i < path.size(); ++i) {
        char ch = '.';
        SpaceType t = spaces[i].type;
        switch (t) {
            case SpaceType::START: ch = 'S'; break;
            case SpaceType::COLLEGE: ch = 'C'; break;
            case SpaceType::CAREER: ch = 'R'; break;
            case SpaceType::MARRIAGE: ch = 'M'; break;
            case SpaceType::HOUSE: ch = 'H'; break;
            case SpaceType::BABY: ch = 'B'; break;
            case SpaceType::STOCK: ch = 'K'; break;
            case SpaceType::INSURANCE: ch = 'I'; break;
            case SpaceType::PAYDAY: ch = 'P'; break;
            case SpaceType::TAX_RETURN: ch = 'T'; break;
            case SpaceType::VACATION: ch = 'V'; break;
            case SpaceType::LAWSUIT: ch = 'L'; break;
            case SpaceType::JOB_LOSS: ch = 'J'; break;
            case SpaceType::RETIREMENT: ch = 'X'; break;
            case SpaceType::CHANCE: ch = '?'; break;
        }
        mvwaddch(win, path[i].y, path[i].x, ch);
    }

    // Draw players.
    for (size_t i = 0; i < players.size(); ++i) {
        int idx = players[i].position % static_cast<int>(path.size());
        int py = path[idx].y;
        int px = path[idx].x;
        if (has_colors()) wattron(win, COLOR_PAIR(players[i].colorPair));
        mvwaddch(win, py, px, '1' + static_cast<int>(i));
        if (has_colors()) wattroff(win, COLOR_PAIR(players[i].colorPair));
    }

    mvwprintw(win, height - 2, 2,
              "Legend: S START  P PAYDAY  R CAREER  M MARRIAGE  B BABY  H HOUSE  ? CHANCE  X RETIRE");
    wrefresh(win);
}

Space Board::getSpace(int position) const {
    return spaces[position % spaces.size()];
}
