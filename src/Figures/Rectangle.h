#pragma once

#include "include/IFigure.h"

struct Rectangle final : public IFigure {
    
    explicit Rectangle(const vector<string>& params);
private:
    vector<string> params_;
};