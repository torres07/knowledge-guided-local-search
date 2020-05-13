#include "../include/Route.hpp"
#include "../include/Vertex.hpp"

using namespace std;

Route::Route(int maxSize, int capacity) {
    this->capacity = capacity;
    this->maxSize = maxSize;
    this->currentVertexId = 1;
}


void Route::addVertexToRoute(Vertex v) {
    this->route[this->currentVertexId].push_back(v);
    this->currentVertexId = v.id;
}


