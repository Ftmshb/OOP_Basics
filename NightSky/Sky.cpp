#include <iostream>
#include "Sky.hpp"
using namespace std;

void Sky::addStar(const Star& star) {
    stars.push_back(star);
}
void Sky:: show_all_star(){
    for(int row = 0; row <= 20; row++){
        for(int col = 0; col <= 20; col++){

            for(Star& star : stars)
            if(row == star.get_y() && col == star.get_x()){
                if(star.get_brightness() == 1){
                    cout << "~";
                }
                if(star.get_brightness() == 2){
                    cout << "*";
                }
                if(star.get_brightness() == 3){
                    cout << "@";
                }
            }
            else{
                cout << " ";
            }
        }
        cout << '\n';
    }
}