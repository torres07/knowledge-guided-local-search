#pragma once

#include <list>

#include "../include/Edge.hpp"

class Route {
	public:
		int * route;
		int capacity, currentVertexId;

		Route(int maxSize, int capacity);
		void addVertexToRoute(int vertexId);
};