#pragma once
#include "IFigure.h"
#include <iostream>
#include <vector>
#include <memory>
#include "BoardMemento.h"
#include "ColoredChar.h"

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
    void select(const int& id);
    void select(const int& x, const int& y);
    void moveFigure(const int& x, const int& y);
    void remove();
    void expandFigure(const int& param);
    void paint(const string& color);
    void save(const string& filename) const;
    void load(const string& filename);
    bool operator==(const BoardMemento& memento) const;
    BoardMemento saveToMemento() const;
    void restoreFromMemento(BoardMemento memento);
private:
    vector<shared_ptr<IFigure>>::iterator selected_figure_;
    vector<vector<ColoredChar>> board_;
    vector<shared_ptr<IFigure>> figures_;

    void redraw();
    void moveForeground();
};
