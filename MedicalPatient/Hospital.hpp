#include "Patient.hpp"
#include <iostream>
#include <vector>
#include <vector>
#include <fstream>

class Hospital{

    private:
    std::vector<Patient*> Patients; // وکتوری از نوع کلاس بیمار برای نگهداری بیمارها
    static std::string decode(const std::string& str); // تابع برای رمزگشایی کردن

    public:
    ~Hospital();
    void add_patients(Patient* patient); // اضافه کردن بیمار به وکتور
    void print_all_patients() const;
    void ReadFromFile(const std::string& filename); // خواندن از فایل

};