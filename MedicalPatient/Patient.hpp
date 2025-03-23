#ifndef PATIENT_HPP
#define PATIENT_HPP
#include <iostream>
#include <string>
#include <cstdlib> // برای rand() و srand()
#include <ctime>   // برای time()
#include <vector>
#include <fstream>

class Patient{

    private:
    std::string name;
    int age;
    double Bodytemperature; //دمای بدن بیمار
    int Heartbeat; //ضربان قلب بیمار
    int Breathingrate; //نرخ تنفس بیمار
    double Bloodpressure; //فشارخون بیمار
    std::string cryptography(const std::string& str);// تابع برای رمزنگاری کردن
    void SaveToFile(const std::string& filename, std::string newData); //تابع برای سیو کردن تو فایل
    
    public:
    Patient(std::string name, int age, double Bodytemperature, int Heartbeat, int Breathingrate, double Bloodpressure, bool ShowingAgainTheWarning = true);
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