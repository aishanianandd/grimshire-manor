#include "Clue.h"
#include <iostream>

Clue::Clue(const std::string& name,
           const std::string& description,
           const std::string& location)
    : name(name), description(description), location(location) {}

// prints the clue in easy to read format for user access
void Clue::printClue() const {
    std::cout << name << " (" << location << "): " << description << '\n';
}

const std::string& Clue::getName() const noexcept {
    return name;
}

const std::string& Clue::getLocation() const noexcept {
    return location;
}

const std::string& Clue::getDescription() const noexcept {
    return description;
}

void Clue::printCountdown() {
    // TODO: implement countdown 
}

bool Clue::useClue() {
    // TODO
    return true;
}

