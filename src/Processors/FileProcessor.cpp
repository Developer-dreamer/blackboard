#include "../../include/FileProcessor.h"
#include <iostream>
#include <fstream>

using namespace std;

FileProcessor::FileProcessor(const string& filename) : filename_(filename)
{};
void FileProcessor::save(const vector<vector<ColoredChar>>& board) const
{
    ofstream file(filename_);
    for (const auto& row : board)
    {
        for (const auto& cell : row)
        {
            file << cell.getChar();
        }
        file << endl;
    }
}

vector<vector<ColoredChar>> FileProcessor::load() const
{
    vector<vector<ColoredChar>> board;
    ifstream file(filename_);
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return board;
    }
    string line;
    while (getline(file, line))
    {
        vector<ColoredChar> row;
        for (const auto& cell : line)
        {
            row.push_back(ColoredChar(to_string(cell), "white"));
        }
        board.push_back(row);
    }

    return board;
}
