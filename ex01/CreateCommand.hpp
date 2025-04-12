#ifndef __CREATE__COMMAND__HPP__
#define __CREATE__COMMAND__HPP__
#include "Command.hpp"

class CreateCommand : public Command
{
    public:
        CreateCommand(Graph* newGraph, size_t sizeX, size_t sizeY);
        virtual ~CreateCommand();
        virtual void execute();
    private:
        Graph* m_graph;
        size_t m_width;
        size_t m_height;
};

#endif  //__CREATE__COMMAND__HPP__
