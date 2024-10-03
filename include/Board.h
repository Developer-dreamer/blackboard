#pragma once
#include "IFigure.h"
#include <iostream>
#include <vector>
#include <memory>
#include "BoardMemento.h"
using namespace std;

class BoardMemento;
class FileProcessor;

class Board {
public:
    Board();
    void draw() const;
    void clear();
    void getAllFigures() const;
    void getAllShapes() const;
    void addFigure(shared_ptr<IFigure> figure);
    void save() const;
    void load();

    BoardMemento saveToMemento() const;
    void restoreFromMemento(BoardMemento memento);
private:
    vector<vector<char>> board_;
    vector<shared_ptr<IFigure>> figures_;
};
