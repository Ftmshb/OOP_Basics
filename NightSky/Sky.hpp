#ifndef SKY_HPP
#define SKY_HPP
#include "Star.hpp"
#include <iostream>
#include <vector>

class Sky{

    private:
    std::vector<Star> stars;

    public:
    void addStar(const Star& star);
    void show_all_star();
};

#endif