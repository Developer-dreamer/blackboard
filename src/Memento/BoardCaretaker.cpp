#include "BoardCaretaker.h"
#include <iostream>
using namespace std;

BoardCaretaker::BoardCaretaker()
{
    history_ = list<BoardMemento>();
    current_ = history_.end();
}

void BoardCaretaker::save(BoardMemento memento) {
    if (current_ != history_.end()) {
        history_.erase(next(current_), history_.end());
    }
    history_.push_back(memento);
    current_ = prev(history_.end());
}

BoardMemento BoardCaretaker::undo() {
    if (current_ == history_.begin())
    {
        cout << "No more undos left" << endl;
        return *current_;
    }
    --current_;
    auto result = *current_;
    return result;
}

BoardMemento BoardCaretaker::redo() {
    if (current_ == prev(history_.end()))
    {
        cout << "No more redos left" << endl;
        return *current_;
    }
    ++current_;
    return *current_;
}

void BoardCaretaker::resetHistory()
{
    history_.clear();
    current_ = history_.end();
}
