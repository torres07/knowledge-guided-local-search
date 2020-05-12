#ifndef HEURISTICS_H
#define HEURISTICS_H

#include <vector>
#include <list>
#include <string>

#include "../include/Route.hpp"
#include "../include/Vertex.hpp"

class Heuristics {
    public:
        static bool compare(Vertex v1, Vertex v2);
        static std::vector<Route> binPacking(std::vector<Vertex> vertices, int maxCapacity);
};

#endif