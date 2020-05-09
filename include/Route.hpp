#include <vector>

#include "../include/Edge.hpp"

class Route {
	private:
		std::vector<Edge> route;
        
	public:
		Route(std::vector<Edge> route);
		
		void addEdgeToRoute(Edge edge);
		std::vector<Edge> getRoute();
};