#include "include/ParseHelper.h"
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <sstream>
#include <bits/uses_allocator.h>
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

    vector<string> parseCommand(int rcsv_c)
    {
        if (rcsv_c > 2)
            return vector<string>({"exit"});
        cout << "Enter params: ";
        string command;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        getline(cin, command);
        vector<string> result = split(command, ' ');
        if (result.capacity() < 2)
        {
            cout << "Invalid number of arguments" << endl;
            result = parseCommand(++rcsv_c);
        } else
        {
            for (auto it = result.begin() + 3; it != result.end(); it++)
            {
                try
                {
                    stoi(*it);
                } catch (invalid_argument e)
                {
                    cout << "Incorrect arguments" << endl;
                    result = parseCommand(++rcsv_c);
                }
            }
        }

        return result;
    }
}
