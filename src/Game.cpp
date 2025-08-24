#include <iostream>
#include "Game.h"

bool Game::move(const std::string& choice) {  // to move from location to location
    if (choice == "f") {
        currentLocation_ = new Foyer();
    } else if (choice == "b") {
        currentLocation_ = new Bedroom();
    } else if (choice == "k") {
        currentLocation_ = new Kitchen();
    } else if (choice == "o") {
        currentLocation_ = new Office();
    } else if (choice == "l") {
        currentLocation_ = new Library();
    } else {
        std::cout << "Invalid option. Try again.\n";
        return false;  // check if move is false for invalid input
    }
    currentLocation_->describe(); // call the location’s own describe()
    return true;
}
 // in game() if currentlocation = __ give those specific clues and npcs