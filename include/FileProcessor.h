#pragma once
#include <vector>
#include <string>
using namespace std;

class FileProcessor {
public:
    FileProcessor() = default;
    void save(const vector<vector<char>>& board) const;
    vector<vector<char>> load() const;
private:
    const string filename_ = "board.txt";

    // allows to save boards to different files and
    // not to overwrite the previous ones
    // like board1.txt, board2.txt, etc.
    string generateFileName() const;
};