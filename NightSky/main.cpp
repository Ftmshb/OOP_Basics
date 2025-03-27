#include <iostream>
#include <string>
#include "Star.hpp"
#include "Sky.hpp"
using namespace std;

void is_number(string &str)
{ // چک می کنه رشته ای که وارد میشه عدد باشه
    for (char const &c : str)
    {
        if (!isdigit(c) && c != '.' && c != '-')
        {
            throw invalid_argument("Pleas enter just number for coordinates only!\n");
        }
    }
}

int main()
{
    cout << "*********************************\n";
    cout << "* WELCOME TO THE SKY OF FATEMEH * \n";
    cout << "*********************************\n\n";
    Sky stars;
    
        while (true)
        {
            cout << "Pleas enter the star coordinates 'x , y' or exit : \n   X and Y must be betweem 1 and 20!\n";
            string input;
            getline(cin, input);
            if (input == "exit")
            {
                break;
            }
            size_t space1 = input.find(' ');
            string word1, word2;

            if (space1 != string::npos)
            {
                word1 = input.substr(0, space1);
                word2 = input.substr(space1 + 1);
            }
                
                
                cout << " According to blow nter 1 or 2 or 3 for brightness of the star: \n";
                cout << "Star with low bightness: enter 1\n";
                cout << "Star with moderate bightness: enter 2\n";
                cout << "Star with high bightness: enter 3\n";
                string word3;
                getline(cin, word3);
                    
                
                try{
                    int x = stoi(word1);
                int y = stoi(word2);
                int brightness = stoi(word3);
                   Star star(x, y, brightness);
                   stars.addStar(star);
                   cout << "Star added successfuly!\n";
                   continue;
                }
                catch (invalid_argument &e)
                {
                    cerr << e.what();
                }
                catch (...)
                {
                    cerr << "Error: Invalid input!\n";
                }
        }
        stars.show_all_star();
}