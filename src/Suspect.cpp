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

char Suspect::TalkOptions() {  
    char input;

    std::cout << "Who would you like to talk to?" << std::endl;

    do {
        std::cout << "(a) Damian's wife, Lenora Grimshire" << std::endl;
        std::cout << "(a) Damian's wife, Lenora Grimshire" << std::endl;
        std::cout << "(b) Damian's best friend, Jellal Vexley" << std::endl;
        std::cout << "(c) Damian's son, Alexander Grimshire" << std::endl;
        std::cout << "(d) Damian's duaghter, Celeste Grimshire" << std::endl;
        std::cout << "(e) The butler, Alfred Crane" << std::endl;
        std::cout << "(f) The chef, Dante Vermillion" << std::endl;
        std::cout << "Please enter a letter a-f" << std::endl;

        std::cin >> input;
        input = tolower(input);     //in case the player enters capital

        if (input < 'a' || input > 'f') {
            std::cout << "Invalid input. Please enter a letter a-f" << std::endl;
            std::cin >> input;
        }

    } while (input < 'a' || input > 'f');
    
    return input;
}

void TalkToSuspect(const Suspect& Suspect){
    std::cout << "Name: " << getName << std::endl;
    std::cout << "Description: " << getDescription << std::endl;
    std::cout << "Alibi: " << getAlibi << std::endl; 
}