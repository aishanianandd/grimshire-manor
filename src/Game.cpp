#include <iostream>
#include <cctype>        // for std::tolower
#include "Game.h"
#include "Suspect.h"
#include "Type.h"

using std::cout;
using std::endl;


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
    type("Once a family of elegance and renown, their halls echoed with laughter, music, and champagne.\n\n");

    type("...but all that grandeur has been tainted.\n");
    type("Last night, tragedy struck.\n\n");
    type("Damian Grimshire, the head of the family and host of the party, was discovered lifeless at the bottom of the grand staircase.\n");  
    type("The official word? A drunken stumble, a fatal fall at precisely 3:17 AM.\n");
    const char* DUDE = 
    R"DUDE(
       ○ 
    く|)へ
        〉          
    ￣￣┗┓             
    ￣￣￣┗┓
    ￣￣￣￣┗┓
    ￣￣￣￣￣┗┓
    )DUDE";
    std::cout << DUDE << std::endl;

    type("But you should know… nothing in this manor can ever be that simple.\n\n");
    type("\033[1mYou have been chosen as the lead detective in this case.\033[0m\n");
    type("The lives, the lies, the legacy of the Grimshires now rest in your hands.\n\n");

    type("Tell me, detective… are you ready to face what awaits in the dark?\033[0m\n\n");


    std::cout << "\033[38;2;255;0;0m";
    std::cout << "|═════════════════════════════⊹⊱≼≽⊰⊹═════════════════════════════|\n";
    std::cout << endl;
    std::cout << "                   THE GRIMSHIRE MANOR MURDER                     \n";
    std::cout << endl;
    std::cout << "|═════════════════════════════⊹⊱≼≽⊰⊹═════════════════════════════|\n";
    std::cout << "\033[0m";  // reset
    std::cout << std::endl;




}

void Game::setName(const std::string& n) {   // was: const string&
    name = n;
}

