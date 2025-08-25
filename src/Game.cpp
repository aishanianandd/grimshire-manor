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


void Game::initSuspects() {
    //create Suspect objects

    Suspect Lenora(
        "Lenora Grimshire",
        "is an elegant woman in her early 50s. She has smooth chestnut-brown hair pinned up neatly with sparkling diamond clips. Her blue silk gown matches her sharp green eyes, and she wears long satin gloves. She moves gracefully, always with perfect posture.",
        "After I’d greeted everyone and made my rounds in the ballroom, I began to feel a bit lightheaded… too much champagne, perhaps. Around 1:30, I excused myself and went upstairs to my boudoir. I poured myself a glass of wine and settled in with my book — the music from the ballroom was still faintly drifting up the stairs. I must have dozed off sometime near 2:45. The next thing I remember was waking to shouting in the hall… it was all so sudden and dreadful."
        "I bet it was Damian's best friend. He was even more upset than I was about what happened between my husband and his wife."
    );

    Suspect Jellal(
        "Jellal Vexley",
        "is a charming man in his mid-40s with tanned skin, dark eyes, and black hair streaked with blue highlights. He wears a maroon tuxedo with shiny gold cufflinks. His smile is warm, but his eyes look like he’s always calculating something.",
        "Ah yes, I was in the library lounge most of the night. You know me — once I start telling my travel stories, people tend to linger. We had quite a lively crowd at first, but by about 2:15  they’d all wandered off to the ballroom for a dance. I stayed behind, poured myself another brandy, and settled by the fire to review some business papers I’d brought along. Alfred popped in around 2:40 with a fresh stack of stationery for me — very attentive fellow. Truth be told, I was glad for the quiet… Damian had been particularly charming with the ladies tonight, as he tends to be. Sometimes I think he forgets who his friends are. Still, I didn’t move from that chair until I heard the commotion."
        "I would focus your search onto that butler, I know that had some gripes with him."
    );

    Suspect Alexander (
        "Alexander Grimshire",
        "is a tall, broad-shouldered 28-year-old with dark brown hair neatly styled. He wears a navy suit with a crisp white shirt and a matching tie, though it’s slightly loosened as if he’s restless. He often scans the room like he’s thinking two steps ahead.",
        "Just before two o’clock, I stepped out of the ballroom — there was a confidential business matter that couldn’t wait. I took the call in the upstairs office where it was quieter. The conversation… well, it was delicate, and I needed privacy. Damian’s name came up more than once — certain investors are still furious about the way he handled a recent deal, and I was left cleaning up his mess. I can’t say I wasn’t frustrated; he’s cost me opportunities before. As far as I recall, the call went on right up until three o’clock. I’d barely hung up when I heard the crash — glass shattering, voices shouting. I left the office straightaway and found the whole place in chaos."
        "I know that my father was upset with our chef. He was having a secret relationship with my sister, and my father did not approve of it."
    );

    Suspect Celeste (
        "Celeste Grimshire",
        "is a beautiful 22-year-old with wavy brown hair over one shoulder. She has pale skin, bright green eyes, and wears a light blue silk dress with a high slit. She laughs easily, but her eyes hint at stubbornness and rebellion.",
        "The ballroom? Please… you know I can only take so much of those tedious society types. I slipped into the kitchen not long after dinner and found Dante there — we ended up talking about a new pastry recipe he’s been working on. It was far more interesting than watching half-drunk men stumble through a waltz. We just chatted, sipped some tea… oh, I think I left the kitchen a little before three to fetch my shawl. I’d barely gotten back to my room when I heard the shouting. It was all such a blur after that."
        "I hope no one says me. Sure, I was upset at my father for forcing me to marry that dumbwitted chump, but I would never lay a finger on him."
    );

    Suspect Alfred (
        "Alfred Crane",
        "is a neat and serious man in his late 60s with silver hair and sharp grey eyes. He wears a perfect black butler’s uniform with polished brass buttons and a gold watch chain. He moves quietly and with purpose.",
        "I was on my feet all evening, as you’d expect — making the rounds between the dining room and ballroom, keeping glasses topped up and seeing to the guests’ coats. Around 12:00, once things had settled into their rhythm, I began polishing the silver in the dining room between service rounds. By the time the clock was nearing 3:00, I’d moved on to arranging flowers in the foyer for the morning. That’s when I heard it — the crash, the shouting. I went straight to see what had happened."
        "Damian was always getting into it with that son of his...and you know, I always though Alexander was such a selfish young man for trying to get all of Damian's inheritance. I never heard if he did."
    );

    Suspect Dante (
        "Dante Vermillion",
        "is an Italian man in his early 30s with olive-toned skin, brown eyes, and dark hair swept back. He wears spotless white chef’s clothes and a small silver necklace with a van cleef charm. His hands are strong and a little scarred from years of cooking.",
        "I was in the kitchen for most of the night — plenty to do after the gala supper. Celeste joined me for a bit; we shared tea and talked about some new recipes I’d been working on. She left a little before 3:00, and I stayed behind to finish tidying up. I put away the silver, wiped the counters, made sure everything was ready for breakfast. I didn’t step out until I went to my quarters, just before the shouting started."
        "The other night, Damian's wife found out that he had been cheating on her. I was still at the house, cleaning up from dinner, and boy she was angry."
    );
}

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
                cout << "[Lenora Grimshire]:\n\n"
                        "\"After I’d greeted everyone and made my rounds in the ballroom, "
                        "I began to feel a bit lightheaded… too much champagne, perhaps. "
                        "Around 1:30, I excused myself and went upstairs to my boudoir. "
                        "I poured myself a glass of wine and settled in with my book — "
                        "the music from the ballroom was still faintly drifting up the stairs. "
                        "I must have dozed off sometime near 2:45. The next thing I remember "
                        "was waking to shouting in the hall… it was all so sudden and dreadful.\"\n\n";
                break;

            case 'b':
                cout << "[Jellal Vexley]:\n\n"
                        "\"Ah yes, I was in the library lounge most of the night. "
                        "We had a lively crowd at first, but by about 2:15 they’d wandered off to the ballroom. "
                        "I stayed behind, poured myself another brandy, and settled by the fire to review some papers. "
                        "Alfred popped in around 2:40 with a fresh stack of stationery. "
                        "Truth be told, I was glad for the quiet. Sometimes I think Damian forgets who his friends are. "
                        "Still, I didn’t move from that chair until I heard the commotion.\"\n\n";
                break;

            case 'c':
                cout << "[Alexander Grimshire]:\n\n"
                        "\"Just before two o’clock, I stepped out of the ballroom — a confidential business call couldn’t wait. "
                        "I took it in the upstairs office where it was quieter. Damian’s name came up more than once, "
                        "and certain investors are still furious about his handling of a deal. "
                        "The call went on right up until three o’clock. I’d barely hung up when I heard glass shattering, "
                        "voices shouting. I left the office straightaway and found the whole place in chaos.\"\n\n";
                break;

            case 'd':
                cout << "[Celeste Grimshire]:\n\n"
                        "\"The ballroom? Please… you know I can only take so much of those tedious society types. "
                        "I slipped into the kitchen not long after dinner and found Dante there. "
                        "We ended up talking about a new pastry recipe he’s been working on. "
                        "We chatted, sipped some tea… I think I left a little before three to fetch my shawl. "
                        "I’d barely gotten back to my room when I heard the shouting. It was all such a blur after that.\"\n\n";
                break;

            case 'e':
                cout << "[Alfred Crane]:\n\n"
                        "\"I was on my feet all evening, as you’d expect — making rounds between the dining room and ballroom. "
                        "Around 12:00 I began polishing the silver in the dining room. "
                        "By the time the clock was nearing 3:00, I’d moved on to arranging flowers in the foyer. "
                        "That’s when I heard it — the crash, the shouting. I went straight to see what had happened.\"\n\n";
                break;

            case 'f':
                cout << "[Dante Vermillion]:\n\n"
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
