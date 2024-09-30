#pragma once
#include "IFigure.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Board {
public:
    Board();
    void draw() const;
    void clear();
    void getAllFigures() const;
    void addFigure(unique_ptr<IFigure> figure);
    void save() const;
    void load();
private:
    vector<vector<char>> board;
    vector<unique_ptr<IFigure>> figures;
};
