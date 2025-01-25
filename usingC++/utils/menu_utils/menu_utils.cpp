// menu_utils.cpp
#include "menu_utils.h"
#include <iostream>

void printHeader(const std::string& title) {
    std::cout << "\n=============================================" << std::endl;
    std::cout << "              " << title << std::endl;
    std::cout << "=============================================" << std::endl;
}

void printFooter() {
    std::cout << "=============================================" << std::endl;
}
