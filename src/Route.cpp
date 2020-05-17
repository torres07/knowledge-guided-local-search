#include <cmath>
#include <iostream>

#include "../include/Route.hpp"

using namespace std;

Route::Route(Vertex depot, int maxSize, int capacity) {
	this->capacity = capacity;
	this->maxSize = maxSize;
	this->currentVertex = depot;
	this->initialVertex = depot;
}

void Route::addVertexToRoute(Vertex v) {
	/** Edge calculation - cost associated with edge ending at this vertex **/
	v.cost = sqrt(pow(this->currentVertex.x - v.x, 2.0) + pow(this->currentVertex.y - v.y, 2.0));

	int id = this->currentVertex.id;
	this->route[id].push_back(v);
	this->currentVertex = v;
}

void Route::removeVertexFromRoute(){

}

void Route::listPath(){
	int initialVertexId = this->initialVertex.id;
	int vertexId = initialVertexId;
	
	printf("%d  ",vertexId);

	do {
		auto it = this->route[vertexId].begin();
		cout << it->id << "  ";
		vertexId = it->id;
	} while(vertexId != initialVertexId);	
	cout << endl;
}

Vertex Route::nextVertex(){
	return *this->route[this->currentVertex.id].begin();
}

void Route::setCurrentByPosition(int position){
	this->currentVertex = this->initialVertex;

	for (int i = 1; i <= position; i++){
		this->currentVertex = this->nextVertex();
	}
}

Route Route::getSubstring(int position, int size){
	// auxiliar route r.
	Route r = *this;
	r.setCurrentByPosition(position);

	Route subRoute = Route(r.currentVertex, r.maxSize, r.capacity);

	for (int i = 1; i < size; i++){
		r.currentVertex = r.nextVertex();
		subRoute.addVertexToRoute(r.currentVertex);
	}

	return subRoute;
}

void Route::addSubroute(Route subRoute, int position){
	this->setCurrentByPosition(position);
	Vertex nextVertex = this->nextVertex();
	this->route[this->currentVertex.id].pop_back();

	subRoute.setCurrentByPosition(0);

	do {
		this->addVertexToRoute(subRoute.currentVertex);
		subRoute.currentVertex = subRoute.nextVertex();
	}
	while (!subRoute.route[subRoute.currentVertex.id].empty());
	this->addVertexToRoute(subRoute.currentVertex);
	this->addVertexToRoute(nextVertex);
}

void Route::removeSubroute(Route subRoute){
	this->currentVertex = this->initialVertex;
	subRoute.currentVertex = subRoute.initialVertex;
	
	while (this->nextVertex().id != subRoute.initialVertex.id){
		this->currentVertex = this->nextVertex();
	}

	Vertex lastVertex = this->currentVertex; // vertex before subroute
	// start removing vertices
	while (this->nextVertex().id == subRoute.currentVertex.id){
		Vertex v = this->currentVertex;
		Vertex nextVertex = this->nextVertex();
		this->route[v.id].pop_back();
		
		// move forward
		this->currentVertex = nextVertex;
		subRoute.currentVertex = subRoute.nextVertex();
	}

	// link route again
	this->route[lastVertex.id].push_back(this->currentVertex);	
}