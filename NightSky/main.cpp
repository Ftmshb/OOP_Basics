#include <iostream>
#include <string>
#include "Star.hpp"
#include "Sky.hpp"
using namespace std;

bool is_number(string &str)
{ // چک می کنه رشته ای که وارد میشه عدد باشه
    for (char const &c : str)
    {
        if (!isdigit(c) && c != '.' && c != '-')
        {
            throw invalid_argument("Pleas enter just number for coordinates only!\n");
            return false;
        }
    }
    return true;
}

int main()
{
    cout << "*********************************\n";
    cout << "* WELCOME TO THE SKY OF FATEMEH * \n";
    cout << "*********************************\n\n";
    Sky stars;
    try
    {
        while (true)
        {
            cout << "Pleas enter the star coordinates or exit : \n";
            string input;
            getline(cin, input);
            if (input == "exit")
            {
                break;
            }
            size_t space1 = input.find(' ');
            size_t space2 = input.find(' ', space1 + 1);
            string word1, word2, word3;

            if (space1 != string::npos && space2 != string::npos)
            {
                word1 = input.substr(0, space1);
                word2 = input.substr(space1 + 1, space2 - space1 - 1);
                word3 = input.substr(space2 + 1);
            }
            if (is_number(word1) && is_number(word2) && is_number(word3))
            {
                float x = stof(word1);
                float y = stof(word2);
                float brightness = stof(word3);

                Star star(x, y, brightness);
                stars.addStar(star);
            }
        }
        stars.show_all_star();
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