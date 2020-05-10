#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

#include "../include/FileParser.hpp"

using namespace std;

int FileParser::extractIntFromString(string line, int pos) {
    int count = 0;
    int value;

    string temp;
    stringstream ss;
    
    ss << line;
    while(!ss.eof()) {
        ss >> temp;

        if(stringstream(temp) >> value) {
            if(count == pos) {
                return value;
            }

            count++;
        }
    }
    return -1;
}

std::vector<Vertex> FileParser::parseTxt(string path) {
    try
    {
        vector<Vertex> vertices;   
        int demandPos = 0;
                
        string line;
        ifstream txtFile (path);

        if(txtFile.is_open()) {
            string part = "header";
            while(getline(txtFile, line)) {
                if(part == "header") {
                    
                    /** Move to next section **/
                    int pos = line.find("NODE_COORD_SECTION");
                    if(pos != string::npos) {
                        part = "nodes";
                        continue;
                    }
                    
                    /** Parse header from txt **/
                    pos = line.find("CAPACITY");
                    if(pos != string::npos) {
                        /** Not being saved anywhere yet **/
                        int capacity = extractIntFromString(line, 0);
                    }
                }

                if(part == "nodes") {
                    
                    /** Move to next section **/
                    int pos = line.find("DEMAND_SECTION");
                    if(pos != string::npos) {
                        part = "demand";
                        continue;
                    }
                    
                    /** Parse node's position from txt **/
                    int id = extractIntFromString(line, 0);
                    int coord1 = extractIntFromString(line, 1);
                    int coord2 = extractIntFromString(line, 2);

                    Vertex vertex = Vertex(id, coord1, coord2, -1);
                    vertices.push_back(vertex);
                }

                if(part == "demand") {
                    /** End Parsing **/
                    int pos = line.find("DEPOT_SECTION");
                    if(pos != string::npos) {
                        break;
                    }

                    /** Parse node's demand from txt **/
                    int demand = extractIntFromString(line, 1);
                    vertices.at(demandPos).setDemand(demand);
                    demandPos++;
                }
            }

            txtFile.close();
        }
        return vertices;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
        return {};
    }
}
