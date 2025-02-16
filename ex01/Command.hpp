#ifndef __COMMAND__HPP__
#define __COMMAND__HPP__
#include "Graph.hpp"

class Command
{
    public:
        Command();
        virtual ~Command();
    public:
        virtual void execute() = 0;
};

#endif //__COMMAND__HPP__