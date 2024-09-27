#include "ConsoleProcessor.h"

ConsoleProcessor::ConsoleProcessor()
{
    cout << "Please enter what action you want to perform: ";
    string command;
    while (true)
    {
        if (!getlineWrapper_(cin, command))
        {
            continue;
        }
        break;
    }
};


unique_ptr<ICommand> ConsoleProcessor::getCommand()
{
    
}