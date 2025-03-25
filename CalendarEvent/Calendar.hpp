#ifndef CALENDAR_HPP
#define CALENDAR_HPP
#include "Event.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <memory>

class Calendar{

    private:
    std::vector<Event> events; 

    public:
    bool interference(const Event& new_event) const;
    void add_event(const Event& event);
    void refresh();
    void print_events() const;
};

#endif