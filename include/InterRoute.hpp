#ifndef INTERROUTE_H
#define INTERROUTE_H

#include "../include/Route.hpp"
#include "../include/Vertex.hpp"

class InterRoute {
    public:
        static bool orExchange(Route r1, Route r2);
};

#endif