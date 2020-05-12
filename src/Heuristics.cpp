#include <vector>
#include <algorithm>

#include "../include/Heuristics.hpp"

/** First attempt to code binPacking heuristics for VRP **/
/**
  * Order vertices by demand
  * Do 
    * Instantiate new route and point to first vertex not attended by previous route
    * Do
      *  Select the node with highest demand that fits in the route
      *  Add node to route
    *  while route still has room available
    * Add route to route list
  * while there exist vertices unattended 
**/

bool Heuristics::compare(Vertex v1, Vertex v2) {
    return (v1.demand < v2.demand);
}

std::vector<Route> Heuristics::binPacking(std::vector<Vertex> vertices, int maxCapacity) {
    std::vector<Route> sol;
    Vertex depot = vertices[0];
    vertices.erase(vertices.begin());

    /** Vertex ids start at 1 instead of 0. **/
    int size = vertices.size() + 1;

    std::sort(vertices.begin(), vertices.end(), compare);
    do {
        Route r = Route(size, maxCapacity);
        auto it = vertices.begin();
        while( (it != vertices.end()) || (r.capacity == 0) ) {
            if(r.capacity > it->demand) {
                
                r.addVertexToRoute(*it);
                r.capacity -= it->demand;

                it = vertices.erase(it);
            } else {
                ++it;
            }
        }

        /** Route starts and ends at Depot **/
        r.addVertexToRoute(depot);
        sol.push_back(r);

    } while (vertices.size() != 0);

    return sol;
}