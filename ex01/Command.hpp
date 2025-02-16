#ifndef __COMMAND__HPP__
#define __COMMAND__HPP__

class Command
{
    public:
        Command();
        ~Command();
    public:
        void execute() = 0;
};

#endif //__COMMAND__HPP__