#ifndef GPS_HPP
#define GPS_HPP
#include <iostream>
#include <vector>
#include <utility>

class Gps{

    private:
    double width;
    double length;
    std::vector<std::pair<double, double>> places;

    public:
    Gps();
    Gps(double width, double length);
    ~Gps();
    double get_width() const;
    double get_length() const;
    void add_location(double width, double length);
    double calculate_distance() const ;

};

#endif