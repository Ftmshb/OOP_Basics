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

        Character *Jooel = new Character("Jooel", "100", "90");
        Jooel->addSkill("Fighting with cold weapons", "10");
        Jooel->addSkill("Killing zombies", "10");
        Jooel->addSkill("High fighting skills", "8");

        Game games;
        games.addCharacter(Geralt);
        games.addCharacter(ArthurMargon);
        games.addCharacter(Jooel);

        games.printAllCharacters(); // چاپ همه شخصیت ها با تمام ویژگی ها

        // مثلا اینجا یک جنگ بین کاراکتر گرالت و جوعل رخ می دهد:
        cout << "  *                                                       *\n";
        cout << " ***                                                     ***\n";
        cout << "***** war between Geralt character and Jooel character: *****\n";
        cout << " ***                                                     ***\n";
        cout << "  *                                                       *\n";
        Geralt->useSkill("Fighting with a sword", 15); // عددی که به همراه اسم به تابع استفاده از مهارت فرستاده می شود مقداری است که استفاده از این مهارت از قدرت کاراکتر کم می کند!
        Jooel->useSkill("Fighting with cold weapons", 15);
        Jooel->useSkill("High fighting skills", 25);

        // مثلا اینجا یک جنگ بین کاراکتر گرالت و آرتور مورگان رخ می دهد:
        cout << "  *                                                               *\n";
        cout << " ***                                                             ***\n";
        cout << "***** war between Geralt character and Arthur Morgan character: *****\n";
        cout << " ***                                                             ***\n";
        cout << "  *                                                               *\n";
        Geralt->useSkill("Fighting with a sword", 15);
        Geralt->useSkill("Magic", 50);
        ArthurMargon->useSkill("Fighting with a gun", 30);
        ArthurMargon->useSkill("Shooting", 12); // اینجا از مهارتی استفاده می کنیم که ارتور مورگان آن مهارت را ندارد و میبینیم که ارور چاپ می شود!

        // مثلا اینجا یک جنگ بین کاراکتر جوعل و آرتور مورگان رخ می دهد:
        cout << "  *                                                               *\n";
        cout << " ***                                                             ***\n";
        cout << "***** war between Jooel character and Arthur Morgan character:  *****\n";
        cout << " ***                                                             ***\n";
        cout << "  *                                                               *\n";
        Jooel->useSkill("Killing zombies", 40);
        Jooel->useSkill("Fighting with cold weapons", 15);
        ArthurMargon->useSkill("Fighting with a gun", 30);

        games.printAllCharacters(); // اینجاهم یک بار دیگر تمام شخصیت ها با ویزگی هاشون رو چاپ می کنیم و میبنیم که قدرت آنها کم شده
        
        delete Geralt;
        delete ArthurMargon;
        delete Jooel;

        Character *Sehiro = new Character("Sehiro", "95", "10fati"); //مثلا الان اینجا چون قدرت رو عدد ندادیم ارورشو چاپ می کنه و بقیه برنامه اجرا نمیشه، برای سلامتی و لول مهارت هم این ویژگی بررسی میشه

        Character *Harry = new Character("Harry", "100", "100");
        Harry->addSkill("Magic", "-12");//مثلا الان اینجا هم چون سطح مهارت منفی داده شده ارور میده
        
        // چون اینجا خطا میده و ترو پرت می کنه دیگه بقیش اجرا نمیشه، اگه میخوایین خطای هرکدوم و ببینین اونو بیارین اول تا اجرا شه!
        
        Character *Dumbledor = new Character("Dumbledor", "-100", "100");//مثلا اینجا چون سلامتی منفی داده شده ارور میده
        Character *Hermaine = new Character("Hermaine", "90", "-80");//مثلا اینجاهم چون قدرت منفی داده شده خطا میده!
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    
    return 0;
}