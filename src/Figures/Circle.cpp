#include "Circle.h"
#include <cmath>
Circle::Circle(const vector<string>& params)
{
    fill_type = params[1];
    char_ = ColoredChar("*", params[2]);
    center_ = make_tuple(stoi(params[3]), stoi(params[4]));
    radius_ = stoi(params[5]);
}

vector<string> Circle::getFigureInfo() const
{
    return {"Circle", to_string(get<0>(center_)), to_string(get<1>(center_)), to_string(radius_)};
}

void Circle::draw()
{
    bresenham(occupied_cells_);

    int cx = get<0>(center_);
    int cy = get<1>(center_);

    for (int x = (cx - radius_); x <= (cx + radius_); x++)
    {
        for (int y = (cy - radius_); y <= (cy + radius_); y++)
        {
            if (fill(x, cx, y, cy))
            {
                occupied_cells_.push_back(make_tuple(x, y));
            }
        }
    }
}

void Circle::bresenham(Circle::coords& circle_shape_coords) const
{
    int x = 0, y = radius_;
    int d = 3 - 2 * radius_;
    EightWaySymmetricPlot(circle_shape_coords, get<0>(center_), get<1>(center_), x, y);
    while (y >= x){

        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;

        x++;

        EightWaySymmetricPlot(circle_shape_coords, get<0>(center_), get<1>(center_), x, y);
    }
}

void Circle::EightWaySymmetricPlot(Circle::coords& circle_shape_coords, int xc, int yc, int x, int y) const
{
    circle_shape_coords.push_back(make_tuple(xc + x, yc + y));
    circle_shape_coords.push_back(make_tuple(xc - x, yc + y));
    circle_shape_coords.push_back(make_tuple(xc + x, yc - y));
    circle_shape_coords.push_back(make_tuple(xc - x, yc - y));
    circle_shape_coords.push_back(make_tuple(xc + y, yc + x));
    circle_shape_coords.push_back(make_tuple(xc - y, yc + x));
    circle_shape_coords.push_back(make_tuple(xc + y, yc - x));
    circle_shape_coords.push_back(make_tuple(xc - y, yc - x));
}

bool Circle::fill(const int& x, const int& cx, const int& y, const int& cy) const
{
    return pow(x - cx, 2) + pow(y - cy, 2) <= pow(radius_, 2);
}