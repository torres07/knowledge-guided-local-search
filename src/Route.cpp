#include <cmath>

#include "../include/Route.hpp"

using namespace std;

Route::Route(Vertex depot, int maxSize, int capacity) {
    this->capacity = capacity;
    this->maxSize = maxSize;
    this->currentVertex = depot;
}


void Route::addVertexToRoute(Vertex v) {
    /** Edge calculation - cost associated with edge ending at this vertex **/
    v.cost = sqrt(pow(this->currentVertex.x - v.x, 2.0) + pow(this->currentVertex.y - v.y, 2.0));

    int id = this->currentVertex.id;
    this->route[id].push_back(v);
    this->currentVertex = v;
}




