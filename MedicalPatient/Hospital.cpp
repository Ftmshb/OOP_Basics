#include "Hospital.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


Hospital::~Hospital()
{
    for (auto patient : Patients)
    {
        delete patient; // آزاد کردن حافظه هر بیمار
    }
}

string Hospital::decode(const string &str)
{
    string encrypted = str;
    char key = 'F';    // رمزگشایی کردن رشته ای که بهش پاس داده میشه
    for (char &c : encrypted)
    {
        c ^= key;
    }
    return encrypted;
}

void Hospital::add_patients(Patient *patient)
{
    Patients.push_back(patient);
    cout << "The patient was successfully added to the patient list!\n";
}

void Hospital::print_all_patients() const
{
    for (auto patient : Patients)
    {
        cout << "* Patient profile : *\n";
        cout << "     ~name: " << patient->get_name() << "\n";
        cout << "     ~age: " << patient->get_age() << " YEAR\n";
        cout << "     ~Bodytemperature: " << patient->get_Bodytemperature() << " C\n";
        cout << "     ~Heartbeat: " << patient->get_Heartbeat() << " BPM\n";
        cout << "     ~Breathingrate: " << patient->get_Breathingrate() << " breaths per minute\n";
        cout << "     ~Bloodpressure: " << patient->get_Bloodpressure() << " mm Hg\n";
        cout << "------------------------------\n";
    }
}

void Hospital::ReadFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        throw runtime_error("Could not open file for reading!");
    }

    for (auto patient : Patients)
    {
        delete patient;
    }
    Patients.clear();


    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string encryptedName, encryptedAge, encryptedTemp, encryptedHeartbeat, encryptedBreathing, encryptedPressure;
        
        // تجزیه خط به بخش‌های جداگانه
        getline(ss, encryptedName, '-');
        getline(ss, encryptedAge, '-');
        getline(ss, encryptedTemp, '-');
        getline(ss, encryptedHeartbeat, '-');
        getline(ss, encryptedBreathing, '-');
        getline(ss, encryptedPressure, '-');

        // رمزگشایی داده‌ها
        string name = decode(encryptedName);
        int age = stoi(decode(encryptedAge));
        double temp = stod(decode(encryptedTemp));
        int heartbeat = stoi(decode(encryptedHeartbeat));
        int breathing = stoi(decode(encryptedBreathing));
        double pressure = stod(decode(encryptedPressure));

        // ایجاد شی و اضافه کردن به لیست بیمارها
        Patient* patient = new Patient(name, age, temp, heartbeat, breathing, pressure, false);
        Patients.push_back(patient);    
    }
    file.close();
}