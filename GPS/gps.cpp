#include "gps.hpp"
#include <iostream>
#include <cmath>
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846 // عدد پی
#endif

Gps::Gps() : width(0.0), length(0.0) {}

Gps::Gps(double width, double length)
{

    if (width < -90.0 || width > 90.0) // اگر در محدوده ای که اعلام کردیم نباشه ارور چاپ میشه
    {
        throw invalid_argument("width must be between -90 and 90 degrees.");
    }

    if (length < -180.0 || length > 180.0)// اگر در محدوده ای که اعلام کردیم نباشه ارور چاپ میشه
    {
        throw invalid_argument("length must be between -180 and 180 degrees.");
    }

    this->width = width;
    this->length = length;

    places.push_back({width, length});
}

Gps::~Gps()
{
    if (!places.empty()) // چک کردن اینکه خالی نباشه
    {
        size_t Sizee = places.size();
        cout << "The coordinates of your last place (" << places.back().first << " , " << places.back().second << ") destroyed.\n";
    }
}

double Gps::get_width() const { return width; }
double Gps::get_length() const { return length; }

void Gps::add_location(double width, double length)
{
    if (width < -90.0 || width > 90.0)// اگر در محدوده ای که اعلام کردیم نباشه ارور چاپ میشه
    {
        throw invalid_argument("width must be between -90 and 90 degrees.");
    }

    if (length < -180.0 || length > 180.0)// اگر در محدوده ای که اعلام کردیم نباشه ارور چاپ میشه
    {
        throw invalid_argument("length must be between -180 and 180 degrees.");
    }

    places.push_back({width, length});
}

double Gps::calculate_distance() const // مسافت طی شده بین مختصات اول و اخر رو چک می کنه
{
    if (places.size() < 2)
    {
        return 0.0;  
    }

    double lat1 = places[0].first * M_PI / 180.0;   // تبدیل درجه به رادیان
    double lon1 = places[0].second * M_PI / 180.0;
    double lat2 = places.back().first * M_PI / 180.0;
    double lon2 = places.back().second * M_PI / 180.0;

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dlon / 2) * sin(dlon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return 6371.0 * c; // کل فرمول های محاسبه مسافت بین دو مختصات تو این تابع از بالا تا اینجا انجام شده
}