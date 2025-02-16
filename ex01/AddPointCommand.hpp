#ifndef __ADD__POINT__COMMAND__HPP__
#define __ADD__POINT__COMMAND__HPP__
#include "Command.hpp"

class AddPointCommand : public Command
{
    public:
        AddPointCommand(Graph& graph, float x, float y);
        virtual ~AddPointCommand();
        virtual void execute();
    private:
        Graph m_graph;
        float m_x;
        float m_y;
};

#endif //__ADD__POINT__COMMAND__HPP__
