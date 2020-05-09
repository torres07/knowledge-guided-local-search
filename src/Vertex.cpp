#include "../include/Vertex.hpp"

Vertex::Vertex(int coord1, int coord2, float demand) {
    setCoord1(coord1);
    setCoord2(coord2);
    setDemand(demand);
}

void Vertex::setCoord1(int coord1) {
    this->coord1 = coord1;
}

int Vertex::getCoord1() {
    return this->coord1;
}

void Vertex::setCoord2(int coord2) {
    this->coord2 = coord2;
}

int Vertex::getCoord2() {
    return this->coord2;
}

void Vertex::setDemand(float demand) {
    this->demand = demand;
}

float Vertex::getDemand() {
    return this->demand;
}

