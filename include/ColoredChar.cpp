#include "ColoredChar.h"

ColoredChar::ColoredChar()
    : ch_(" "), color_("white") {}

ColoredChar::ColoredChar(string ch, string color)
    : ch_(ch), color_(color) {}


string ColoredChar::getColor() const
{
    if (color_ == "red")
        return "\033[31m" + ch_ + "\033[0m";
    else if (color_ == "green")
        return "\033[32m" + ch_ + "\033[0m";
    else if (color_ == "yellow")
        return "\033[33m" + ch_ + "\033[0m";
    else if (color_ == "blue")
        return "\033[34m" + ch_ + "\033[0m";
    else if (color_ == "magenta")
        return "\033[35m" + ch_ + "\033[0m";
    else if (color_ == "cyan")
        return "\033[36m" + ch_ + "\033[0m";
    else if (color_ == "white")
        return "\033[37m" + ch_ + "\033[0m";
    else
        return ch_;
}

string ColoredChar::getChar() const
{
    return ch_;
}

bool ColoredChar::operator==(const ColoredChar& other) const
{
    return ch_ == other.ch_ && color_ == other.color_;
}