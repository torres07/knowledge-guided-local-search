#include <list>

#include "../include/Edge.hpp"

class Route {
	private:
		int * route;
		int capacity;
        
	public:
		Route(int maxSize, int capacity);
		void addEdgeToRoute(int prevEdgeId, int nextEdgeId);
		int * getRoute();
};