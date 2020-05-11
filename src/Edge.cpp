#include "../include/Edge.hpp"

// Edge::Edge(Vertex v1, Vertex v2) {
//     setV1(v1);
//     setV2(v2);
// }

void Edge::setV1(Vertex v1) {
    this->v1 = v1;
}

Vertex Edge::getV1() {
    return this->v1;
}

void Edge::setV2(Vertex v2) {
    this->v2 = v2;
}

Vertex Edge::getV2() {
    return this->v2;
}