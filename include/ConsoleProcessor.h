#pragma once

#include <iostream>
#include <map>
#include "ICommand.h"

using namespace std;

class ICommand;

class ConsoleProcessor {
public:
    ConsoleProcessor();
    unique_ptr<ICommand> getCommand();
    static void printInfo(const map<string, string>& file_info);
    
    ~ConsoleProcessor() = default;
private:
    string parsed_string_;
    string getInput_();
    vector<string> validateCommand_(const string& command);
    bool getlineWrapper_(istream& input, string& line);
};
