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

void Location::showOptions() {
    char key = 'a';
    for (const auto& opt : options) {
        std::cout << key++ << ") " << opt << "\n";
    }
    std::cout << "x) back\n";

    std::string choice;
    std::cin >> choice;
    menuChoice = choice;
}

void Location::showLocationOptions() {
    if (name == "Foyer") {
        if (menuChoice == "a") {
            std::cout << "You take a closer look at the staircase... polished wood, but a scrap of light blue fabric stuck on the staircase handrail.\n";
        } else if (menuChoice == "b") {
            std::cout << "While I was coming down the stairs earlier, I overheard Mrs. "
                            "Grimshire speaking in a low voice to one of her friends near the foyer. "
                            "She said something like, ‘If he thinks he can humiliate me and get away with it, "
                            "he’s mistaken.’ I didn’t stay to listen — it sounded… personal.\n";
        } else {
            std::cout << "Nothing more to see here.\n";
        }
    }
}