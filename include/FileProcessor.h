#pragma once
#include <vector>
#include <string>
using namespace std;

class FileProcessor {
public:
    FileProcessor(const string& filemame);
    void save(const vector<vector<char>>& board) const;
    vector<vector<char>> load() const;
private:
    string filename_;
};