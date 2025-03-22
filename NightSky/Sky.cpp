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
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << '\n';
    }
}