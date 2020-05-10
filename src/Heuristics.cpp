#include "../include/Edge.hpp"
#include "../include/Heuristics.hpp"

/** First attempt to code binPacking heuristics for VRP **/
std::list<Route> binPacking(std::vector<Vertex> vertices, int maxCapacity) {
    int size = vertices.size();

    /**
      * Do 
        * Order vertices by demand
        * Do
            *  Select the node with highest demand that fits in the route
            *  Add node to route
        *  while route still has room available
        * Instantiate new route and point back to first vertex not attended by previous route
      * while there exist vertices not attended 
    **/

}