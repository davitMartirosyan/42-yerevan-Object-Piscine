#include "CommandLineInterface.hpp"

CommandLineInterface::CommandLineInterface()
{

}

CommandLineInterface::~CommandLineInterface()
{

}

bool CommandLineInterface::isValid()
{
    if (m_prompt.empty())
        return (false);
    return (true);
}

void CommandLineInterface::prepare(std::string& prompt)
{
    m_prompt = prompt;
    prompt = trim(m_prompt);
    for(size_t i = 0; i < prompt.size(); i++){
       prompt[i] = std::tolower(prompt[i]);
    }
}

std::string CommandLineInterface::ltrim(std::string const& str)
{
    std::string lt = str;
    size_t f = lt.find_first_not_of(" \n\t\b\r\a");
    return (f == std::string::npos ? "" : lt.substr(f));

}
std::string CommandLineInterface::rtrim(std::string const& str)
{
    std::string rt = str;
    size_t f = rt.find_last_not_of(" \n\t\b\r\a");
    return (f == std::string::npos ? "" : rt.substr(0, f + 1));
}

std::string CommandLineInterface::trim(std::string const& str)
{
    return (rtrim(ltrim(str)));
}

void CommandLineInterface::run(Graph* graph, Invoker* invoker, std::string const& cmdName, Command* command)
{
    invoker->reset(cmdName);
    invoker->set(cmdName, command);
    invoker->ExecuteCommand(cmdName);
}