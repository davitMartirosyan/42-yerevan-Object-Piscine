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
    for(int y = (int)m_sizeY; y >= -1; y--)
    {
        for(int x = -1; x <= (int)m_sizeX; x++)
        {
            if (x == -1)
                if (y != -1)
                    std::cout << "\033[32m" << y << "\033[0m ";
                else
                    std::cout << "\033[31m" << "O" << "\033[0m ";
            else if (y != -1){
                bool found = false;
                for(size_t i = 0; i < m_points.size(); i++){
                    if (m_points[i].getX() == x && m_points[i].getY() == y)
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                    std::cout << "\033[33m * \033[0m";
                else
                    std::cout << "\033[34m • \033[0m";
            }
            else
                std::cout << " " << "\033[32m" << x << "\033[0m ";
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