#include <iostream>
#include "Game.h"
#include "Suspect.h"
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

bool Game::move(const std::string& choice) {
    // Free the old room
    delete currentLocation_;
    currentLocation_ = nullptr;

    if (choice == "a") {
        currentLocation_ = new Foyer();
    } else if (choice == "b") {
        currentLocation_ = new Bedroom();
    } else if (choice == "c") {
        currentLocation_ = new Kitchen();
    } else if (choice == "d") {
        currentLocation_ = new Office();
    } else if (choice == "e") {
        currentLocation_ = new Library();
    } else {
        std::cout << "Invalid option. Try again.\n";
        return false;
    }

    // Show room description
    currentLocation_->describe();

    // Show room options (this prints a), b), etc.)
    currentLocation_->showOptions();

    // Example: read player choice inside this loop
    char c;
    std::cin >> c;

    int idx = c - 'a';
    if (idx >= 0 && idx < (int)currentLocation_->options.size()) {
        std::cout << "You chose: " << currentLocation_->options[idx] << "\n";
    } else if (c == 'x') {
        std::cout << "Leaving the " << currentLocation_->name << ".\n";
    } else {
        std::cout << "Invalid choice.\n";
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

void Game::visit(Location& room) {
    room.describe();

    while (true) {
        room.showOptions();              // prints a), b), ..., x) back, then "> "
        char c;
        std::cin >> c;

        if (c == 'x') break;             // leave the room

        int idx = c - 'a';               // map 'a' -> 0, 'b' -> 1, ...
        if (idx < 0 || idx >= (int)room.options.size()) {
            std::cout << "Invalid choice.\n";
            continue;
        }

        // For now: generic feedback. You can replace with per-room logic below.
        std::cout << "You chose: " << room.options[idx] << "\n";

        // --- optional: per-room outcomes ---
        if (room.name == "Foyer") {
            if (idx == 0) std::cout << "You find tiny shards near the steps.\n";
            if (idx == 1) std::cout << "The latch is set from the inside.\n";
            if (idx == 2) std::cout << "Faint scuff marks lead toward the hall.\n";
        } else if (room.name == "Library") {
            if (idx == 0) std::cout << "Crumbled note in ash: \"give me what I want... -A.C.\"\n";
            if (idx == 1) std::cout << "Bank notice: Alexander’s account is nearly empty.\n";
        } else if (room.name == "Kitchen") {
            if (idx == 0) std::cout << "Pantry: rat poison bottle is missing.\n";
            if (idx == 1) std::cout << "Letter from Damian to Dante: \"Stay away from my daughter.\"\n";
            if (idx == 2) std::cout << "Servant: \"Celeste helped with drinks; bitter smell lingered.\"\n";
        } else if (room.name == "Office") {
            if (idx == 0) std::cout << "Drawer: photo of Damian and Mrs. Vexley.\n";
            if (idx == 1) std::cout << "Sticky note: \"Call Marcus re: Celeste’s arranged marriage.\"\n";
            if (idx == 2) std::cout << "Chair: a lock of dark brown hair.\n";
            if (idx == 3) std::cout << "Maid: heard glass tapping; bitter, metallic smell.\n";
        } else if (room.name == "Bedroom") {
            if (idx == 0) std::cout << "Staircase: heavy, uneven steps scuffed the runner.\n";
            if (idx == 1) std::cout << "NPC: \"He looked pale, unsteady—clutching the wall.\"\n";
        }
        // -----------------------------------

        std::cout << "\n";
    }
}

char Game::TalkOptions() {  
    char input;

    std::cout << "Who would you like to talk to?" << std::endl;

    do {
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

void Game::TalkToSuspect(Suspect& suspect) {
    std::cout << "Name: " << suspect.getName() << std::endl;
    std::cout << "Description: " << suspect.getDescription() << std::endl;
    std::cout << "Alibi: " << suspect.getAlibi() << std::endl; 
}