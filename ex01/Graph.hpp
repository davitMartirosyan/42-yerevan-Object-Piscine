#ifndef __GRAPH__HPP__
#define __GRAPH__HPP__
#include <vector>

class Vector2
{
    public:
        Vector2(float _x, float _y);
        ~Vector2();
    private:
        float x;
        float y;    
    public:
        friend class Graph;
};

class Graph
{
    public:
        Graph();
        Graph(size_t sizeX, size_t sizeY);
        ~Graph();
    public:
        bool create(size_t w, size_t h);
        void print( void );
    private:
        size_t m_sizeX;
        size_t m_sizeY;
        Vector2* m_vecPoints;
};

#endif