#pragma once

#include <tuple>
#include "IFigure.h"

struct Triangle final: public IFigure
{
public:
    explicit Triangle(const vector<string>& params);
    vector<string> getFigureInfo() const override;
    void draw() override;
    coords getArea() const override;
private:
    tuple<int, int > vertex_a_;
    tuple<int, int > vertex_b_;
    tuple<int, int > vertex_c_;
    int area_;
    void bresenham(tuple<int, int> left_p_, tuple<int, int> right_p_, vector<tuple<int, int>>& triangle_shape_coords) const;
    bool fill(const int& x, const int& y) const;
};