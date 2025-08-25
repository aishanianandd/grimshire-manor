#include <iostream>
#include "Location.h" 

Location::Location(std::string n, std::string d) :
name(std::move(n)), description(std::move(d)) {}

void Location::describe() const {
    std::cout << "[" << name << "]\n" << description << "\n";
}

void Location::addOption(const std::string& option) {
    options.push_back(option);
}

void Location::showOptions() const {
    char key = 'a';
    for (const auto& opt : options) {
        std::cout << key++ << ") " << opt << "\n";
    }
    std::cout << "x) back\n> ";
}