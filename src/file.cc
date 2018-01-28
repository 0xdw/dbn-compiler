#include <iostream>
#include <fstream>
#include <string>

#include "constants.h"
#include "file.h"

const std::string get_file_content(const char* file_name) {
    
    std::string line;
    std::string out;
    std::ifstream file(file_name);

    if (file.is_open()) {
        while (std::getline(file, line)) {
            out += line + "\n";
        }
        file.close();
        return out;
    }

    std::cout << "Unable to open file " << file_name << std::endl;
    EXIT
}

void write_file(std::string source, const char* file_name) {
    std::ofstream svg;
    svg.open(file_name);
    svg << source;
    svg.close();
}