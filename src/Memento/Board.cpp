#include "Board.h"
#include <tuple>
#include "Figures/Circle.h"
#include "Figures/Rectangle.h"
#include "Figures/Triangle.h"

#include "FileProcessor.h"

Board::Board()
{
    board_ = vector<vector<char>>(50, vector<char>(50, ' '));
}

void Board::draw() const
{
    for (vector<char> row : board_)
    {
        for (char cell : row)
        {
            cout << cell;
        }
        cout << endl;
    }
}

void Board::clear()
{
    for (vector<char> row : board_)
    {
        row.clear();
    }
}

void Board::getAllFigures() const
{
    for (shared_ptr<IFigure> figure : figures_)
    {
        vector<string> figureInfo = figure->getFigureInfo();
        for (string info : figureInfo)
        {
            cout << info << " ";
        }
    }
}

void Board::getAllShapes() const
{
    cout << "rectangle <left top x> <left top y> <right bottom x> <right bottom y>" << endl;
    cout << "circle <center x> <center y> <radius>" << endl;
    cout << "triangle <x1> <y1> <x2> <y2> <x3> <y3>" << endl;
}

void Board::addFigure(shared_ptr<IFigure> figure)
{
    figures_.push_back(move(figure));
    vector<tuple<int, int>> figureCoordinates = figures_.back()->draw();

    for (tuple<int, int> coordinate : figureCoordinates)
    {
        int x  = get<0>(coordinate);
        int y = get<1>(coordinate);

        if (x < 0 || y < 0 || x >= board_.size() || y >= board_[0].size())
            continue;

        board_[x][y]= '*';
    }
}

void Board::save(const string& filename) const
{
    FileProcessor fileProcessor(filename);
    fileProcessor.save(board_);
}

void Board::load(const string& filename)
{
    FileProcessor fileProcessor(filename);
    figures_.clear();
    board_ = fileProcessor.load();
}

bool Board::operator==(const BoardMemento& memento) const
{
    auto state = memento.getState();

    return board_ == get<0>(state) && figures_ == get<1>(state);
}

BoardMemento Board::saveToMemento() const
{
    return BoardMemento(make_tuple(board_, figures_));
}

void Board::restoreFromMemento(BoardMemento memento)
{
    tuple<vector<vector<char>>, vector<shared_ptr<IFigure>>> state = memento.getState();
    board_ = get<0>(state);
    figures_ = get<1>(state);
}