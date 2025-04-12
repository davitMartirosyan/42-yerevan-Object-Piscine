#include "CreateCommand.hpp"

CreateCommand::CreateCommand(Graph* newGraph, size_t w, size_t h)
    : m_graph(newGraph), m_width(w), m_height(h)
{

}

CreateCommand::~CreateCommand()
{

}

void CreateCommand::execute()
{
    m_graph->create(m_width, m_height);
}
