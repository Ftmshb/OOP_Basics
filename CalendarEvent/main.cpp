#include "calendar.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

void Tolower(string &str){ // کوچک کردن تمام حروف یک رشته
    int size = str.size();

    for(int i=0 ; i<size ; i++){
        str[i] = tolower(str[i]);
    }
}

time_t parse_date(const std::string& date_str) { // تاریخ و ساعتی که میفرستیم رو به ثانیه های گذرونده شده تبدیل می کنه
    tm tm = {0}; 
    istringstream ss(date_str); 

    
    ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");

    if (ss.fail()) {
        throw invalid_argument("Invalid date format. Please use YYYY-MM-DD HH:MM:SS.\n");
    }

    return mktime(&tm); 
}

int main() {
    Calendar calendar;
    string input;

    while (true) {
        string name, start_date_str, end_date_str;

        
        cout << "Enter event name or enter the 'exit' to exit :\n";
        getline(cin, name);
        Tolower(name);

        if (name == "exit") {
            break;
        }

        cout << "Enter start date (YYYY-MM-DD HH:MM:SS):\n";
        getline(cin, start_date_str);

        
        cout << "Enter end date (YYYY-MM-DD HH:MM:SS):\n";
        getline(cin, end_date_str);

        try {
            
            auto start_time = parse_date(start_date_str);
            auto end_time = parse_date(end_date_str);

            
            Event event(name, start_time, end_time);
            calendar.add_event(event);

        } 
        catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << "\n";
        }
    }

    // نمایش رویدادها
    cout << "Current events:\n";
    calendar.print_events();
    cout << "     *---------------*     \n";

    // بروزرسانی تقویم و حذف رویدادهای منقضی شده
    calendar.refresh();

    vector<Event> expired_events;

    expired_events.clear();

    // نمایش رویدادها پس از بروزرسانی
    cout << "Events after refresh:\n";
    calendar.print_events();
    cout << "     *---------------*     \n";

    return 0;
}
