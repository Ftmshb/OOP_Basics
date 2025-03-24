#include "Character.hpp"
#include "Game.hpp"
#include <iostream>
using namespace std;

void Tolower(string &str){ //کوچک کردن تمام حروف یک رشته
    int size = str.size();

    for(int i=0 ; i<size ; i++){
        str[i] = tolower(str[i]);
    }
}

int main()
{
    try
    {
        Character *Geralt = new Character("Geralt", "100", "100"); // برای اینکه وقتی از یک مهارت استفاده می کنه مستقیم از قدرتش کم شه به صورت پوینتر تعریف کردم
        Geralt->addSkill("Fighting with a sword", "10");
        Geralt->addSkill("Magic", "5");

        Character *ArthurMargon = new Character("ArthurMargon", "100", "50");
        ArthurMargon->addSkill("Fighting with a gun", "10");

        Game games;
        games.addCharacter(Geralt);
        games.addCharacter(ArthurMargon);

        games.printAllCharacters(); // چاپ همه شخصیت ها با تمام ویژگی ها

        
        // مثلا اینجا یک جنگ بین کاراکتر گرالت و آرتور مورگان رخ می دهد:
        cout << "  *                                                               *\n";
        cout << " ***                                                             ***\n";
        cout << "***** war between Geralt character and Arthur Morgan character: *****\n";
        cout << " ***                                                             ***\n";
        cout << "  *                                                               *\n";
        Geralt->useSkill("Fighting with a sword", 15);
        ArthurMargon->useSkill("Fighting with a gun", 30);


        games.printAllCharacters(); // اینجاهم یک بار دیگر تمام شخصیت ها با ویزگی هاشون رو چاپ می کنیم و میبنیم که قدرت آنها کم شده
        
        delete Geralt;
        delete ArthurMargon;

        Character *Sehiro = new Character("Sehiro", "95", "10fati"); //مثلا الان اینجا چون قدرت رو عدد ندادیم ارورشو چاپ می کنه و بقیه برنامه اجرا نمیشه، برای سلامتی و لول مهارت هم این ویژگی بررسی میشه

    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    
    return 0;
}