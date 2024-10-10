#pragma once
#include <tuple>
#include "include/IFigure.h"

struct Rectangle final : public IFigure {
    
    explicit Rectangle(const vector<string>& params);
    vector<string> getFigureInfo() const override;
    void draw()override;
    virtual coords getArea() const = 0;
private:
    tuple<int,int> left_top_coords_;
    tuple<int,int> right_bottom_coords_;
};