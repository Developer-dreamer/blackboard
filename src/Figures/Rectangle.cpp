#include "Rectangle.h"

Rectangle::Rectangle(const vector<string>& params)
{
    left_top_coords_ = {stoi(params[1]), stoi(params[2])};
    right_bottom_coords_= {stoi(params[3]), stoi(params[4])};
}

vector<tuple<int, int>> Rectangle::draw() const
{
    vector<tuple<int, int>> rectangle_shape_coords;
    rectangle_shape_coords.push_back(left_top_coords_);
    int left_x = get<0>(left_top_coords_);
    int left_y = get<1>(left_top_coords_);
    int right_x = get<0>(right_bottom_coords_);
    int right_y = get<1>(right_bottom_coords_);

    for (int i = left_x; i <= right_x; ++i)
    {
        rectangle_shape_coords.push_back({i, left_y});
        rectangle_shape_coords.push_back({i, right_y});
    }

    for (int i = left_y; i <= right_y; ++i)
    {
        rectangle_shape_coords.push_back({left_x, i});
        rectangle_shape_coords.push_back({right_x, i});
    }

    return rectangle_shape_coords;
}

vector<string> Rectangle::getFigureInfo() const
{
    return {"Rectangle", to_string(get<0>(left_top_coords_)), to_string(get<1>(left_top_coords_)), to_string(get<0>(right_bottom_coords_)), to_string(get<1>(right_bottom_coords_))};
}