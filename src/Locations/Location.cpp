#include <iostream>
#include "Location.h" 

Location::Location(std::string n, std::string d) :
name(std::move(n)), description(std::move(d)) {}

void Location::describe() const {
    std::cout << name << ": " 
              << description << std::endl;
}