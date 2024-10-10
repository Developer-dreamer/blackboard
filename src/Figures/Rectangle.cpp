#include "Rectangle.h"

Rectangle::Rectangle(const vector<string>& params)
{

    left_top_coords_ = {stoi(params[1]), stoi(params[2])};
    right_bottom_coords_= {stoi(params[3]), stoi(params[4])};
}

void Rectangle::draw()
{
    occupied_cells_.push_back(left_top_coords_);
    int left_x = get<0>(left_top_coords_);
    int left_y = get<1>(left_top_coords_);
    int right_x = get<0>(right_bottom_coords_);
    int right_y = get<1>(right_bottom_coords_);

    for (int i = left_x; i <= right_x; i++)
    {
        for (int j = left_y; j <= right_y; j++)
        {
            occupied_cells_.push_back(make_tuple(i, j));
        }
    }
}

Rectangle::coords Rectangle::getArea() const
{
    return occupied_cells_;
}

vector<string> Rectangle::getFigureInfo() const
{
    return {"Rectangle", to_string(get<0>(left_top_coords_)), to_string(get<1>(left_top_coords_)), to_string(get<0>(right_bottom_coords_)), to_string(get<1>(right_bottom_coords_))};
}