#include "../include/Route.hpp"

using namespace std;

Route::Route(int maxSize, int capacity) {
    this->capacity = capacity;
    this->route = new int [maxSize];
}

void Route::addEdgeToRoute(int prevEdgeId, int nextEdgeId) {
    this->route[prevEdgeId] = nextEdgeId;
}

int * Route::getRoute() {
    return this->route;
}





