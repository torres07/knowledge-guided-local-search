#include "../include/Route.hpp"

using namespace std;

Route::Route(std::vector<Edge> route) {
    this->route = route;
}

void Route::addEdgeToRoute(Edge edge) {
    route.push_back(edge);
}