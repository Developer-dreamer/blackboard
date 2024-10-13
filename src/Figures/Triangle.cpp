#include <iostream>
#include <algorithm>
#include "Triangle.h"
using namespace std;

Triangle::Triangle(const vector<string>& params)
{
    fill_type = params[1];
    char_ = ColoredChar('*', params[2]);
    vertex_a_ = make_tuple(stoi(params[3]), stoi(params[4]));
    vertex_b_ = make_tuple(stoi(params[5]), stoi(params[6]));
    vertex_c_ = make_tuple(stoi(params[7]), stoi(params[8]));

    area_ = 0.5 * abs((
            get<0>(vertex_a_) * (get<1>(vertex_b_) - get<1>(vertex_c_)) +
            get<0>(vertex_b_) * (get<1>(vertex_c_) - get<1>(vertex_a_)) +
            get<0>(vertex_c_) * (get<1>(vertex_a_) - get<1>(vertex_b_))
                    ));
}

vector<string> Triangle::getFigureInfo() const
{
    return {"Triangle", to_string(get<0>(vertex_a_)), to_string(get<1>(vertex_a_)), to_string(get<0>(vertex_b_)), to_string(get<1>(vertex_b_)), to_string(get<0>(vertex_c_)), to_string(get<1>(vertex_c_))};
}

void Triangle::draw()
{
    //finding bounding box
    int min_x = min({get<0>(vertex_a_), get<0>(vertex_b_), get<0>(vertex_c_)});
    int max_x = max({get<0>(vertex_a_), get<0>(vertex_b_), get<0>(vertex_c_)});
    int min_y = min({get<1>(vertex_a_), get<1>(vertex_b_), get<1>(vertex_c_)});
    int max_y = max({get<1>(vertex_a_), get<1>(vertex_b_), get<1>(vertex_c_)});

    bresenham(vertex_a_, vertex_b_, occupied_cells_);
    bresenham(vertex_b_, vertex_c_, occupied_cells_);
    bresenham(vertex_a_, vertex_c_, occupied_cells_);

    for (int x = min_x; x <= max_x; ++x)
    {
        for (int y = min_y; y <= max_y; ++y)
        {
            if (fill(x, y))
            {
                occupied_cells_.push_back(make_tuple(x, y));
            }
        }
    }
}

Triangle::coords Triangle::getArea() const
{
    return occupied_cells_;

}
void Triangle::bresenham(tuple<int, int> left_p_, tuple<int, int> right_p_, vector<tuple<int, int>>& triangle_shape_coords) const
{
    int x1 = get<0>(left_p_);
    int y1 = get<1>(left_p_);
    int x2 = get<0>(right_p_);
    int y2 = get<1>(right_p_);
    triangle_shape_coords.push_back(make_tuple(x1, y1));
    float slope = (y2 - y1) / (float)(x2 - x1);
    if (slope >= 1)
    {
        swap(x1, y1);
        swap(x2, y2);
    } else if (slope < 0)
    {
        y1 = -y1;
        y2 = -y2;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;

    //decision
    int d = 2 * dy - dx;
    int x = x1;
    int y = y1;

    while (x < x2 )
    {
        ++x;
        if (d < 0){
            // move horizontally
            d += 2 * dy;
        } else
        {
            // move diagonally
            d += 2 * (dy - dx);
            ++y;
        }
        if (slope >= 1)
        {
            triangle_shape_coords.push_back(make_tuple(y, x));
        } else if (slope < 1 && slope >= 0)
        {
            triangle_shape_coords.push_back(make_tuple(x, y));
        } else
        {
            triangle_shape_coords.push_back(make_tuple(x, -y));
        }
    }
}

bool Triangle::fill(const int& x, const int& y) const
{
    int area1 = 0.5 * abs((
                                  x * (get<1>(vertex_b_) - get<1>(vertex_c_)) +
                                  get<0>(vertex_b_) * (get<1>(vertex_c_) - y) +
                                  get<0>(vertex_c_) * (y - get<1>(vertex_b_))
                          ));

    int area2 = 0.5 * abs((
                                  get<0>(vertex_a_) * (y - get<1>(vertex_c_)) +
                                  x * (get<1>(vertex_c_) - get<1>(vertex_a_)) +
                                  get<0>(vertex_c_) * (get<1>(vertex_a_) - y)
                          ));

    int area3 = 0.5 * abs((
                                  get<0>(vertex_a_) * (get<1>(vertex_b_) - y) +
                                  get<0>(vertex_b_) * (y - get<1>(vertex_a_)) +
                                  x * (get<1>(vertex_a_) - get<1>(vertex_b_))
                          ));

    return area1 + area2 + area3 == area_;
}

ColoredChar Triangle::getChar() const {
    return ColoredChar();
}

void Triangle::edit(const string &color) {
    char_.editColor(color);
}

void Triangle::moveCoords(const IFigure::coords &newCoords) {
    occupied_cells_ = newCoords;
}


