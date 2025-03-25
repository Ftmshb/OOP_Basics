#ifndef EVENT_HPP
#define EVENT_HPP
#include <iostream>
#include <string>
#include <ctime>

class Event{

    private:
    std::string name;
    std::time_t start_time;
    std::time_t end_time;

    public:
    Event(const std::string& name, std::time_t start_time, std::time_t end_time);
    ~Event();
    std::string get_name() const;
    std::time_t get_start_time() const;
    std::time_t get_end_time() const;
};

#endif