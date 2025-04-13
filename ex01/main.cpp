#include <vector>
#include <iostream>
#include "Graph.hpp"
#include "Invoker.hpp"
#include "CommandLineInterface.hpp"

int main()
{
    std::string command;
    Invoker *invoker = new Invoker;
    Graph   *graph = new Graph;
    CommandLineInterface* cmd = new CommandLineInterface;
    Points p {.x = 0, .y = 0};

    do
    {
        std::cout << "$(dmartiro): ";
        std::getline(std::cin, command);
        cmd->prepare(command);
        if (!cmd->isValid())
           continue;
        if (command == CREATE)
        {
            p.x = 0;
            p.y = 0;
            std::cout << "Graph Size(X Y): ";
            std::cin >> p.x >> p.y;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(MAXLIMIT(std::streamsize), '\n');
                continue;
            }
            if (p.x > 0 &&  p.y > 0 && p.x < MAXLIMIT(float) && p.y < MAXLIMIT(float))
            {
                graph->clean();
                Command* createGraph = new CreateCommand(graph, p.x, p.y);
                cmd->run(graph, invoker, command, createGraph);
            }
        }
        else if (command == ADD)
        {
            std::cout << "Add New Point: ";
            std::cin >> p.x >> p.y;
            Command* addPoint = new AddPointCommand(graph, p.x, p.y);
            cmd->run(graph, invoker, command, addPoint);
        }
        else if (command == PRINT)
        {
            graph->print();
            continue;
        }
        else if (command == QUIT)
            break;
        else
        {
            std::cout << "Invalid command" << std::endl;
            continue;
        }
        std::cin.ignore(MAXLIMIT(std::streamsize), '\n');
    }
    while(1);

    delete invoker;
    delete graph;
    delete cmd;
}
