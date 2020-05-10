#include <vector>
#include <list>
#include <string>

#include "../include/Vertex.hpp"
#include "../include/Route.hpp"

class Heuristics {
    public:
        static std::list<Route> binPacking(std::vector<Vertex> vertices, int maxCapacity);
}
   