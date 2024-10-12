#include "Board.h"
#include <tuple>
#include "Figures/Circle.h"
#include "Figures/Rectangle.h"
#include "Figures/Triangle.h"

#include "FileProcessor.h"

Board::Board()
{
    board_ = vector<vector<ColoredChar>>(50, vector<ColoredChar>(50));
}

void Board::draw() const
{
    for (vector<ColoredChar> row : board_)
    {
        for (ColoredChar cell : row)
        {
            cout <<cell.getColor() << cell.getChar();
        }
        cout << endl;
    }
}

void Board::redraw() {
    clear();
    for (const auto& figure : figures_)
    {
        vector<tuple<int,int>> shape = figure->getArea();
        for (const auto& point : shape)
        {
            int x = get<0>(point);
            int y = get<1>(point);
            if (x < 0 || x >= board_.size() || y < 0 || y >= board_[0].size())
                continue;
            board_[x][y] = figure->getChar();
        }
    }
}

void Board::clear()
{
    for (vector<ColoredChar> row : board_)
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
        cout << endl;
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
    figures_.back()->draw();


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
    tuple<vector<vector<ColoredChar>>, vector<shared_ptr<IFigure>>> state = memento.getState();
    board_ = get<0>(state);
    figures_ = get<1>(state);
}