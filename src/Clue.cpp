#include "Clue.h"
#include <iostream>

Clue::Clue(const std::string name, const std::string description, const std::string location)
    : name(name), description(description), location(location) {}

void Clue::printClue() const {
    std::cout << name << " (" << location << "): " << description << "\n";
}

std::string Clue::getName() const { return name; }
std::string Clue::getLocation() const { return location; }

void Clue::printCountdown() { }
bool Clue::useClue() { return true; }
