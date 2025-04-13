#ifndef __GRAPH__HPP__
#define __GRAPH__HPP__
#include <vector>
#include <string>
#include <iostream>
#include <limits>

struct Points{
    float x;
    float y;
};

class Vector2
{
    public:
        Vector2(float, float);
        ~Vector2();
        void setX(float);
        void setY(float);
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
        bool create(size_t, size_t);
        void setSizeX(size_t );
        void setSizeY(size_t);
        void addPoint(Vector2 const &);
        void print();
        void clean();
        std::vector<Vector2> getVector() { return m_points; };
    private:
        size_t m_sizeX;
        size_t m_sizeY;
        std::vector<Vector2> m_points;
};

#endif