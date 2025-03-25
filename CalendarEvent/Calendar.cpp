#include "Calendar.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

bool Calendar::interference(const Event &new_event) const // این تابع تداخل رویداد اضافه شده رو با رویداد های قبلی بررسی می کنه و اگه تداخل داشته باشه تورو بر می گردونه
{
    for (const auto &event : events)
    {
        if (new_event.get_start_time() < event.get_end_time() &&
            new_event.get_end_time() > event.get_start_time())
        {
        return true;
        }
    }
    return false;
}

void Calendar::add_event(const Event& event)
{
    if (interference(event)) // اگر تداخل داشته باشه ارور چاپ می کنه
    {
        cout << "Error: Event '" << event.get_name() << "' conflicts with existing events !!!\n----------\n";
        return;
    }

    events.push_back(event);
    cout << "Event '" << event.get_name() << "' added successfully.\n----------\n";
}

void Calendar::refresh()
{
    time_t now = time(nullptr);
    size_t sizee = events.size(); 

    for (size_t i = 0; i < sizee;)
    {
        if (events[i].get_end_time() < now)
        {
            swap(events[i], events.back()); // جابه جایی رویداد منقضی شده با اخرین رویداد در وکتور
            events.back().set_expily(true);// اگر منقضی شده باشه به تابع انقضا، تورو میفرسته و اون ویژگی انقضای رویداد رو تورو می کنه
            events.pop_back();//حذف اخرین رویداد در وکتور که همان رویداد منقضی شده است
            sizee--;
        }
        else
        {
            ++i;
        }
    } 
}

void Calendar::print_events() const
{
    for (const auto &event : events)
    {
        time_t start_time = event.get_start_time();
        time_t end_time = event.get_end_time();

        tm start_tm = *std::localtime(&start_time);
        tm end_tm = *std::localtime(&end_time);

        cout << "  -Event: " << event.get_name()
             << " (Start: " << put_time(&start_tm, "%Y-%m-%d %H:%M:%S")
             << ", End: " << put_time(&end_tm, "%Y-%m-%d %H:%M:%S") << ")\n";
    }
}