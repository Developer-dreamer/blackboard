// ParseHelper.h
#ifndef PARSEHELPE_H
#define PARSEHELPE_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

namespace ParseHelper
{
    std::vector<std::string> split(const std::string& str, char delimiter);
    std::vector<std::string> parseCommand(int rcsv_c);
    std::tuple<int, int> parseSelector();
}

#endif // PARSEHELPE_H