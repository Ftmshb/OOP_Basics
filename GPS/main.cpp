#include "gps.hpp"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void Tolower(string &str){ // کوچک کردن تمام حروف یک رشته
    int size = str.size();

    for(int i=0 ; i<size ; i++){
        str[i] = tolower(str[i]);
    }
}

string trim(const string& str) { // این تابع اسپیس اول و اخرشون رو در نظر نمی گیره
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) 
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

bool is_number(const string& str) { // چک می کنه رشته ای که وارد میشه عدد باشه
    for (char const& c : str) {
        if (!isdigit(c) && c != '.' && c != '-')
            return false;
    }
    return true;
}

int main(){ 
    Gps places;
    string input;
    
    while(true){
       
        double width, length;
        cout << "Please enter your geographical coordinates or exit:\n";
        getline(cin, input);

        input = trim(input); 

        if(!is_number(input)){ // اینکه عدد باشه
            Tolower(input);
        }
        if(input == "exit")
            break;

        if (input.empty()) { // اگر خالی داده باشه ارور چاپ میشه
            cerr << "Error: Empty input. Please enter valid coordinates.\n";
            continue;
        }
    
        try{
            
           size_t pos;
           width = stod(input, &pos);
           length = stod(input.substr(pos));

           places.add_location(width, length);
           cout << "Your place was successfuly stored with coordinates (" << width << " , " << length << ").\n";
        }
        catch (const invalid_argument& e){
            cerr << "Erorr: " << e.what() << endl;
        }
        catch(...){
            cerr << "Invalid input!\n";
        }    
    }

    double distance = places.calculate_distance();
    cout << "The distance you've traveled: " << distance << " km\n";

    return 0;
}