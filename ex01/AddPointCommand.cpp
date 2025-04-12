#include "AddPointCommand.hpp"

AddPointCommand::AddPointCommand(Graph* graph, float x, float y)
    : m_graph(graph), m_x(x), m_y(y)
{

}

AddPointCommand::~AddPointCommand()
{

}

void AddPointCommand::execute()
{
    m_graph->addPoint(Vector2(m_x, m_y));
}
