#include "Hospital.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string Hospital::decode(const std::string &str)
{
    string encrypted = str;
    char key = 'F';
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

Hospital::~Hospital()
{
    for (auto patient : Patients)
    {
        delete patient; // آزاد کردن حافظه هر بیمار
    }
}

/*void Hospital::SaveToFile(const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        throw runtime_error("Could not open file for writing!");
    }
    for (const auto &patient : Patients)
    {
        string encryptedName = patient->cryptography(patient->get_name());
        string encryptedAge = patient->cryptography(to_string(patient->get_age()));
        string encryptedTemp = patient->cryptography(to_string(patient->get_Bodytemperature()));
        string encryptedHeartbeat = patient->cryptography(to_string(patient->get_Heartbeat()));
        string encryptedBreathing = patient->cryptography(to_string(patient->get_Breathingrate()));
        string encryptedPressure = patient->cryptography(to_string(patient->get_Bloodpressure()));

        // ذخیره‌سازی داده‌های رمزنگاری شده در فایل
        file << encryptedName << "-"
             << encryptedAge << "-"
             << encryptedTemp << "-"
             << encryptedHeartbeat << "-"
             << encryptedBreathing << "-"
             << encryptedPressure << "\n";
    }

    file.close();
}*/

void Hospital::LoadFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        throw runtime_error("Could not open file for reading!");
    }

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

        // ایجاد شیء Patient و اضافه کردن به لیست
        Patient* patient = new Patient(name, age, temp, heartbeat, breathing, pressure);
        Patients.push_back(patient);    
    }
    file.close();
}