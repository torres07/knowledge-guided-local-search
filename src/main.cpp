#include <iostream>
#include <vector>

#include "../include/FileParser.hpp"

using namespace std;

int main()
{
    cout << "Starting parsing of graph..." << endl;
    vector<Vertex> vertices = FileParser::parseTxt("C:\\Users\\dev\\Downloads\\X-n101-k25.vrp");

    cout << "VRP - Vertex Description: " << endl;
    for (size_t i = 0; i < vertices.size(); i++)
    {
        Vertex vertex = vertices.at(i);
        cout << vertex.getCoord1() << " - " << vertex.getCoord2() << " : " << vertex.getDemand() << endl;    
    }
    
    return 0;
}