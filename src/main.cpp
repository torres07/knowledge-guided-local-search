#include <iostream>
#include <vector>

#include "../include/FileParser.hpp"
#include "../include/Heuristics.hpp"

using namespace std;

int main() {
    cout << "Starting parsing of graph..." << endl;
    pair<vector<Vertex>, int> rFileParse;
    rFileParse = FileParser::parseTxt("instances/X-n101-k25.vrp");

    vector<Vertex> vertices = rFileParse.first;
    int capacity = rFileParse.second;

    cout << "VRP - Vertex Description: " << endl;
    float totalDemand = 0.0;
    for (size_t i = 0; i < vertices.size(); i++) {
        Vertex vertex = vertices[i];
        cout << vertex.id << " @ " << "(" << vertex.x << ", " << vertex.y << ")" << " : " << vertex.demand << endl;    
    
        totalDemand += vertex.demand;
    }

    cout << endl;
    cout << "Min Number of Routes: " << (int) (1.0 + totalDemand/capacity) << endl;
    cout << endl;

    cout << endl;
    cout << "Testing Bin Packing Heuristic for VRP..." << endl;
    vector<Route>sol = Heuristics::binPacking(vertices, capacity);

    cout << endl;
    cout << "Bin Packing - Total Routes: " << sol.size() << endl;
    
    for (size_t i = 0; i < sol.size(); i++) {
        Route r = sol[i];
        
        // Print routes for Bin Packing heuristics
        int vertexId = 1;
        float cost = 0;

        cout << "Route " << i << " :   " << vertexId << "  ";
        do {
            auto it = r.route[vertexId].begin();
            cout << it->id << "  ";
            vertexId = it->id;
            cost += it->cost;
        } while(vertexId != 1);
        cout << "- cap: " << capacity - r.capacity << " - cost: " << cost << endl;
    }

    /** Next step: Neighbourhood Search -> Inter and Intra Route Local Search **/

    return 0;
}