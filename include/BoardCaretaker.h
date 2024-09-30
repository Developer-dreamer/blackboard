#pragma once
#include <list>
#include "BoardMemento.h"

class BoardCaretaker {
public:
    void save(BoardMemento memento);
    BoardMemento undo();
    BoardMemento redo();
private:
    list<BoardMemento> history_;
    list<BoardMemento>::iterator current_;
};
