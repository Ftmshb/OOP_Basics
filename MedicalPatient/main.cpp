#include "Patient.hpp"
#include "Hospital.hpp"
#include <iostream>
using namespace std;

void Tolower(string &str){ // کوچک کردن تمام حروف یک رشته
    int size = str.size();

    for(int i=0 ; i<size ; i++){
        str[i] = tolower(str[i]);
    }
}

int main(){

    cout << "* WELCOME *\n";
    Hospital hospital;

    try {
        hospital.ReadFromFile("patients.txt"); // خواندن از فایل
    } 
    catch (const exception& e) {
        cout << e.what() << "\n";
    }

    while(true){
        cout << "Enter continue or exit: \n";
        string input;
        cin >> input;
        Tolower(input);

        if (input == "exit"){
            break;
        }
        if(input == "continue"){
            cout << "Enter your name: \n";
            string name;
            cin >> name;

            cout << "Enter your age: \n";
            int age;
            cin >> age;

            cout << "Enter your Bodytemperature: \n";
            double Bodytemperature;
            cin >> Bodytemperature;

            cout << "Enter your Heartbeat: \n";
            int Heartbeat;
            cin >> Heartbeat;

            cout << "Enter your Breathingrate: \n";
            int Breathingrate;
            cin >> Breathingrate;

            cout << "Enter your Bloodpressure: \n";
            double Bloodpressure;
            cin >> Bloodpressure;
            
            try{
                Patient* patient = new Patient(name, age, Bodytemperature, Heartbeat, Breathingrate, Bloodpressure);
                hospital.add_patients(patient); // ایجاد شی و ضافه کردن اشاره‌گر به بیمارستان
            }
            catch(invalid_argument &e){
                cout << e.what();
            }
            catch(...){
                cout << "Error!\n";
            }
        }
    }
    hospital.print_all_patients(); // چاپ کردن تمام بیمارها
    return 0;
}