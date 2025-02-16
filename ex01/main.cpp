#include <vector>
#include <iostream>
#include "Graph.hpp"
int main(int ac, char** av)
{
    (void)ac;
    (void)av;
    if (ac < 2)
    {
        std::cout << "Usage: ./ex01 <initial graph size>" << std::endl
            << "Initialize a graph with the specified size." << std::endl
            << "Arguments: <inital grap size> The number of points in the graph"
        << std::endl;
        return (1);
    }
    Graph graph;
    


}
