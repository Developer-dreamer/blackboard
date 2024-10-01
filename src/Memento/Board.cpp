#include "Board.h"
#include <tuple>

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

void getAllFigures()
{
    // TODO: add an opportunity to detect the figure and its position
}

void Board::addFigure(shared_ptr<IFigure> figure)
{
    figures_.push_back(move(figure));
    vector<tuple<int, int>> figureCoordinates = figures_.back()->draw();

    for (tuple<int, int> coordinate : figureCoordinates)
    {
        board_[get<0>(coordinate)][get<1>(coordinate)] = '*';
    }
}

void Board::save() const
{
    FileProcessor fileProcessor;
    fileProcessor.save(board_);
}

void Board::load()
{
    FileProcessor fileProcessor;
    board_ = fileProcessor.load();
}

BoardMemento Board::saveToMemento() const
{
    return BoardMemento(make_tuple(board_, figures_));
}
