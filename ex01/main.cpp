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
            float sizeX = 0;
            float sizeY = 0;
            std::cout << "Graph Size(X Y): ";
            std::cin >> sizeX >> sizeY;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(MAXLIMIT(std::streamsize), '\n');
                continue;
            }
            if (sizeX > 0 && sizeY > 0 && sizeX < MAXLIMIT(float) && sizeY < MAXLIMIT(float))
            {
                graph->clean();
                invoker->reset(command);
                Command* createGraph = new CreateCommand(*graph, sizeX, sizeY);
                invoker->set(command, createGraph);
                invoker->ExecuteCommand(command);
            }
        }
        else if (command == ADD)
        {
            float x = 0;
            float y = 0;
            std::cout << "Add New Point: ";
            std::cin >> x >> y;
            invoker->reset(command);
            Command* addPoint = new AddPointCommand(*graph, x, y);
            invoker->set(command, addPoint);
            invoker->ExecuteCommand(command);   
        }
        else if (command == QUIT)
            break;
        std::cin.ignore(MAXLIMIT(std::streamsize), '\n');
    }
    while(1);

    delete invoker;
    delete graph;
    delete print;
}
