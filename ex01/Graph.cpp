#include "Graph.hpp"

Vector2::Vector2(float _x, float _y)
    : x(_x), y(_y)
{

}

Vector2::~Vector2()
{

}

void Vector2::setX(float _x)
{
    x = _x;
}

void Vector2::setY(float _y)
{
    y = _y;
}

float Vector2::getX()
{
    return (x);
}

float Vector2::getY()
{
    return (y);
}


Graph::Graph()
    :m_sizeX(0), m_sizeY(0)
{
    (void)m_sizeX;
    (void)m_sizeY;
}

Graph::~Graph()
{

}

void Graph::clean()
{
    m_points.clear();
}

void Graph::setSizeX(size_t sizeX)
{
    m_sizeX = sizeX;
}

void Graph::setSizeY(size_t sizeY)
{
    m_sizeY = sizeY;
}


void Graph::print()
{
    std::cout << std::endl;
    // for(size_t y = m_sizeY + 1; y > 0;)
    // {
    //     // std::cout << --y << " ";
    //     for(size_t x = m_sizeX + 1; x > 0; x--)
    //     {
    //         if (x)
    //         std::cout << " • ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << "   ";
    // for(size_t x = 0; x < m_sizeX + 1; x++)
    //     std::cout << x << "  ";


    for(int y = (int)m_sizeY; y >= -1; y--)
    {
        for(int x = -1; x <= (int)m_sizeX; x++)
        {
            if (x == -1)
                if (y != -1)
                    std::cout << y << " ";
                else
                    std::cout << "O" << " ";
            else if (y != -1)
            {
                std::cout << " • ";
            }
            else
                std::cout << " " << x << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

bool Graph::create(size_t sizeX, size_t sizeY)
{
    m_sizeX = sizeX;
    m_sizeY = sizeY;
    this->print();
    return (true);//unused
}

void Graph::addPoint(Vector2 const &point)
{
    m_points.push_back(point);
}