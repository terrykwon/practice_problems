// #ifndef DEBUG_H
// #define DEBUG_H
#pragma once

#include <vector>
#include <string>


namespace debug {
    void print_vector(std::vector<int>& v);
    // void print_vector(std::vector<double>& v);
    // void print_vector(std::vector<std::string>& v);
    void print_vv(std::vector<std::vector<int>>& vv);
}


// #endif