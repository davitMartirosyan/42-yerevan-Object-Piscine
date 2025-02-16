#include "PrintCommand.hpp"

PrintCommand::PrintCommand(Graph& graph)
    : m_graph(graph)
{

}

PrintCommand::~PrintCommand()
{

}

void PrintCommand::execute()
{
    m_graph.print();
}
