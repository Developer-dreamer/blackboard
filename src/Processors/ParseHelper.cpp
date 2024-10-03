#include "include/ParseHelper.h"
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

namespace ParseHelper
{
    vector<string> split(const string& str, char delimiter)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(str);
        while (getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    vector<string> parseCommand()
    {
        cout << "Enter params: ";
        string command;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        getline(cin, command);
        return split(command, ' ');
    }
}
