#include "Patient.hpp"
#include <iostream>
#include <vector>
#include <vector>
#include <fstream>

class Hospital{

    private:
    std::vector<Patient*> Patients;
    static std::string decode(const std::string& str); // تابع برای رمزگشایی کردن

    public:
    void add_patients(Patient* patient);
    void print_all_patients() const;
    ~Hospital();
    void LoadFromFile(const std::string& filename);

};