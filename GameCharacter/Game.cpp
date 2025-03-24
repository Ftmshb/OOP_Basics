#include "Game.hpp"
#include <iostream>
using namespace std;

void Game::addCharacter(const Character* character) {
    characters.push_back(character);
}

void Game::printAllCharacters() const {
    for (const auto& character : characters) {
        character->print();
        cout << "-------------------" << endl;
    }
}