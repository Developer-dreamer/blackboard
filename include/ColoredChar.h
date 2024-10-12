#pragma once
#include <string>

using namespace std;

class ColoredChar {
public:
    ColoredChar();
    ColoredChar(string ch, string color);
    string getColor() const;
    string getChar() const;
    bool operator==(const ColoredChar& other) const;
private:
    string ch_;
    string color_;
};