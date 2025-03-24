#include "Character.hpp"
#include <iostream>
using namespace std;

Character::Character(const std::string &name, string health, string power)
{
    this->name = name;
    set_health(health);
    set_power(power);
}

string Character::get_name() const { return name; }
string Character::get_health() const { return health; }
string Character::get_power() const { return power; }

void Character::set_health(string &health)
{
    if (!is_number(health)) // چک کردن اینکه عدد باشه و اگر عدد نبود ارور چاپ کنه
    {
        throw invalid_argument(" Health should be a number!!!.\n");
    }
    if (stoi(health) < 0) // اگر عدد و منفی بود باز ارور چاپ می کنه
    {
        throw invalid_argument(" Health cannot be negative or empty!!!.\n");
    }
    this->health = health;
}

void Character::set_power(string &power)
{
    if (!is_number(power))// چک کردن اینکه عدد باشه و اگر عدد نبود ارور چاپ کنه
    {
        throw invalid_argument(" Power should be a number!!!.\n");
    }
    if (stoi(power) < 0)// اگر عدد و منفی بود باز ارور چاپ می کنه
    {
        throw invalid_argument(" Power cannot be negative.\n");
    }
    this->power = power;
}

void Character::set_skilllevel(string &skilllevel)
{
    if (!is_number(skilllevel))// چک کردن اینکه عدد باشه و اگر عدد نبود ارور چاپ کنه
    {
        throw invalid_argument(" SkillLevel should be a number!!!.\n");
    }
    if (stoi(skilllevel) < 0)// اگر عدد و منفی بود باز ارور چاپ می کنه
    {
        throw invalid_argument(" Skilllevel cannot be negative.\n");
    }
}

void Character::addSkill(const std::string &skillName, string skillLevel)
{
    set_skilllevel(skillLevel);
    skills[skillName] = skillLevel;
}

void Character::useSkill(const std::string &skillName, int poweruse)
{
    auto it = skills.find(skillName);
    if (it != skills.end()) // چک کردن اینکه مهارتی داشته باشد و آن مهارت پیدا شود
    {
        if (stoi(power) >= poweruse) // اگر قدرت کافی برای اجرای آن مهارت را داشت
        {
            cout << name << " used " << skillName << " (Level " << it->second << ")" << endl;
            power = to_string(stoi(power) - poweruse);
            cout << name << " The use of " << skillName << "skill reduced the power of " << poweruse << " units of power !\n";
            cout << "------------------------------------------\n";
        }
        else // اگر قدرت کافی برای اجرای اون برنامه رو نداشته باشه ارور چاپ میشه
        {
            cout << name << " Not enough mana to use " << skillName << "!" << endl;
            cout << "------------------------------------------\n";
        }
    }
    else // اگر مهارت با آن اسم پیدا نشود ارور چاپ می شود
    {
        cout << "Skill " << skillName << " not found for " << name << "!" << endl;
        cout << "--------------------------------------------\n";
    }
}

void Character::print() const // چاپ همه کاراکتر ها با تمام ویژگی ها
{
    cout << "Character: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Power: " << power << endl;
    cout << "Skills:" << endl;
    for (const auto &skill : skills)
    {
        cout << " - " << skill.first << " (Level " << skill.second << ")" << endl;
    }
}

bool Character::is_number(string &str)
{ // چک می کنه رشته ای که وارد میشه عدد باشه
    for (char const &c : str)
    {
        if (!isdigit(c) && c != '.' && c != '-')
            return false;
    }
    return true;
}