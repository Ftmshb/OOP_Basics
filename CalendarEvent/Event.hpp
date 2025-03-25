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
    bool expily=false;  // اینجا منقضی شدن هر رویداد رو به طور خودکار فالس قرار دادیم و بعدش تو تابع رفرش برررسی می کنیم.
    
    public:
    Event(const std::string& name, std::time_t start_time, std::time_t end_time);
    ~Event();
    std::string get_name() const;
    std::time_t get_start_time() const;
    std::time_t get_end_time() const;
    void set_expily(bool is_expily);  //در تابع رفرش اگر یک رویداد منقضی شده باشه به این تابع تورو پاس داده میشه
};

#endif