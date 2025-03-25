#include "Event.hpp"
#include <iostream>
using namespace std;

Event::Event(const string &name, time_t start_time, time_t end_time) : name(name), start_time(start_time), end_time(end_time) {}

Event::~Event()
{
    if (expily) // اینجا برای چاپ پیغام حذف شده شرط گذاشتیم که اگر بولین منقضی اون رویداد تورو بود چاپ کنه
    {
        cout << " Snooze: "<<  name  <<" event was deleted due to expired !!! \n";
    }
}

string Event::get_name() const { return name; }
time_t Event::get_start_time() const { return start_time; }
time_t Event::get_end_time() const { return end_time; }

void Event::set_expily(bool is_expily)
{
    expily = is_expily; // تورو یا فالس فرستاده میشه و در ویژگی انقضای رویداد قرار می گیره
}
