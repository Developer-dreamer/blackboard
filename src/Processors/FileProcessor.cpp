#include "../../include/FileProcessor.h"
#include <iostream>
#include <fstream>

using namespace std;

FileProcessor::FileProcessor(const string& filename) : filename_(filename)
{};
void FileProcessor::save(const vector<vector<char>>& board) const
{
    ofstream file(filename_);
    for (const auto& row : board)
    {
        for (const auto& cell : row)
        {
            file << cell;
        }
        file << endl;
    }
}

vector<vector<char>> FileProcessor::load() const
{
    vector<vector<char>> board;
    ifstream file(filename_);
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return board;
    }
    string line;
    while (getline(file, line))
    {
        vector<char> row;
        for (const auto& cell : line)
        {
            row.push_back(cell);
        }
        board.push_back(row);
    }

    return board;
}
