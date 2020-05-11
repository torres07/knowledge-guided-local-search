#include <iostream>
#include <vector>

#include "../include/FileParser.hpp"
#include "../include/Heuristics.hpp"

using namespace std;

int main()
{
    cout << "Starting parsing of graph..." << endl;
    vector<Vertex> vertices = FileParser::parseTxt("C:\\Users\\dev\\Downloads\\X-n101-k25.vrp");

    cout << "VRP - Vertex Description: " << endl;
    float totalDemand = 0.0;
    for (size_t i = 0; i < vertices.size(); i++)
    {
        Vertex vertex = vertices.at(i);
        cout << vertex.getId() << " @ " << "(" << vertex.getCoord1() << ", " << vertex.getCoord2() << ")" << " : " << vertex.getDemand() << endl;    
    
        totalDemand += vertex.getDemand();
    }

    cout << endl;
    cout << "Min Number of Routes: " << (int) (1.0 + totalDemand/206) << endl;
    cout << endl;

    cout << endl;
    cout << "Testing Bin Packing Heuristic for VRP..." << endl;
    vector<Route> sol = Heuristics::binPacking(vertices, 206);

    cout << endl;
    cout << "Bin Packing - Total Routes: " << sol.size() << endl;
    for (size_t i = 0; i < sol.size(); i++) {
        int *r = (sol.at(i)).route;

        /** Print routes for Bin Packing heuristics **/
        cout << "Route " << i << " :   ";
        int vertexId = 1;
        cout << vertexId << "  ";
        do {
            cout << r[vertexId] << "  ";
            vertexId = r[vertexId];
        } while(vertexId != 1);
        cout << " - cap: " << 206 - (sol.at(i)).capacity << endl;
    }

    return 0;
}