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
    std::vector<std::string> parseCommand();
}

#endif // PARSEHELPE_H