#ifndef PATIENT_HPP
#define PATIENT_HPP
#include <iostream>
#include <string>
#include <cstdlib> // برای rand() و srand()
#include <ctime>   // برای time()

class Patient{

    private:
    std::string name;
    int age;
    double Bodytemperature;
    int Heartbeat;
    int Breathingrate;
    double Bloodpressure;

    public:
    Patient(std::string name, int age, double Bodytemperature, int Heartbeat, int Breathingrate, double Bloodpressure);
    ~Patient();
    std::string get_name();
    int get_age();
    double get_Bodytemperature();
    int get_Heartbeat();
    int get_Breathingrate();
    double get_Bloodpressure();
    void set_age(int age);
    void set_Bodytemperature(double Bodytemperature);
    void set_Heartbeat(int Heartbeat);
    void set_Breathingrate(int age, int Breathingrate);
    void set_Bloodpressure(int age, double Bloodpressure);

};

#endif