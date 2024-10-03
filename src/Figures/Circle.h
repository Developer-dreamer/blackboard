#pragma once
#include <tuple>
#include "IFigure.h"

struct Circle final : public IFigure {
public:
    using coord_v = vector<tuple<int, int>>;
    explicit Circle(const vector<string>& params);
    vector<string> getFigureInfo() const override;
    coord_v draw() const override;
private:
    int radius_;
    tuple <int, int > center_;
    void bresenham(coord_v& circle_shape_coords) const;
    void EightWaySymmetricPlot(coord_v& circle_shape_coords, int xc,int yc,int x,int y)  const;
};
