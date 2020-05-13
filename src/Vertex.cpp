#include "../include/Vertex.hpp"

Vertex::Vertex(int id, int x, int y, float demand) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->demand = demand;
    this->cost = 0.0;
}

Vertex::Vertex() {
    this->id = -1;
    this->x = -1;
    this->y = -1;
    this->demand = -1;
    this->cost = 0;
}