#include "Board.h"
#include <tuple>

#include "FileProcessor.h"

Board::Board()
{
    board = vector<vector<char>>(100, vector<char>(100, ' '));
}

void Board::draw() const
{
    for (vector<char> row : board)
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
    for (vector<char> row : board)
    {
        row.clear();
    }
}

void getAllFigures()
{
    // TODO: add an opportunity to detect the figure and its position
}

void Board::addFigure(unique_ptr<IFigure> figure)
{
    figures.push_back(move(figure));
    vector<tuple<int, int>> figureCoordinates = figures.back()->draw();

    for (tuple<int, int> coordinate : figureCoordinates)
    {
        board[get<0>(coordinate)][get<1>(coordinate)] = '*';
    }
}

void Board::save() const
{
    FileProcessor fileProcessor;
    fileProcessor.save(board);
}

void Board::load()
{
    FileProcessor fileProcessor;
    board = fileProcessor.load();
}
