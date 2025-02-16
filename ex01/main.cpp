#include <vector>
#include <iostream>
#include "Graph.hpp"
#include "Invoker.hpp"

#define CREATE  "create"
#define ADD     "add"
#define PRINT   "print"
#define QUIT    "quit"

#define MAXLIMIT(type) \
    std::numeric_limits<type>::max()

int main()
{
    std::string command;
    Invoker *invoker = new Invoker;
    Graph   *graph = new Graph;
    Command *print = new PrintCommand(*graph);
    do
    {
        std::cout << "$(dmartiro): ";
        std::getline(std::cin, command);
        if (command.empty())
           continue;
        if (command == CREATE)
        {
            size_t sizeX;
            size_t sizeY;
            std::cout << "Graph Size(X Y): ";
            std::cin >> sizeX >> sizeY;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (sizeX > 0 && sizeY > 0 && sizeX < MAXLIMIT(size_t) && sizeY < MAXLIMIT(size_t))
            {
                graph->clean();
                invoker->reset(command);
                Command* createGraph = new CreateCommand(*graph, sizeX, sizeY);
                invoker->set(command, createGraph);
                invoker->ExecuteCommand(command);
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (command == ADD)
        {
            std::cout << "Will be implemented" << std::endl;
        }
        else if (command == QUIT)
            break;
    }
    while(1);

    delete invoker;
    delete graph;
    delete print;
}
