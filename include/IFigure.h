#pragma once

#include <vector>
#include <string>
#include <memory>
#include "ColoredChar.h"

using namespace std;

struct IFigure
{
    using coords = vector<tuple<int, int>>;
    virtual vector<string> getFigureInfo() const = 0;
    virtual void draw() = 0;
    virtual coords getArea() const = 0;
    virtual ColoredChar getChar() const = 0;
    virtual void edit(const string& color) = 0;
    virtual void moveCoords(const coords& newCoords) = 0;
    virtual ~IFigure() = default;
protected:
    ColoredChar char_;
    string fill_type;
    coords occupied_cells_;
};