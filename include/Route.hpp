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
		std::list<Vertex> route[MAX_SIZE];
	
		Route(Vertex depot, int maxSize, int capacity);
		
		float cost(Vertex vIn, Vertex vOut);
		void addVertexToRoute(Vertex v);
		std::pair<int, Vertex> findMostExpensiveEdge();
		std::pair<int, Vertex> selectRandomEdge();
		std::list<Vertex> list();
		void replaceEdge(std::pair<int, Vertex> eOut, std::pair<int, Vertex> eIn);
		void printRoute();
};

#endif