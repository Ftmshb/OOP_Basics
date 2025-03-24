#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include <map>

class Character{

    private:
    std::string name;
    std::string health;
    std::string power;
    std::map<std::string, std::string> skills; 

    public:
    Character(const std::string& name, std::string health, std::string power);
    std::string get_name() const;
    std::string get_health() const;
    std::string get_power() const;
    void set_health(std::string& health);
    void set_power(std::string& power);
    void set_skilllevel(std::string& skilllevel);
    void addSkill(const std::string& skillName, std::string skillLevel);
    void useSkill(const std::string& skillName, int poweruse);
    void print() const;
    bool is_number(std::string& str);
};

#endif