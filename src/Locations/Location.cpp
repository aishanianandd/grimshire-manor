#include <iostream>
#include <cctype> 
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

    std::string line;
    std::getline(std::cin, line);           // always use getline

    if (line.empty()) {
        menuChoice = " ";                   // default if user just hits Enter
    } else {
        // take first character, lowercase it safely, store as 1-char string
        unsigned char uc = static_cast<unsigned char>(line[0]);
        char lower = static_cast<char>(std::tolower(uc));
        menuChoice = std::string(1, lower);
    }
}

void Location::interact() {
    while (true) {
        // print options and read input
        showOptions();

        // go back to main menu when player chooses x
        if (menuChoice == "x") break;

        // handle the choice inside this room
        showLocationOptions();
        std::cout << "\n";
    }
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
    } else if (name == "Bedroom") {
        if (menuChoice == "a") {
            std::cout << "You find that the bookmark stuck in the book is only on page 2...Hm, Lenora must be a very slow reader..." << std::endl;
        } else if (menuChoice == "b") {
            std::cout << "I was on my way to tend to my usual cleaning duties when I noticed Mr. Grimshire in the upstairs hallway. "
                            "He looked… strange — pale, unsteady on his feet, and clutching at the wall like he might fall. "
                            "I asked if he was alright, but he just waved me off without a word and kept moving toward the staircase. "
                            "Something was off though, his steps were slow… almost dragging, like he was dizzy or in pain.\n";
        } else {
            std::cout << "Nothing more to see here.\n";
        }
    } else if (name == "Kitchen") {
        if (menuChoice == "a") {
            std::cout << "The bottom shelf seems to be missing a bottle of rat poison" << std::endl;
        } else if (menuChoice == "b") {
            std::cout << "The letter is from Damian addressed to Dante the chef:" 
                " Stay away from my daughter. You will never marry her! " << std::endl;
        } else if (menuChoice == "c") {
            std::cout << "“I saw Miss Celeste helping Chef Dante with drinks. "
                " Strange, since she never does that… and there was this  bitter chemical-like smell in the air as well." << std::endl;
        } else {
            std::cout << "Nothing more to see here.\n";
        }
    } else if (name == "Office") {
        if (menuChoice == "a") {
            std::cout << "There's a photograph of Damian and Jellal's wife in an intimate pose." << std::endl;
        } else if (menuChoice == "b") {
            std::cout << "The sticky note in Damian's handwriting reads: "
                "Call Marcus regarding Celeste's arranged marriage to the Ackerman heir.\n";
        } else if (menuChoice == "c") {
            std::cout << "You notice a lock of dark brown hair caught on the back of Damian's chair.\n";
        } else if (menuChoice == "d") {
            std::cout << "I was dusting in the hall outside this office earlier, just before everything happened.\n"
                "I heard Mr. Grimshire talking quietly to someone, then the sound of glass tapping on wood.\n"
                "Then there was this strange sound… like glass tapping on wood.\n"
                "A moment later, I caught a faint, sharp smell — not wine or alcohol, but something bitter, almost metallic.\n";
        } else {
            std::cout << "Nothing more to see here.\n";
    }
    } else if (name == "Library") {
        if (menuChoice == "a") {
            std::cout << "A threatening letter is crumpled up between the firewood: "
                "give me what I want unless you want them all to find out” -A.C.\n";
        } else if (menuChoice == "b") {
            std::cout << "You find a folded bank notice with Alexander Grimshire's account completely empty and in debt." << std::endl;
            std::cout << "He must be really desperate for money right now." << std::endl;
        } else {
            std::cout << "Nothing more to see here.\n";
    }
    }
}