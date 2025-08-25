#include "Character.h"
#include <iostream>

Character::Character(const std::string& n, const std::string& a) : name(n), alibi(a) {}

void Character::printInfo() {
    std::cout << name << ": " << alibi << "\n";
}

std::string Character::getName() const { return name; }
std::string Character::getAlibi() const { return alibi; }
