#ifndef ROUTE_H
#define ROUTE_H
#define MAX_SIZE 1005

#include <list>
#include <vector>
#include "../include/Vertex.hpp"

class Route {        
	public:
		int capacity;
		int maxSize;
		Vertex currentVertex;
		Vertex initialVertex;

		std::list<Vertex> route[MAX_SIZE];
		
		Route(Vertex depot, int maxSize, int capacity);
		Route getSubstring(int position, int size);
		void setCurrentByPosition(int position);
		Vertex nextVertex();
		void addVertexToRoute(Vertex v);
		void removeVertexFromRoute();
		void listPath();
		void addSubroute(Route r, int position);
		void removeSubroute(Route r);
};

#endif