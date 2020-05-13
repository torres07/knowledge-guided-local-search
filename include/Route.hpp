#ifndef ROUTE_H
#define ROUTE_H
#define MAX_SIZE 1005

#include <list>
#include "../include/Vertex.hpp"

class Route {        
	public:
		int capacity;
		int maxSize;
		Vertex currentVertex;
		std::list<Vertex> route[MAX_SIZE];
		
		Route(Vertex depot, int maxSize, int capacity);
		void addVertexToRoute(Vertex v);
};

#endif