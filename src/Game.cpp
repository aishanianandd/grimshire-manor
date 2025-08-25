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
    std::cout << std::endl;
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
    while (true) {
        std::cout << "Who would you like to talk to?\n"
                     "(a) Damian's wife, Lenora Grimshire\n"
                     "(b) Damian's best friend, Jellal Vexley\n"
                     "(c) Damian's son, Alexander Grimshire\n"
                     "(d) Damian's daughter, Celeste Grimshire\n"
                     "(e) The butler, Alfred Crane\n"
                     "(f) The chef, Dante Vermillion\n"
                     "Please enter a letter a–f (or Q to quit): ";

        std::string line;
        if (!std::getline(std::cin, line)) return 'q';      // EOF/signal -> bail to menu
        if (line.empty()) { std::cout << "\n"; continue; }

        char ch = static_cast<char>(std::tolower(static_cast<unsigned char>(line[0])));
        if (ch >= 'a' && ch <= 'f') return ch;
        if (ch == 'q') return 'q';

        std::cout << "Invalid input. Please enter a letter a–f (or Q).\n\n";
    }
}

void Game::TalkToSuspect(Suspect& suspect) {
    std::cout << "Name: " << suspect.getName() << std::endl;
    std::cout << "Description: " << suspect.getDescription() << std::endl;
    std::cout << "Alibi: " << suspect.getAlibi() << std::endl; 
}
void Game::printSuspectIntroduction() {
    cout << "--------------------------------------------" << endl;
    cout << endl;
    
    std::cout << "\n--- The Police Station ---\n"
                 "You arrive at the station where the main suspects await questioning.\n"
                 "Interview anyone in any order. (Q to quit)\n\n";

    bool interviewing = true;
    while (interviewing) {
        std::cout << "Who would you like to interview?\n"
                     "A) Lenora Grimshire (Wife)\n"
                     "B) Jellal Vexley (Best Friend)\n"
                     "C) Alexander Grimshire (Son)\n"
                     "D) Celeste Grimshire (Daughter)\n"
                     "E) Alfred Crane (Butler)\n"
                     "F) Dante Vermillion (Chef)\n"
                     "Q) Quit questioning\n"
                     "Enter your choice: ";

        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) { std::cout << "\n"; continue; }
        char choice = std::tolower(line[0]);
        std::cout << "\n";

        switch (choice) {
            case 'a':
                cout << "[Lenora Grimshire]\n"
                        "\"After I’d greeted everyone and made my rounds in the ballroom, "
                        "I began to feel a bit lightheaded… too much champagne, perhaps. "
                        "Around 1:30, I excused myself and went upstairs to my boudoir. "
                        "I poured myself a glass of wine and settled in with my book — "
                        "the music from the ballroom was still faintly drifting up the stairs. "
                        "I must have dozed off sometime near 2:45. The next thing I remember "
                        "was waking to shouting in the hall… it was all so sudden and dreadful.\"\n\n";
                break;

            case 'b':
                cout << "[Jellal Vexley]\n"
                        "\"Ah yes, I was in the library lounge most of the night. "
                        "We had a lively crowd at first, but by about 2:15 they’d wandered off to the ballroom. "
                        "I stayed behind, poured myself another brandy, and settled by the fire to review some papers. "
                        "Alfred popped in around 2:40 with a fresh stack of stationery. "
                        "Truth be told, I was glad for the quiet. Sometimes I think Damian forgets who his friends are. "
                        "Still, I didn’t move from that chair until I heard the commotion.\"\n\n";
                break;

            case 'c':
                cout << "[Alexander Grimshire]\n"
                        "\"Just before two o’clock, I stepped out of the ballroom — a confidential business call couldn’t wait. "
                        "I took it in the upstairs office where it was quieter. Damian’s name came up more than once, "
                        "and certain investors are still furious about his handling of a deal. "
                        "The call went on right up until three o’clock. I’d barely hung up when I heard glass shattering, "
                        "voices shouting. I left the office straightaway and found the whole place in chaos.\"\n\n";
                break;

            case 'd':
                cout << "[Celeste Grimshire]\n"
                        "\"The ballroom? Please… you know I can only take so much of those tedious society types. "
                        "I slipped into the kitchen not long after dinner and found Dante there. "
                        "We ended up talking about a new pastry recipe he’s been working on. "
                        "We chatted, sipped some tea… I think I left a little before three to fetch my shawl. "
                        "I’d barely gotten back to my room when I heard the shouting. It was all such a blur after that.\"\n\n";
                break;

            case 'e':
                cout << "[Alfred Crane]\n"
                        "\"I was on my feet all evening, as you’d expect — making rounds between the dining room and ballroom. "
                        "Around 12:00 I began polishing the silver in the dining room. "
                        "By the time the clock was nearing 3:00, I’d moved on to arranging flowers in the foyer. "
                        "That’s when I heard it — the crash, the shouting. I went straight to see what had happened.\"\n\n";
                break;

            case 'f':
                cout << "[Dante Vermillion]\n"
                        "\"I was in the kitchen most of the night. Celeste joined me for a bit; we shared tea and talked recipes. "
                        "She left a little before 3:00, and I stayed behind to tidy up. "
                        "I put away the silver, wiped the counters, made sure everything was ready for breakfast. "
                        "I didn’t step out until just before the shouting started.\"\n\n";
                break;

            case 'q':
                cout << "You wrap up the questioning for now.\n\n";
                cout << endl;
                cout << "--------------------------------------------" << endl;
                interviewing = false;
                break;

            default:
                cout << "Invalid choice. Please pick A–F or Q.\n\n";
                break;
        }
    }
}
