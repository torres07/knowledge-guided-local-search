#ifndef EDGE_H
#define EDGE_H

#include "../include/Vertex.hpp"

class Edge {
	private:
		Vertex v1;
        Vertex v2;

	public:
		Edge(Vertex v1, Vertex v2);
		
		void setV1(Vertex v1);
		Vertex getV1();

		void setV2(Vertex v2);
		Vertex getV2();
};

#endif