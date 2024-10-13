#include "Board.h"
#include <tuple>
#include <stdexcept>
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

void Board::select(const int &id) {

    if (id >= figures_.size()) {
        cout << "No figure found with id: " << id <<endl;
    }
    selected_figure_ = figures_.begin() + id;

    cout << "Selected figure: ";
    for (const auto& info : selected_figure_->get()->getFigureInfo()) {
        cout << info << " ";
    }
    cout << endl;

}

void Board::select(const int &x, const int &y){
    for (size_t i = 0; i < figures_.size(); i++) {
        const auto& figure = figures_.at(i);
        const auto& area = figure->getArea();
        for (const auto& point : area) {
            if (get<0>(point) == x && get<1>(point) == y) {
                cout << "Selected figure: ";
                for (const auto& info : figure->getFigureInfo()) {
                    cout << info << " ";
                }
                selected_figure_ = figures_.begin() + i;
                return;
            }
        }
    }
    cout << "No figure found at (" << x << ", " << y << ")";
}
