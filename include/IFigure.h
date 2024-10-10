#pragma once

#include <vector>
#include <string>

using namespace std;

struct IFigure
{
    using coords = vector<tuple<int, int>>;
    virtual vector<string> getFigureInfo() const = 0;
    virtual void draw() = 0;
    virtual coords getArea() const = 0;
    virtual ~IFigure() = default;
protected:
    vector<string> parameters;
    coords occupied_cells_;
};