#include "debug.h"
#include <iostream>

using namespace debug;

void print_vector(std::vector<int>& v) {
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


void print_vv(std::vector<std::vector<int>&> vv) {
    std::cout << std::endl;
    for (auto v : vv) {
        std::cout << "X ";
        for (auto e : v) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
} 