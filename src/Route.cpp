#include "../include/Route.hpp"

using namespace std;

Route::Route(int maxSize, int capacity) {
    this->capacity = capacity;
    this->route = new int [maxSize];
    this->currentVertexId = 1;
}

void Route::addVertexToRoute(int vertexId) {
    this->route[this->currentVertexId] = vertexId;
    this->currentVertexId = vertexId;
}


