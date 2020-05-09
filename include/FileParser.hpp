#include <vector>
#include <string>

#include "../include/Vertex.hpp"

class FileParser {
    public:
        static int extractIntFromString(std::string line, int pos);
        static std::vector<Vertex> parseTxt(std::string path);
            
};