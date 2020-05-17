#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "../include/Route.hpp"

using namespace std;

Route::Route(Vertex depot, int maxSize, int capacity) {
    this->capacity = capacity;
    this->maxSize = maxSize;
    this->currentVertex = depot;
}

void Route::addVertexToRoute(Vertex v) {
    /** Edge calculation - cost associated with edge ending at this vertex **/
    v.cost = this->cost(this->currentVertex, v);

    int id = this->currentVertex.id;
    this->route[id].push_back(v);
    this->currentVertex = v;
}

float Route::cost(Vertex vIn, Vertex vOut) {
    return sqrt(pow(vIn.x - vOut.x, 2.0) + pow(vIn.y - vOut.y, 2.0));
}

pair<int,Vertex> Route::findMostExpensiveEdge() {
    std::list<Vertex> vertices = this->list();
    Vertex prev_v = vertices.back();
    Vertex exp_v = vertices.front();

    pair<int,Vertex> edge = std::make_pair(prev_v.id, exp_v);
    for(auto v : vertices) {
        if(edge.second.cost < v.cost) {
            edge = std::make_pair(prev_v.id, v);
        }
        prev_v = v;
    }
    return edge;        
}

pair<int,Vertex> Route::selectRandomEdge() {
    std::list<Vertex> vertices = this->list();
    
    int i = rand() % vertices.size();
    auto it = vertices.begin();
    std::advance(it, i);
    Vertex v = *it;

    pair<int,Vertex> edge = std::make_pair(v.id, *this->route[v.id].begin());
    return edge;        
}

std::list<Vertex> Route::list() {
    int id = 1;
    std::list<Vertex> vertices;
    
    do {
        auto it = this->route[id].begin();
        vertices.push_back(*it);
        id = (*it).id;
    } while(id != 1);

    return vertices;
}

/** Replace edge in k-opt algorithm **/
void Route::replaceEdge(std::pair<int, Vertex> eOut, std::pair<int, Vertex> eIn) {
    this->route[eOut.first].remove(eOut.second);
    this->route[eIn.first].push_back(eIn.second);
}

void Route::printRoute() {
    int vertexId = 1;
    float cost = 0;

    cout << "Route: " << " :   " << vertexId << "  ";
    do {
        auto it = this->route[vertexId].begin();
        cout << it->id << "  ";
        vertexId = it->id;
        cost += it->cost;
    } while(vertexId != 1);
    cout << "- cap: " << this->capacity << " - cost: " << cost << endl;
}






