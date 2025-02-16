#include "Invoker.hpp"

Invoker::Invoker()
{

}

Invoker::~Invoker()
{

}

void Invoker::set(std::string const& commandName, Command* cmd)
{
    m_cmdMap[commandName] = cmd;
}

bool Invoker::reset(std::string const& commandName)
{
    if (m_cmdMap.find(commandName) != m_cmdMap.end())
    {
        delete m_cmdMap[commandName];
        m_cmdMap.erase(commandName);
        return (true);
    }
    return (false);
}

void Invoker::ExecuteCommand(std::string const &commandName)
{
    if (m_cmdMap.find(commandName) != m_cmdMap.end())
    {
        m_cmdMap[commandName]->execute();
    }
}
