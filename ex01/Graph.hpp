#ifndef __GRAPH__HPP__
#define __GRAPH__HPP__
#include <vector>
#include <string>
#include <iostream>
#include <limits>
class Vector2
{
    public:
        Vector2(float _x, float _y);
        ~Vector2();
        void setX(float _x);
        void setY(float _y);
        float getX();
        float getY();
    private:
        float x;
        float y;
};

class Graph
{
    public:
        Graph();
        ~Graph();
    public:
        bool create(size_t w, size_t h);
        void setSizeX(size_t w);
        void setSizeY(size_t h);
        void addPoint(Vector2 const &point);
        void print();
        void clean();
    private:
        size_t m_sizeX;
        size_t m_sizeY;
        std::vector<Vector2> m_points;
};

#endif