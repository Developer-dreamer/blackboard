#pragma once
#include <tuple>
#include "IFigure.h"

struct Circle final : public IFigure {
public:
    explicit Circle(const vector<string>& params);
    vector<string> getFigureInfo() const override;
    void draw() override;
    coords getArea() const override;
    ColoredChar getChar() const override;
    void edit(const string& color) override;
    void moveCoords(const coords& newCoords) override;
private:
    int radius_;
    tuple <int, int > center_;
    void bresenham(coords& circle_shape_coords) const;
    void EightWaySymmetricPlot(coords& circle_shape_coords, int xc,int yc,int x,int y)  const;
    bool fill(const int& x, const int& cx, const int& y, const int& cy) const;
};
