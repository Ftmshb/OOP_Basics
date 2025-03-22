#include "Patient.hpp"
#include <iostream>
#include <vector>

class Hospital{

    private:
    std::vector<Patient*> Patients;

    public:
    void add_patients(Patient* patient);
    void print_all_patients() const;
    ~Hospital();
};