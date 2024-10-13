#pragma once
#include <tuple>
#include "include/IFigure.h"

struct Rectangle final : public IFigure {
    
    explicit Rectangle(const vector<string>& params);
    vector<string> getFigureInfo() const override;
    void draw()override;
    coords getArea() const override;
    ColoredChar getChar() const override;
    void edit(const string& color) override;
    void moveCoords(const coords& newCoords) override;
private:
    tuple<int,int> left_top_coords_;
    tuple<int,int> right_bottom_coords_;
};