#include <iostream>
#include "Game.h"
#include "Type.h"


void Game::printIntroduction() {
    const char* MANSION = R"MANSION(
      `'::::.
        _____A_
       /      /\
    __/__/\__/  \___
---/__|" '' "| /___/\----
   |''|"'||'"| |' '||
   `""`""))""`"`""""`
)MANSION";

    type(MANSION, 2);
    cout << endl;
    // printing the introduction
    type("Ah yes… the Grimshires.\n");
    type("The most prestigious family in the nation—wealthy, influential, adored by high society.\n");
    type("Their manor stood as a beacon of elegance, a place where laughter and luxury seemed endless.\n\n");

    type("But behind the crystal chandeliers and polished marble floors,\n");
    type("not everything was as perfect as it appeared.\n");
    type("Whispers of betrayal… shadows of resentment… unspoken grudges buried deep.\n\n");

    type("And tonight, those whispers would finally turn into something far darker.\n\n");

    type("Now the manor trembles with unease.\n");
    type("Every smile feels rehearsed. Every alibi feels fragile.\n");
    type("The truth hides among liars… and only one person can uncover it.\n\n");

    type("You have been chosen as the lead detective in this case.\n");
    type("The lives, the lies, the legacy of the Grimshires now rest in your hands.\n\n");

    type("Tell me, detective—are you ready to face what waits in the dark?\n\n");

    // auraful title box
    type("|=================================================|\n", 2);
    type("|            THE GRIMSHIRE MANOR MURDER           |\n", 2);
    type("|=================================================|\n\n", 2);
}

bool Game::move(const std::string& choice) {  // to move from location to location
    if (choice == "f") {
        delete currentLocation_; // ...frees memory of the old room??
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

    // Add room-specific clues
    if (currentLocation_->name == "Library") {
        Clue libraryClue("Torn Page", 
                         "A page ripped from a ledger, edges singed.", 
                         "Library");
        addClue(libraryClue);
    }
    else if (currentLocation_->name == "Kitchen") {
        Clue kitchenClue("Locked Pantry Key", 
                         "A small brass key lies hidden under a pot.", 
                         "Kitchen");
        addClue(kitchenClue);
    }
    else if (currentLocation_->name == "Bedroom") {
        Clue bedroomClue("Bookmark", 
                         "A bookmark left on page 2 of a novel.", 
                         "Bedroom");
        addClue(bedroomClue);
    }
    else if (currentLocation_->name == "Foyer") {
        Clue foyerClue("Broken Glass", 
                       "Shards of glass near the stairs, possibly from a struggle.", 
                       "Foyer");
        addClue(foyerClue);
    }
    else if (currentLocation_->name == "Office") {
        Clue officeClue("Chemical Residue", 
                        "A faint chemical smell lingers on the desk.", 
                        "Office");
        addClue(officeClue);
    }
    return true;
}
 // in game() if currentlocation = __ give those specific clues and npcs


// clues #5 
 void Game::addClue(const Clue& c) {
    for (const auto& clue : clues) {
        if (clue.getName() == c.getName()) return; // already found
    }
    clues.push_back(c);
    std::cout << "You discovered a clue: " << c.getName() << "!\n";
}

void Game::reviewClues() const {
    std::cout << "\n=== Clues Discovered ===\n";
    if (clues.empty()) std::cout << "No clues found yet.\n";
    else {
        for (const auto& c : clues) c.printClue();
    }
    std::cout << "=======================\n";
}

// add a new statement #12
void Game::addStatement(const std::string& s) {
    // Avoid duplicate statements
    for (const auto& stmt : heardStatements) {
        if (stmt == s) return; // already heard
    }
    heardStatements.push_back(s);
    std::cout << "You recorded a statement: \"" << s << "\"\n";
}

// Review all statements
void Game::reviewStatements() const {
    std::cout << "\n=== Statements Heard ===\n";
    if (heardStatements.empty()) {
        std::cout << "You haven't talked to anyone yet.\n";
    } else {
        for (const auto& s : heardStatements) {
            std::cout << "- " << s << std::endl;
        }
    }
    std::cout << "========================\n";
} // these work like clues but store npc dialogue 


void Game::initSuspects() {
    suspects.clear(); // just in case

    suspects.push_back(Character("Lenora", "I was in the ballroom all night."));
    suspects.push_back(Character("Alexander", "I was in the library reading."));
    suspects.push_back(Character("Celeste", "I was cooking in the kitchen."));
    suspects.push_back(Character("Alfred", "I was cleaning the foyer."));
    suspects.push_back(Character("Dante", "I was walking in the garden."));
    suspects.push_back(Character("Jellal", "I was reading in my bedroom."));
}

void Game::talkToNPC(const string& npcName) { 
    bool found = false;
    for (const auto& npc : suspects) {
        if (npc.getName() == npcName) {
            addStatement(npc.getName() + ": " + npc.getAlibi());
            cout << npc.getName() << " says: \"" << npc.getAlibi() << "\"\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "That person is not available to talk.\n";
}
