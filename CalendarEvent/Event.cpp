#include "Event.hpp"
#include <iostream>
using namespace std;

Event::Event(const string &name, time_t start_time, time_t end_time) : name(name), start_time(start_time), end_time(end_time) {}

Event::~Event()
{
        cout << " Snooze: "<<  name  <<" event was deleted due to expired !!! \n";
}

string Event::get_name() const { return name; }
time_t Event::get_start_time() const { return start_time; }
time_t Event::get_end_time() const { return end_time; }

