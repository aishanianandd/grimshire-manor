#include <iostream>
#include "Game.h"
#include "Suspect.h"
#include "Type.h"


void Game::printIntroduction() {
    const char* MANSION = "\033[38;2;255;0;0m"
     R"MANSION( 
      `'::::.
        _____A_
       /      /\
    __/__/\__/  \___
---/__|" '' "| /___/\----
   |''|"'||'"| |' '||
   `""`""))""`"`""""`
)MANSION"
"\033[0m";

    type(MANSION, 2);
    std::cout << std::endl;
    // printing the introduction
    type("\033[3mAh yes… the Grimshires.\n");
    type("The most prestigious family in the nation—wealthy, influential, admired by all.\n");
    type("Their manor once stood as a beacon of wealth and luxury.\n\n");

    type("But now, tragedy has struck.\n");
    type("Damian Grimshire, the head of the family, was found dead yesterday evening.\n\n");

    type("You have been chosen as the lead detective in this case.\n");
    type("The lives, the lies, the legacy of the Grimshires now rest in your hands.\n\n");

    type("Tell me, detective… are you ready to face what awaits in the dark?\033[0m\n\n");


    std::cout << "\033[38;2;255;0;0m";
    std::cout << "|═════════════════════⊹⊱≼≽⊰⊹═════════════════════|\n";
    std::cout << endl;
    std::cout << "            THE GRIMSHIRE MANOR MURDER            \n";
    std::cout << endl;
    std::cout << "|═════════════════════⊹⊱≼≽⊰⊹═════════════════════|\n";
    std::cout << "\033[0m";  // reset
    std::cout << std::endl;




}

// user's name
void Game::setName(const string& n){
    name = n;
}

// retrieves user name
string Game::getName(){
    return name;
}

// destructor added to free dynamically allocated memory 
Game::~Game() {
    delete currentLocation_;
    currentLocation_ = nullptr;
}


bool Game::move(const std::string& choice) {
    // Free the old room
    delete currentLocation_;
    currentLocation_ = nullptr;

    if (choice == "a") {
        cout << R"(      
               -     -                  |          -
   -           -     -    .      .      |    -     -     -
         -     -     -    |      .      |    -     -     -
   -     -     -     -    |      :      |    -     -     -
   -     -     -     -   .|     _|_     |.         -     -
   -     -     -       ._-|             |-_.       -     -
   -     -     -     ._-  |             |  -_.     -     -
-.--.--.--.--.--. _ _-_ _ |             | _ _-_ _ .--.--.--.--.--.-
 |  |  |  |  |  |`.| | | ||   _______   || | | |.'|  |  |  |  |  |
8888888888888888L_|`.88888|  |   |   |  |88888.'|_J8888888888888888
       |:     `888L_|`.|  |  |   |   |  | :|.'|_J888'    :|
       |:       `888L_|`. |  |   |   |: | .'|_J888'      :|
       |:        |`888L_|`.  |   |   |  .'|_J888'        :|
_______<:________|:_`888L_|) |   |   | (|_J888':|________:|________
       |:        |:   `888L. |___|___| .J888'  :|        :|
       |:        |:     `88|/_________\|88'    :|        :|
 __..--       _.-'        ,|L_________J|.      `-._      ``--..__
'         _.-'            |/___________\|          `-._          ``
                        .c|L___________J|c.            `-.
                      .' |/_____________\| `.
                    .'|  |L_____________J|  |`.
                  .'  | _/               \_ |  `.
                .'|   _//     Damian's    \\_   |`.
              .'  | _///        Body       \\\_ |  `.
          _______________________________________________
        .'                                               `.
      .'                                                   `.
    .'                                                       `.
)" << endl;

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
    // currentLocation_->showOptions();
    currentLocation_->interact();

    // show menu options after selecting a location
    currentLocation_->showLocationOptions();

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

char Game::TalkOptions() {
    while (true) {
        std::cout << "Who would you like to talk to?\n\n"
                     "(a) Damian's wife, Lenora Grimshire\n"
                     "(b) Damian's best friend, Jellal Vexley\n"
                     "(c) Damian's son, Alexander Grimshire\n"
                     "(d) Damian's daughter, Celeste Grimshire\n"
                     "(e) The butler, Alfred Crane\n"
                     "(f) The chef, Dante Vermillion\n\n"
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
    std::cout << "\nName: " << suspect.getName() << std::endl;
    std::cout << "\nDescription: " << suspect.getDescription() << std::endl; 
    std::cout << "\nAlibi: " << suspect.getAlibi() << std::endl; 
}
void Game::printSuspectIntroduction() {
    std::cout << "-----------------------------------" << endl;
    
    static constexpr const char* POLICE = R"POLICE(
                 ,
        __  _.-"` `'-.
       /||\'._ __{}_(
       ||||  |'--.__\
       |  L.(   ^_\^
       \ .-' |   _ |
       | |   )\___/
       |  \-'`:._]
       \__/;      '-.

━━━━━━━━━━━━━━━⊱⋆⊰━━━━━━━━━━━━━━━
       The Police Station 
━━━━━━━━━━━━━━━⊱⋆⊰━━━━━━━━━━━━━━━

You arrive at the station where the main suspects await questioning.
Interview anyone in any order. (Q to quit)

)POLICE";

    std::cout << POLICE << '\n';

    bool interviewing = true;
    while (interviewing) {
        std::cout << "Who would you like to interview?\n\n"
                     "A) Lenora Grimshire (Wife)\n"
                     "B) Jellal Vexley (Best Friend)\n"
                     "C) Alexander Grimshire (Son)\n"
                     "D) Celeste Grimshire (Daughter)\n"
                     "E) Alfred Crane (Butler)\n"
                     "F) Dante Vermillion (Chef)\n"
                     "Q) Quit questioning\n"
                     << endl <<
                     "Enter your choice: ";

        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) { std::cout << "\n"; continue; }
        char choice = std::tolower(line[0]);
        std::cout << "\n";

        switch (choice) {
            // lenora grimshire interview
            case 'a':
                std::cout << "\n=========================================\n\n";

                std::cout << "\033[1mSuspect:\033[0m Lenora Grimshire\n\n";

                // appearance
                type("\033[1mAppearance:\033[0m \033[3mAn elegant woman in her early 50s. She has smooth chestnut-brown hair\n"
                    "\t    pinned up neatly with sparkling diamond clips. \n"
                    "\t    Her blue silk gown matches her sharp green eyes, and she wears long satin gloves.\n"
                    "\t    She moves gracefully, always with perfect posture.\033[0m\n\n", 15);

                std::cout << "\033[1;36m"
                        << "=============== INTERVIEW ==============="
                        << "\033[0m\n\n";

                type("\033[1;34mDetective:\033[0m \033[3mMrs. Grimshire, where were you last night?\033[0m\n\n", 15);

                type("\033[1mLenora:\033[0m \033[3mAfter I’d greeted everyone and made my rounds in the ballroom,\n"
                    "\tI began to feel a bit lightheaded… too much champagne, perhaps. \n"
                    "\tAround 1:30, I excused myself and went upstairs to my boudoir. \n"
                    "\tI poured myself a glass of wine and settled in with my book..\n"
                    "\tthe music from the ballroom was still faintly drifting up the stairs. \n"
                    "\tI must have dozed off sometime near 2:45. \n"
                    "\tThe next thing I remember was waking to shouting in the hall… \n"
                    "\tit was all so sudden and dreadful.\033[0m\n\n", 15);

                type("\033[1;34mDetective:\033[0m \033[3mDid you and Damian argue that night?\033[0m\n\n", 15);

                type("\033[1mLenora:\033[0m \033[3mYes… but only briefly, about his… behavior. \n"
                    "\tStill, I would never harm him. He had many enemies, Detective.\033[0m\n\n", 15);

                std::cout << "\033[1;31m"   // bold red
                    << "============= INTERVIEW END ============="
                    << "\033[0m\n\n";

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

bool Game::accuseSuspect(){

    // ----------------- Accuse Suspect -----------------
    std::cout << "\n\033[1;38;2;147;112;219m=== Make Your Accusation ===\033[0m\n\n";
    std::cout << "Who do you accuse of murdering Damian Grimshire?\n\n";
    std::cout << "A) Lenora Grimshire (Wife)\n";
    std::cout << "B) Jellal Vexley (Best Friend)\n";
    std::cout << "C) Alexander Grimshire (Son)\n";
    std::cout << "D) Celeste Grimshire (Daughter)\n";
    std::cout << "E) Alfred Crane (Butler)\n";
    std::cout << "F) Dante Vermillion (Chef)\n";
    std::cout << "Q) Cancel accusation\n\n";

    std::cout << "Enter your choice: ";
    std::string acc; std::getline(std::cin, acc);
    if (!acc.empty()) acc = std::string(1, std::tolower(acc[0]));

    std::string accused;
    switch (!acc.empty() ? acc[0] : '\0') {
        case 'a': accused = "Lenora Grimshire"; break;
        case 'b': accused = "Jellal Vexley";     break;
        case 'c': accused = "Alexander Grimshire"; break;
        case 'd': accused = "Celeste Grimshire"; break;
        case 'e': accused = "Alfred Crane";      break;
        case 'f': accused = "Dante Vermillion";  break;
        case 'q': std::cout << "You holster your accusation… for now.\n"; return false;
        default:  std::cout << "Invalid choice. Accusation cancelled.\n";  return false;
    }

    std::cout << "\n\033[1mYou are accusing:\033[0m " << accused << "\n";
    std::cout << "Are you sure? (y/n): ";
    std::string yn; std::getline(std::cin, yn);
    cout << endl;
    if (!yn.empty()) yn = std::string(1, std::tolower(yn[0]));
    if (yn != "y") { std::cout << "You decide to gather more evidence first.\n"; return false; }

    // Decide win/lose
    if (accused == TRUE_KILLER) {
        std::cout << "\033[1;32mYour accusation rings true. Justice is served.\033[0m\n";
        return true;   // end game (success)
    } else {
        std::cout << "\033[1;31mYour accusation fails. The killer smiles.\033[0m\n";
        return true;   // end game (failure)
    }
}