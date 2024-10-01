#include <iostream>

#include "Board.h"
#include "BoardMemento.h"
#include "BoardCaretaker.h"
#include "Figures/Rectangle.h"
#include "Figures/Triangle.h"

using namespace std;
int main() {
    Board board;
    BoardMemento memento(board.saveToMemento());
    BoardCaretaker caretaker;

    shared_ptr<IFigure> figure = make_shared<Triangle>(vector<string>{"Triangle", "3", "8", "7", "2", "12", "7"});
    board.addFigure(figure);
    board.draw();
}