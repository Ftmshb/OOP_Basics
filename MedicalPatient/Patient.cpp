#include "Patient.hpp"
#include <iostream>
using namespace std;

Patient::Patient(string name, int age, double Bodytemperature, int Heartbeat, int Breathingrate, double Bloodpressure){
    set_age(age);
    set_Bodytemperature(Bodytemperature);
    set_Heartbeat(Heartbeat);
    set_Breathingrate(age, Breathingrate);
    set_Bloodpressure(age, Bloodpressure);

    this->name = name; 
    this->age = age;
    this->Bodytemperature = Bodytemperature;
    this->Heartbeat = Heartbeat;
    this->Breathingrate = Breathingrate;
    this->Bloodpressure = Bloodpressure;
}

Patient::~Patient(){
}

string Patient::get_name(){return name;}
int Patient::get_age(){return age;}
double Patient::get_Bodytemperature(){return Bodytemperature;}
int Patient::get_Heartbeat(){return Heartbeat;}
int Patient::get_Breathingrate(){return Breathingrate;}
double Patient::get_Bloodpressure(){return Bloodpressure;}

void Patient::set_age(int age){
    if(age < 0){
        throw invalid_argument("Error: Age can not be negative!\n");
    }
    if(age > 100){
        throw invalid_argument("Error: Enter age curructly!\n");
    }
}

void Patient::set_Bodytemperature(double Bodytemperature){
    if(Bodytemperature < 0){
        throw invalid_argument("Error: Bodytemperature can not be negative!\n");
    }
    if(Bodytemperature < 36){
        cout << "Be careful!: Your body temperature is low!\n";
    }
    if(Bodytemperature > 37.5){
        cout << "Be careful!: Your body temperature is high!\n";
    }
}

void Patient::set_Heartbeat(int Heartbeat){
    if(Heartbeat < 0){
        throw invalid_argument("Error: Heartbeat can not be negative!\n");
    }
    if(Heartbeat < 50){
        cout << "Be careful!: Your heartbeat is low!\n";
    }
    if(Heartbeat > 100){
        cout << "Be careful!: Your heartbeat is high!\n";
    }
}

void Patient::set_Breathingrate(int age, int Breathingrate){
    if(Breathingrate < 0){
        throw invalid_argument("Error: Breathingrate can not be negative!\n");
    }
    if(age >=0 && age <= 2){
        if(Breathingrate < 25){
            cout << "Be careful!: Your breathingrate is low!\n";
        }
        if(Breathingrate > 60){
            cout << "Be careful!: Your breathingrate is high!\n";
        }
    }
    if(age > 2 && age <= 12){
        if(Breathingrate < 18){
            cout << "Be careful!: Your breathingrate is low!\n";
        }
        if(Breathingrate > 30){
            cout << "Be careful!: Your breathingrate is high!\n";
        }
    }
    if(age > 12 && age <= 18){
        if(Breathingrate < 12){
            cout << "Be careful!: Your breathingrate is low!\n";
        }
        if(Breathingrate > 20){
            cout << "Be careful!: Your breathingrate is high!\n";
        }
    }
    if(age > 18){
        if(Breathingrate < 12){
            cout << "Be careful!: Your breathingrate is low!\n";
        }
        if(Breathingrate > 18){
            cout << "Be careful!: Your breathingrate is high!\n";
        }
    }
}

void Patient::set_Bloodpressure(int age, double Bloodpressure){
    if(Bloodpressure < 0){
        throw invalid_argument("Error: Bloodpressure can not be negative!\n");
    }
    if(age >=0 && age <= 2){
        if(Bloodpressure < 45){
            cout << "Be careful!: Your bloodpressure is low!\n";
        }
        if(Bloodpressure > 90){
            cout << "Be careful!: Your bloodpressure is high!\n";
        }
    }
    if(age > 2 && age <= 12){
        if(Bloodpressure < 50){
            cout << "Be careful!: Your bloodpressure is low!\n";
        }
        if(Bloodpressure > 110){
            cout << "Be careful!: Your bloodpressure is high!\n";
        }
    }
    if(age > 12 && age <= 18){
        if(Bloodpressure < 60){
            cout << "Be careful!: Your bloodpressure is low!\n";
        }
        if(Bloodpressure > 120){
            cout << "Be careful!: Your bloodpressure is high!\n";
        }
    }
    if(age > 18){
        if(Bloodpressure < 80){
            cout << "Be careful!: Your bloodpressure is low!\n";
        }
        if(Bloodpressure > 120){
            cout << "Be careful!: Your bloodpressure is high!\n";
        }
    }
}

