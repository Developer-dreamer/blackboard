#include "Circle.h"

Circle::Circle(const vector<string>& params)
{
    center_ = make_tuple(stoi(params[1]), stoi(params[2]));
    radius_ = stoi(params[3]);
}

vector<string> Circle::getFigureInfo() const
{
    return {"Circle", to_string(get<0>(center_)), to_string(get<1>(center_)), to_string(radius_)};
}

vector<tuple<int, int>> Circle::draw() const
{
    vector<tuple<int, int>> circle_shape_coords;
    bresenham(circle_shape_coords);
    return circle_shape_coords;
}

void Circle::bresenham(Circle::coord_v& circle_shape_coords) const
{
    int x = 0, y = radius_;
    int d = 3 - 2 * radius_;
    EightWaySymmetricPlot(circle_shape_coords, get<0>(center_), get<1>(center_), x, y);
    while (y >= x){

        // check for decision parameter
        // and correspondingly
        // update d, y
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;

        // Increment x after updating decision parameter
        x++;

        // Draw the circle using the new coordinates
        EightWaySymmetricPlot(circle_shape_coords, get<0>(center_), get<1>(center_), x, y);
    }
}

void Circle::EightWaySymmetricPlot(Circle::coord_v& circle_shape_coords, int xc, int yc, int x, int y) const
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