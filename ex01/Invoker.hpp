#ifndef __INVOKER__HPP__
#define __INVOKER__HPP__
#include <map>
#include "Command.hpp"
#include "CreateCommand.hpp"
#include "AddPointCommand.hpp"
#include "PrintCommand.hpp"

class Invoker
{
    public:
        Invoker();
        ~Invoker();
        void ExecuteCommand(std::string const &commandName);
        void set(std::string const& commandName, Command* cmd);
        bool reset(std::string const& commandName);
    private:
        std::map<std::string, Command*> m_cmdMap;
};

#endif //__INVOKER__HPP__
