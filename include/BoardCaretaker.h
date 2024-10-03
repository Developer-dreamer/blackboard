#pragma once
#include <list>
#include "BoardMemento.h"

class BoardCaretaker {
public:
    BoardCaretaker();
    void save(BoardMemento memento);
    BoardMemento undo();
    BoardMemento redo();
    void resetHistory();
private:
    list<BoardMemento> history_;
    list<BoardMemento>::iterator current_;
};
