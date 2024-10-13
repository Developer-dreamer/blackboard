#include "Rectangle.h"

Rectangle::Rectangle(const vector<string>& params)
{
    fill_type = params[1];
    char_ = ColoredChar('*', params[2]);
    left_top_coords_ = {stoi(params[3]), stoi(params[4])};
    right_bottom_coords_= {stoi(params[5]), stoi(params[6])};
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

ColoredChar Rectangle::getChar() const {
    return ColoredChar();
}

void Rectangle::edit(const string &color) {
    char_.editColor(color);
}

void Rectangle::moveCoords(const IFigure::coords &newCoords) {
    occupied_cells_ = newCoords;
}
