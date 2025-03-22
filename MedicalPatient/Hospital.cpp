#include "Hospital.hpp"
#include <iostream>
using namespace std;

void Hospital::add_patients( Patient* patient){
    Patients.push_back(patient);
    cout << "The patient was successfully added to the patient list!\n";
}

void Hospital::print_all_patients() const{
    for(auto patient : Patients){
        cout << "* Patient profile : *\n";
        cout << "     ~name: " << patient->get_name() << "\n";
        cout << "     ~age: " << patient->get_age() << " YEAR\n";
        cout << "     ~Bodytemperature: " << patient->get_Bodytemperature() <<  " ℃\n";
        cout << "     ~Heartbeat: " << patient->get_Heartbeat() << " BPM\n";
        cout << "     ~Breathingrate: " << patient->get_Breathingrate() << " breaths per minute\n";
        cout << "     ~Bloodpressure: " << patient->get_Bloodpressure() << " mm Hg\n";
        cout << "------------------------------\n";
    }
}

Hospital::~Hospital() {
    for (auto patient : Patients) {
        delete patient; // آزاد کردن حافظه هر بیمار
    }
}