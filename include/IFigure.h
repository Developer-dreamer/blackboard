#pragma once

#include <vector>
#include <string>

using namespace std;

struct IFigure
{
    virtual vector<string> getFigureInfo() const = 0;
    virtual ~IFigure() = default;
protected:
    vector<string> parameters; 
};