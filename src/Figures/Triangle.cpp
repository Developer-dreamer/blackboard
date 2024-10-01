#include <iostream>
#include "Triangle.h"
using namespace std;

Triangle::Triangle(const vector<string>& params)
{
    vertex_a_ = make_tuple(stoi(params[1]), stoi(params[2]));
    vertex_b_ = make_tuple(stoi(params[3]), stoi(params[4]));
    vertex_c_ = make_tuple(stoi(params[5]), stoi(params[6]));
}

vector<string> Triangle::getFigureInfo() const
{
    return {"Triangle", to_string(get<0>(vertex_a_)), to_string(get<1>(vertex_a_)), to_string(get<0>(vertex_b_)), to_string(get<1>(vertex_b_)), to_string(get<0>(vertex_c_)), to_string(get<1>(vertex_c_))};
}

vector<tuple<int, int>> Triangle::draw() const
{
    vector<tuple<int, int>> triangle_shape_coords;
    bresenham(vertex_a_, vertex_b_, triangle_shape_coords);
    bresenham(vertex_b_, vertex_c_, triangle_shape_coords);
    bresenham(vertex_c_, vertex_a_, triangle_shape_coords);
    return triangle_shape_coords;
}

void Triangle::bresenham(tuple<int, int> left_p_, tuple<int, int> right_p_, vector<tuple<int, int>>& triangle_shape_coords) const
{
    int x1 = get<0>(left_p_);
    int y1 = get<1>(left_p_);
    int x2 = get<0>(right_p_);
    int y2 = get<1>(right_p_);

    float slope = (y2 - y1) / (float)(x2 - x1);
    if (slope > 1)
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

    while (x <= x2)
    {
        ++x;
        if (d < 0){
            // move horizontally
            d += 2 * dy;
        } else
        {
            // move diagonally
            d += 2 * (dy - dx);
            y = y + 1;
        }

        if (slope > 1)
        {
            triangle_shape_coords.push_back(make_tuple(y, x));
        } else if (slope < 1 && slope > 0)
        {
            triangle_shape_coords.push_back(make_tuple(x, y));
        } else
        {
            triangle_shape_coords.push_back(make_tuple(x, -y));
        }
    }
}
