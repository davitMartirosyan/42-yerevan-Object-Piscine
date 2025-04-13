#ifndef _COMMAND_LINE_INTERFACE_HPP_
#define _COMMAND_LINE_INTERFACE_HPP_
#include <string>
#include <iostream>
#include "Invoker.hpp"

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
        void prepare(std::string &);
        void run(Graph* graph, Invoker* invoker, std::string const& cmdName, Command* command);
        bool isValid();
    private:
        std::string ltrim(std::string const&);
        std::string rtrim(std::string const&);
        std::string trim(std::string const&);
    private:
        std::string m_prompt;
};

#endif //_COMMAND_LINE_INTERFACE_HPP_