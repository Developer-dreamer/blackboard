#pragma once

#include <iostream>
#include <map>
#include "BookingContext.h"
#include "ICommand.h"

using namespace std;

class ICommand;

class ConsoleProcessor {
public:
    static unique_ptr<ICommand> parseParameters(const shared_ptr<BookingContext>& bookTicket);
    static map<string,string> authenticateUser();
    static void printInfo(const map<string, string>& file_info);
    static void printInfo(const map<string, float>& file_info);
    
    ~ConsoleProcessor() = default;
private:
    static int recursive_counter_;
    static vector<string> validate_command(const string& command);
    static string validate_int(string& param);
    static bool getline_wrapper(istream& input, string& line);
};
