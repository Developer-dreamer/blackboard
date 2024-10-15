#include "include/ParseHelper.h"
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <bits/uses_allocator.h>
using namespace std;

namespace ParseHelper {
    vector <string> split(const string &str, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(str);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    vector <string> parseCommand(int rcsv_c) {
        if (rcsv_c > 2) {
            return {"exit"};
        }

        cout << "Enter params: ";
        string command;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        getline(cin, command);
        vector<string> result = split(command, ' ');

        // Define allowed shapes and required argument counts
        vector<pair<string, int>> figures = {
                {"circle",    6},    // <shape/fill> <color> <centerX> <centerY> <radius>
                {"rectangle", 7}, // <shape/fill> <color> <left_top_x> <left_top_y> <right_bottom_x> <right_bottom_y>
                {"triangle",  9}   // <shape/fill> <color> <x1> <y1> <x2> <y2> <x3> <y3>
        };

        // Check if the input command is one of the allowed figures
        auto figure = find_if(figures.begin(), figures.end(), [&](const pair<string, int> &f) {
            return result[0] == f.first;
        });

        if (figure == figures.end()) {
            cout << "Undefined figure. Supported shapes are 'circle', 'rectangle', 'triangle'." << endl;
            return parseCommand(++rcsv_c);
        }

        // Check the number of arguments for the figure
        if (result.size() != figure->second) {
            cout << "Incorrect number of arguments for " << figure->first
                 << ". Expected " << figure->second << " arguments." << endl;
            return parseCommand(++rcsv_c);
        }

        // Validate drawing type
        if (result[1] != "shape" && result[1] != "fill") {
            cout << "Incorrect drawing type. Enter either 'shape' or 'fill'." << endl;
            return parseCommand(++rcsv_c);
        }

        // Validate color
        vector<string> availableColors = {"red", "green", "blue", "yellow", "magenta", "cyan", "white"};
        if (find(availableColors.begin(), availableColors.end(), result[2]) == availableColors.end()) {
            cout << "Incorrect color. Available colors are: red, green, blue, yellow, magenta, cyan, white." << endl;
            return parseCommand(++rcsv_c);
        }

        // Validate that the remaining arguments are numeric (coordinates and dimensions)
        for (size_t i = 3; i < result.size(); i++) {
            try {
                stoi(result[i]);
            } catch (const invalid_argument &) {
                cout << "Incorrect argument: " << result[i] << ". Arguments must be numbers." << endl;
                return parseCommand(++rcsv_c);
            }
        }

        return result;
    }

    tuple<int, int> parseSelector() {
        cout << "Enter the selection factor (id / coords): ";
        string selector;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, selector);
        vector<string> coords = split(selector, ' ');
        if (coords.size() == 1) {
            return make_tuple(stoi(selector), -1);
        } else if (coords.size() == 2) {
            return make_tuple(stoi(coords[0]), stoi(coords[1]));
        } else {
            cout << "Incorrect number of arguments. Expected 1 or 2 arguments." << endl;
            return make_tuple(-1, -1);
        }

    }
}