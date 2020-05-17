#include <iostream>
#include <vector>

#include "../include/FileParser.hpp"
#include "../include/Heuristics.hpp"
#include "../include/IntraRoute.hpp"

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
        cout << "Number: " << i << endl;
        sol[i].capacity = capacity - sol[i].capacity;
        sol[i].printRoute();
    }

    /** Next step: Neighbourhood Search -> Inter and Intra Route Local Search **/

    /** Applying only Intra-Route Neighborhood Search -> K-opt **/
    
    cout << "Applying intra-route optimization: k-opt algorithm..." << endl;
    Route r = sol[1];
    r.printRoute();
    for (size_t i = 0; i < 10; i++) {
        try {
            r = IntraRoute::kopt(r, 4);
        } catch(int e) {
            cout << "Can't optimize route through K-opt anymore" << endl;
        }   

        r.printRoute();
    }

    return 0;
}