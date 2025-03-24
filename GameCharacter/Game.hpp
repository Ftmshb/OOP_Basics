#ifndef GAME_HPP
#define GAME_HPP
#include "Character.hpp"
#include <iostream>
#include <vector>

class Game{

    private:
    std::vector<const Character*> characters;

    public:
    void addCharacter(const Character* character);
    void printAllCharacters() const;
};

#endif