std::string Game::getName() {                // was: string
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
    
    static constexpr const char* POLICE = "\033[34m"  // turn text blue
    R"( 
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

)" 
"\033[0m";

    std::cout << POLICE;

    bool interviewing = true;
    while (interviewing) {
        std::cout << "\033[1mWho would you like to interview?\033[0m\n\n"
                     "\033[1mA)\033[0m Lenora Grimshire (Wife)\n"
                     "\033[1mB)\033[0m Jellal Vexley (Best Friend)\n"
                     "\033[1mC)\033[0m Alexander Grimshire (Son)\n"
                     "\033[1mD)\033[0m Celeste Grimshire (Daughter)\n"
                     "\033[1mE)\033[0m Alfred Crane (Butler)\n"
                     "\033[1mF)\033[0m Dante Vermillion (Chef)\n"
                     "\033[1mQ)\033[0m Quit questioning\n"
                     << endl <<
                     "\033[1mEnter your choice: \033[0m";

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
                    "\t    She moves gracefully, always with perfect posture.\033[0m\n\n", 5);

                std::cout << "\033[1;36m"
                        << "================ INTERVIEW ================"
                        << "\033[0m\n\n";

                type("\033[1;34mDetective:\033[0m \033[3mMrs. Grimshire, where were you last night?\033[0m\n\n", 5);

                type("\033[1mLenora:\033[0m \033[3mAfter I’d greeted everyone and made my rounds in the ballroom,\n"
                    "\tI began to feel a bit lightheaded… too much champagne, perhaps. \n"
                    "\tAround 1:30, I excused myself and went upstairs to my boudoir. \n"
                    "\tI poured myself a glass of wine and settled in with my book..\n"
                    "\tthe music from the ballroom was still faintly drifting up the stairs. \n"
                    "\tI must have dozed off sometime near 2:45. \n"
                    "\tThe next thing I remember was waking to shouting in the hall… \n"
                    "\tit was all so sudden and dreadful.\033[0m\n\n", 15);

                type("\033[1;34mDetective:\033[0m \033[3mDid you and Damian argue that night?\033[0m\n\n", 5);

                type("\033[1mLenora:\033[0m \033[3mYes… but only briefly, about his… behavior. \n"
                    "\tStill, I would never harm him. He had many enemies, Detective.\033[0m\n\n", 5);

                std::cout << "\033[1;31m"   // bold red
                    << "============= INTERVIEW END ============="
                    << "\033[0m\n\n";

                break;

            // ---------------------- Jellal Vexley ---------------------------

            case 'b':
                std::cout << "\n========================================\n\n";

                // suspect label
                std::cout << "\033[1mSuspect:\033[0m Jellal Vexley\n\n";

                // appearance
                type("\033[1mAppearance:\033[0m "
                    "A charming man in his mid-40s with tanned skin, dark eyes, "
                    "\n\t   and black hair streaked with blue highlights.\n"
                    "\t   He wears a maroon tuxedo with shiny gold cufflinks."
                    "\n\t   His smile is warm, but his eyes look calculating.\033[0m\n\n",
                    5);

                // interview header (cyan)
                std::cout << "\033[1;36m"
                        << "============== INTERVIEW =============="
                        << "\033[0m\n\n";

                // Q1
                type("\033[1;34mDetective:\033[0m \033[3mMr. Vexley, where were you last night?\033[0m\n\n", 5);

                // A1 (full alibi, italic body)
                type("\033[1mJellal:\033[0m \033[3mAh yes, I was in the library lounge most of the night. \n"
                    "\tYou know me once I start telling my travel stories, people tend to linger. "
                    "\n\tWe had quite a lively crowd at first, "
                    "\n\tbut by about 2:15 they’d all wandered off to the ballroom for a dance. "
                    "\n\tI stayed behind, poured myself another brandy, "
                    "\n\tand settled by the fire to review some papers. "
                    "\n\tAlfred popped in around 2:40 with a fresh stack of stationery. "
                    "\n\tTruth be told, I was glad for the quiet… "
                    "\n\tDamian had been particularly charming with the ladies tonight, as he tends to be. "
                    "\n\tSometimes I think he forgets who his friends are. "
                    "\n\tStill, I didn’t move from that chair until I heard the commotion.\033[0m\n\n",
                    5);

                // Q2 (motive probe)
                type("\033[1;34mDetective:\033[0m \033[3mYou and Damian—any trouble between you two recently?\033[0m\n\n", 5);

                // A2 (hedged denial)
                type("\033[1mJellal:\033[0m \033[3mTrouble? Hah. Old friends bicker. "
                    "\n\tI told him more than once that parading about the ballroom wasn’t wise for a married man. "
                    "\n\tBut murder? Please. I prefer my duels with words, not weapons.\033[0m\n\n",
                    5);

                // Q3 (timeline nudge)
                type("\033[1;34mDetective:\033[0m \033[3mAnyone see you in the library after 2:15?\033[0m\n\n", 5);

                // A3 (timeline detail)
                type("\033[1mJellal:\033[0m \033[3mOnly Alfred at about 2:40. He’ll confirm it. "
                    "\n\tAnd if the brandy decanter could talk, it would vouch for me too.\033[0m\n\n",
                    5);

                // end banner (bold red, same as your style)
                std::cout << "\033[1;31m"
                        << "============= INTERVIEW END ============="
                        << "\033[0m\n\n";
                break;

            // ---------------------- Alexander Grimshire ---------------------------

            case 'c':
                // separator
                std::cout << "\n========================================\n\n";

                // suspect label
                std::cout << "\033[1mSuspect:\033[0m Alexander Grimshire\n\n";

                // appearance
                type("\033[1mAppearance:\033[0m "
                    "A tall, broad-shouldered 28-year-old with dark brown hair neatly styled. "
                    "He wears a navy suit with a crisp white shirt and a matching tie, though it’s slightly loosened as if he’s restless. "
                    "He often scans the room like he’s thinking two steps ahead.\033[0m\n\n",
                    5);

                // interview header
                std::cout << "\033[1;36m"
                        << "============== INTERVIEW =============="
                        << "\033[0m\n\n";

                // Q1
                type("\033[1;34mDetective:\033[0m \033[3mMr. Grimshire, where were you last night?\033[0m\n\n", 5);

                // A1 (his business call alibi)
                type("\033[1mAlexander:\033[0m \033[3mJust before two o’clock, I stepped out of the ballroom — there was a confidential business matter that couldn’t wait. "
                    "I took the call in the upstairs office where it was quieter. "
                    "The conversation… well, it was delicate, and I needed privacy.\033[0m\n\n",
                    5);

                // Q2 (motive probe)
                type("\033[1;34mDetective:\033[0m \033[3mDamian’s name came up during that call?\033[0m\n\n", 5);

                // A2
                type("\033[1mAlexander:\033[0m \033[3mYes. Damian’s name came up more than once — certain investors are still furious about how he handled a recent deal, "
                    "and I was left cleaning up his mess. I can’t say I wasn’t frustrated; he’s cost me opportunities before.\033[0m\n\n",
                    5);

                // Q3 (timeline clarification)
                type("\033[1;34mDetective:\033[0m \033[3mAnd how long did this call last?\033[0m\n\n", 5);

                // A3
                type("\033[1mAlexander:\033[0m \033[3mAs far as I recall, the call went on right up until three o’clock. "
                    "I’d barely hung up when I heard the crash — glass shattering, voices shouting. "
                    "I left the office straightaway and found the whole place in chaos.\033[0m\n\n",
                    5);

                // end banner
                std::cout << "\033[1;31m"
                        << "============= INTERVIEW END ============="
                        << "\033[0m\n\n";
                break;

            // ---------------------- Celeste Grimshire ---------------------------

            case 'd':
                // separator
                std::cout << "\n========================================\n\n";

                // suspect label
                std::cout << "\033[1mSuspect:\033[0m Celeste Grimshire\n\n";

                // appearance
                type("\033[1mAppearance:\033[0m "
                    "A beautiful 22-year-old with wavy brown hair over one shoulder. "
                    "She has pale skin, bright green eyes, and wears a light blue silk dress with a high slit. "
                    "She laughs easily, but her eyes hint at stubbornness and rebellion.\033[0m\n\n",
                    5);

                // interview header (cyan)
                std::cout << "\033[1;36m"
                        << "============== INTERVIEW =============="
                        << "\033[0m\n\n";

                // Q1
                type("\033[1;34mDetective:\033[0m \033[3mMiss Grimshire, where were you last night?\033[0m\n\n", 5);

                // A1 (her ballroom/kitchen alibi)
                type("\033[1mCeleste:\033[0m \033[3mThe ballroom? Please… you know I can only take so much of those tedious society types. "
                    "I slipped into the kitchen not long after dinner and found Dante there — we ended up talking about a new pastry recipe he’s been working on. "
                    "It was far more interesting than watching half-drunk men stumble through a waltz.\033[0m\n\n",
                    5);

                // Q2
                type("\033[1;34mDetective:\033[0m \033[3mAnd how long did you stay in the kitchen?\033[0m\n\n", 5);

                // A2
                type("\033[1mCeleste:\033[0m \033[3mWe just chatted, sipped some tea… oh, I think I left the kitchen a little before three to fetch my shawl. "
                    "I’d barely gotten back to my room when I heard the shouting. "
                    "It was all such a blur after that.\033[0m\n\n",
                    5);

                // end banner
                std::cout << "\033[1;31m"
                        << "============= INTERVIEW END ============="
                        << "\033[0m\n\n";
                break;

            // ---------------------- Alfred Crane ---------------------------

            case 'e':
                // separator
                std::cout << "\n========================================\n\n";

                // suspect label
                std::cout << "\033[1mSuspect:\033[0m Alfred Crane\n\n";

                // appearance
                type("\033[1mAppearance:\033[0m "
                    "A neat and serious man in his late 60s with silver hair and sharp grey eyes. "
                    "He wears a perfect black butler’s uniform with polished brass buttons and a gold watch chain. "
                    "He moves quietly and with purpose.\033[0m\n\n",
                    5);

                // interview header
                std::cout << "\033[1;36m"
                        << "============== INTERVIEW =============="
                        << "\033[0m\n\n";

                // Q1
                type("\033[1;34mDetective:\033[0m \033[3mMr. Crane, could you tell me where you were during the evening?\033[0m\n\n", 5);

                // A1 (alibi part 1)
                type("\033[1mAlfred:\033[0m \033[3mI was on my feet all evening, as you’d expect — making the rounds between the dining room and ballroom, "
                    "keeping glasses topped up and seeing to the guests’ coats.\033[0m\n\n",
                    5);

                // Q2
                type("\033[1;34mDetective:\033[0m \033[3mWhat were you doing around midnight?\033[0m\n\n", 5);

                // A2
                type("\033[1mAlfred:\033[0m \033[3mAround 12:00, once things had settled into their rhythm, I began polishing the silver in the dining room between service rounds.\033[0m\n\n",
                    5);

                // Q3
                type("\033[1;34mDetective:\033[0m \033[3mAnd just before the incident?\033[0m\n\n", 5);

                // A3 (final timeline detail)
                type("\033[1mAlfred:\033[0m \033[3mBy the time the clock was nearing 3:00, I’d moved on to arranging flowers in the foyer for the morning. "
                    "That’s when I heard it — the crash, the shouting. I went straight to see what had happened.\033[0m\n\n",
                    5);

                // end banner
                std::cout << "\033[1;31m"
                        << "============= INTERVIEW END ============="
                        << "\033[0m\n\n";
                break;

            // ---------------------- Dante Vermillion ---------------------------

            case 'f':
                // separator
                std::cout << "\n========================================\n\n";

                // suspect label
                std::cout << "\033[1mSuspect:\033[0m Dante Vermillion\n\n";

                // appearance
                type("\033[1mAppearance:\033[0m "
                    "An Italian man in his early 30s with olive-toned skin, brown eyes, and dark hair swept back. "
                    "He wears spotless white chef’s clothes and a small silver necklace with a Van Cleef charm. "
                    "His hands are strong and a little scarred from years of cooking.\033[0m\n\n",
                    5);

                // interview header
                std::cout << "\033[1;36m"
                        << "============= INTERVIEW ============="
                        << "\033[0m\n\n";

                // Q1
                type("\033[1;34mDetective:\033[0m \033[3mChef Vermillion, where were you during the evening?\033[0m\n\n", 5);

                // A1
                type("\033[1mDante:\033[0m \033[3mI was in the kitchen for most of the night — plenty to do after the gala supper. "
                    "Celeste joined me for a bit; we shared tea and talked about some new recipes I’d been working on.\033[0m\n\n",
                    5);

                // Q2
                type("\033[1;34mDetective:\033[0m \033[3mWhen did Celeste leave?\033[0m\n\n", 5);

                // A2
                type("\033[1mDante:\033[0m \033[3mShe left a little before three o’clock, and I stayed behind to tidy up. "
                    "I put away the silver, wiped the counters, made sure everything was ready for breakfast.\033[0m\n\n",
                    5);

                // Q3
                type("\033[1;34mDetective:\033[0m \033[3mAnd when did you leave the kitchen?\033[0m\n\n", 5);

                // A3
                type("\033[1mDante:\033[0m \033[3mI didn’t step out until I went to my quarters, just before the shouting started.\033[0m\n\n",
                    5);

                // end banner
                std::cout << "\033[1;31m"
                        << "============= INTERVIEW END ============="
                        << "\033[0m\n\n";
                break;


            case 'q':
                cout << "You wrap up the questioning for now. ب_ب\n\n";
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
    std::cout << "A) Lenora Grimshire (Wife) 𓏌\n";
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
        std::cout << "\033[1;32mYour accusation rings true. Justice is served \\( ﾟヮﾟ)/\033[0m\n";
        return true;   // end game (success)
    } else {
        std::cout << "\033[1;31mYour accusation fails. The killer smiles (≖_≖ )\033[0m\n";
        return true;   // end game (failure)
    }
}