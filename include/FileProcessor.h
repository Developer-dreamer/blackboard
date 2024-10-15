#pragma once
#include <vector>
#include <string>
#include "src/Helper/ColoredChar.h"

using namespace std;

class FileProcessor {
public:
    FileProcessor(const string& filemame);
    void save(const vector<vector<ColoredChar>>& board) const;
    vector<vector<ColoredChar>> load() const;
private:
    string filename_;
};