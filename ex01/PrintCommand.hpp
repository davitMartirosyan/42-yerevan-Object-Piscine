#ifndef __PRINT__COMMAND__HPP__
#define __PRINT__COMMAND__HPP__
#include "Command.hpp"

class PrintCommand : public Command
{
    public:
        PrintCommand(Graph& graph);
        virtual ~PrintCommand();
        virtual void execute();
    private:
        Graph m_graph;
};

#endif //__PRINT__COMMAND__HPP__
