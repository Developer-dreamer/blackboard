#include "BoardCaretaker.h"
#include <iostream>
using namespace std;

void BoardCaretaker::save(BoardMemento memento) {
    if (current_ != history_.end()) {
        history_.erase(next(current_), history_.end());
    }
    history_.push_back(memento);
    current_ = history_.end();
}

BoardMemento BoardCaretaker::undo() {
    if (current_ == history_.begin())
    {
        cout << "No more undos left" << endl;
    }
    BoardMemento state = current_->getState();
    current_--;
    return state;
}

BoardMemento BoardCaretaker::redo() {
    if (current_ == prev(history_.end()))
    {
        cout << "No more redos left" << endl;
    }
    current_++;
    return current_->getState();
}