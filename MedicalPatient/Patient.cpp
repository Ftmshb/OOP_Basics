#include "Patient.hpp"
#include <iostream>
using namespace std;

string Patient::cryptography(const string &str)
{
    string encrypted = str; 
    char key = 'F'; // رمزنگاری کردن رشته ای که بهش پاس داده میشه
    for (char &c : encrypted)
    {
        c ^= key;
    }
    return encrypted; // رشته رمزنگاری شده رو برمی گردونه
}

void Patient::SaveToFile(const string &filename, string newData)
{
    // بارگذاری داده‌های قبلی از فایل
    ifstream infile(filename);
    vector<string> RepeatedData; // یه وکتور از نوع رشته که داده های قبلی رو تو خودش نگه می داره
    string line;
    while (getline(infile, line))
    {
        RepeatedData.push_back(line);
    }
    infile.close();

    // بررسی تکراری نبودن داده‌های جدید
    bool isDuplicate = false;
    for (const auto &data : RepeatedData)
    {
        if (data == newData)
        {
            isDuplicate = true;
            break;
        }
    }

    //اگر داده‌های جدید تکراری نباشه، اونا رو به فایل اضافه می کنه
    if (!isDuplicate)
    {
        ofstream outfile(filename, ios::app);
        if (!outfile.is_open())
        {
            throw runtime_error("Could not open file for writing!");
        }
        outfile << newData << "\n";
        outfile.close();
    }
}

Patient::Patient(string name, int age, double Bodytemperature, int Heartbeat, int Breathingrate, double Bloodpressure, bool ShowingAgainTheWarning)
{
    if (ShowingAgainTheWarning == true) // این برای اینه که وقتی میخواد از فایل بخونه دوباره هشدار ها چاپ نشن چون موقع اضافه شدن و نوشتن تو فایل یه بار فراخوانی شدن
    {
        set_age(age);
        set_Bodytemperature(Bodytemperature);
        set_Heartbeat(Heartbeat);
        set_Breathingrate(age, Breathingrate);
        set_Bloodpressure(age, Bloodpressure);
    }

    this->name = name;
    this->age = age;
    this->Bodytemperature = Bodytemperature;
    this->Heartbeat = Heartbeat;
    this->Breathingrate = Breathingrate;
    this->Bloodpressure = Bloodpressure;
}

Patient::~Patient()
{
    try
    {         //رمزنگاری مشخصات بیمار
        string encryptedName = cryptography(name);
        string encryptedAge = cryptography(to_string(age));
        string encryptedTemperatur = cryptography(to_string(Bodytemperature));
        string encryptedHeartbeat = cryptography(to_string(Heartbeat));
        string encryptedBreathing = cryptography(to_string(Breathingrate));
        string encryptedPressure = cryptography(to_string(Bloodpressure));

        string newData = encryptedName + "-" + encryptedAge + "-" + encryptedTemperatur + "-" +
                         encryptedHeartbeat + "-" + encryptedBreathing + "-" + encryptedPressure;

        SaveToFile("patients.txt", newData); // سیو کردن تو فایل به صورتی که بالا گفته شد
        cout << "[~] " << name << " Patient data encrypted and saved to file succuessfuly.\n"; // چاپ کردن پیغام اینکه رمزنگاری شد
    }
    catch (const exception &e)
    {
        cerr << "Error saving patient data: " << e.what() << "\n";
    }
}

string Patient::get_name() { return name; }
int Patient::get_age() { return age; }
double Patient::get_Bodytemperature() { return Bodytemperature; }
int Patient::get_Heartbeat() { return Heartbeat; }
int Patient::get_Breathingrate() { return Breathingrate; }
double Patient::get_Bloodpressure() { return Bloodpressure; }

void Patient::set_age(int age)
{
    if (age < 0)
    {
        throw invalid_argument("Error: Age can not be negative!\n");
    }
    if (age > 100)
    {
        throw invalid_argument("Error: Enter age curructly!\n");
    }
}

void Patient::set_Bodytemperature(double Bodytemperature)
{
    if (Bodytemperature < 0)
    {
        throw invalid_argument("Error: Bodytemperature can not be negative!\n");
    }
    if (Bodytemperature < 36)
    {
        cout << "Be careful!: Your body temperature is low!\n";
    }
    if (Bodytemperature > 37.5)
    {
        cout << "Be careful!: Your body temperature is high!\n";
    }
}

void Patient::set_Heartbeat(int Heartbeat)
{
    if (Heartbeat < 0)
    {
        throw invalid_argument("Error: Heartbeat can not be negative!\n");
    }
    if (Heartbeat < 50)
    {
        cout << "Be careful!: Your heartbeat is low!\n";
    }
    if (Heartbeat > 100)
    {
        cout << "Be careful!: Your heartbeat is high!\n";
    }
}

void Patient::set_Breathingrate(int age, int Breathingrate)
{
    if (Breathingrate < 0)
    {
        throw invalid_argument("Error: Breathingrate can not be negative!\n");
    }
    if (age >= 0 && age <= 2)
    {
        if (Breathingrate < 25)
        {
            cout << "Be careful!: Your breathingrate is low!\n";
        }
        if (Breathingrate > 60)
        {
            cout << "Be careful!: Your breathingrate is high!\n";
        }
    }
    if (age > 2 && age <= 12)
    {
        if (Breathingrate < 18)
        {
            cout << "Be careful!: Your breathingrate is low!\n";
        }
        if (Breathingrate > 30)
        {
            cout << "Be careful!: Your breathingrate is high!\n";
        }
    }
    if (age > 12 && age <= 18)
    {
        if (Breathingrate < 12)
        {
            cout << "Be careful!: Your breathingrate is low!\n";
        }
        if (Breathingrate > 20)
        {
            cout << "Be careful!: Your breathingrate is high!\n";
        }
    }
    if (age > 18)
    {
        if (Breathingrate < 12)
        {
            cout << "Be careful!: Your breathingrate is low!\n";
        }
        if (Breathingrate > 18)
        {
            cout << "Be careful!: Your breathingrate is high!\n";
        }
    }
}

void Patient::set_Bloodpressure(int age, double Bloodpressure)
{
    if (Bloodpressure < 0)
    {
        throw invalid_argument("Error: Bloodpressure can not be negative!\n");
    }
    if (age >= 0 && age <= 2)
    {
        if (Bloodpressure < 45)
        {
            cout << "Be careful!: Your bloodpressure is low!\n";
        }
        if (Bloodpressure > 90)
        {
            cout << "Be careful!: Your bloodpressure is high!\n";
        }
    }
    if (age > 2 && age <= 12)
    {
        if (Bloodpressure < 50)
        {
            cout << "Be careful!: Your bloodpressure is low!\n";
        }
        if (Bloodpressure > 110)
        {
            cout << "Be careful!: Your bloodpressure is high!\n";
        }
    }
    if (age > 12 && age <= 18)
    {
        if (Bloodpressure < 60)
        {
            cout << "Be careful!: Your bloodpressure is low!\n";
        }
        if (Bloodpressure > 120)
        {
            cout << "Be careful!: Your bloodpressure is high!\n";
        }
    }
    if (age > 18)
    {
        if (Bloodpressure < 80)
        {
            cout << "Be careful!: Your bloodpressure is low!\n";
        }
        if (Bloodpressure > 120)
        {
            cout << "Be careful!: Your bloodpressure is high!\n";
        }
    }
}
