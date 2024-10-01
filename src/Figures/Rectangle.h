#pragma once
#include <tuple>
#include "include/IFigure.h"

struct Rectangle final : public IFigure {
    
    explicit Rectangle(const vector<string>& params);
    vector<string> getFigureInfo() const override;
    vector<tuple<int, int>> draw() const override;
private:
    tuple<int,int> left_top_coords_;
    tuple<int,int> right_bottom_coords_;
};