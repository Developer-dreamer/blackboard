#pragma once
#include <memory>
#include <vector>

#include "Board.h"
#include "src/Helper/ColoredChar.h"
#include "IFigure.h"
using namespace std;

class BoardMemento {
public:
    using board_state = tuple<vector<vector<ColoredChar>>, vector<shared_ptr<IFigure>>>;

    BoardMemento(board_state state)
        : state_(state){}

    board_state getState() const;
private:
    board_state state_;
};
