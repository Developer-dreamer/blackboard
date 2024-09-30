#include <iostream>

#include "Board.h"
#include "BoardMemento.h"
#include "BoardCaretaker.h"

using namespace std;
int main() {
    Board board;
    BoardMemento memento(board.saveToMemento());
    BoardCaretaker caretaker;
}