#include "ColoredChar.h"

ColoredChar::ColoredChar()
    : ch_(' '), color_("\033[37m") {}

ColoredChar::ColoredChar(char ch, string color)
    : ch_(ch){
    color_ = convertColor(color);
}

string ColoredChar::reset() {
    return "\033[0m";
}

string ColoredChar::getColor() const
{
    return color_;
}

char ColoredChar::getChar() const
{
    return ch_;
}

bool ColoredChar::operator==(const ColoredChar& other) const
{
    return ch_ == other.ch_ && color_ == other.color_;
}
void ColoredChar::editColor(const string& newColor)
{
    color_ = convertColor(newColor);
}

string ColoredChar::convertColor(const string& color)
{
    if (color == "red")
        return "\033[31m";
    if (color == "green")
        return "\033[32m";
    if (color == "yellow")
        return "\033[33m";
    if (color == "blue")
        return "\033[34m";
    if (color == "magenta")
        return "\033[35m";
    if (color == "cyan")
        return "\033[36m";
    if (color == "white")
        return "\033[37m";
    return "\033[37m";
}