#ifndef _COMMAND_LINE_INTERFACE_HPP_
#define _COMMAND_LINE_INTERFACE_HPP_
#include <string>

#define CREATE  "create"
#define ADD     "add"
#define PRINT   "print"
#define QUIT    "quit"

#define MAXLIMIT(type) \
    std::numeric_limits<type>::max()



class CommandLineInterface{
    public:
        CommandLineInterface();
        ~CommandLineInterface();
    public:
        bool prepare(std::string const&);
        bool isValidCommand();

    private:
        std::string m_prompt;
};

#endif //_COMMAND_LINE_INTERFACE_HPP_