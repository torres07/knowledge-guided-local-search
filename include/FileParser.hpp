#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <vector>
#include <string>

#include "../include/Edge.hpp"

class FileParser {
    public:
        static int extractIntFromString(std::string line, int pos);
        static std::pair<std::vector<Vertex>, int> parseTxt(std::string path);
};

#endif