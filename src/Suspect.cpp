#include "Suspect.h"
#include <string>
#include <iostream>

Suspect::Suspect(std::string n, std::string d, std::string a) 
    : name(n), description(d), alibi(a) {}

std::string Suspect::getName() const {
    return name;
}

std::string Suspect::getDescription() const {
    return description;
}

std::string Suspect::getAlibi() const {
    return alibi;
}