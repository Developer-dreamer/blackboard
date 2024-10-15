#pragma once
#include <string>

using namespace std;

class ColoredChar {
public:
    ColoredChar();
    ColoredChar(char ch, string color);
    string getColor() const;
    char getChar() const;
    void editColor(const string& newColor);
    string reset();
    bool operator==(const ColoredChar& other) const;
private:
    char ch_;
    string color_;

    string convertColor(const string& color);
};