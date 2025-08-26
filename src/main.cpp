#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "Type.h"
#include "Game.h"
#include "Suspect.h"

using namespace std;

int main(){

    Game game;
    game.printIntroduction();
    
    string name;
    type("Enter your name: ");
    getline(cin, name);
    cout << endl;
    game.setName(name);


    // ask the player a question
    type("Are you up to the task, \033[1mDetective " + game.getName() + "\033[0m?\n\n");
    cout << "A) Yes\nB) No\n";
    cout << endl;
    cout << "Enter your choice: ";


    // responses to the selected choice
    string choice;
    bool choiceMade = false;
    bool running = false;
    while(choiceMade == false){
        getline(cin, choice);
        if(choice == "a" || choice == "A" || choice == "yes" || choice == "Yes") {
            choiceMade = true;
            type("\n\033[3mVery Well. The fate of the investigation now rests with you, " + game.getName() + ".\n");
            type("Tread carefully… every word, every glance, every clue matters.\n");
            type("Let us begin.\033[0m\n\n");
            game.printSuspectIntroduction();
            running = true;
        } else if(choice == "b" || choice == "B" || choice == "no" || choice == "No") {
            choiceMade = true;
            type("\n\033[3m…Ah. Perhaps the weight of the Grimshire legacy is too much for one soul to bear.\n");
            type("But justice waits for no one, detective.\n");
            type("When you are ready… the manor will still be here.\033[0m\n");
            running = false;
        } else {
            choiceMade = false;
            type("\n\033[3mI didn’t quite catch that…\n");
            type("Is it a yes… or a no, detective?\n");
            type("The Grimshires don’t take kindly to indecision…\033[0m\n");
            cout << endl;
            cout << "Enter your choice: ";
        }
    }


    // ignore the 2nd line for all of these (that's not being printed out but can't be deleted rn either lol) 
    Suspect Lenora(
        "Lenora Grimshire",
        "is an elegant woman in her early 50s. She has smooth chestnut-brown hair pinned up neatly with sparkling diamond clips. Her blue silk gown matches her sharp green eyes, and she wears long satin gloves. She moves gracefully, always with perfect posture.",
        "Lenora recalls greeting guests in the ballroom, but feeling dizzy from champagne. Around 1:30, she went to her boudoir, poured wine, and read a book. She drifted asleep until about 2:45, when shouting in the hall woke her suddenly."
        "I bet it was Damian's best friend. He was even more upset than I was about what happened between my husband and his wife."
    );

    Suspect Jellal(
        "Jellal Vexley",
        "is a charming man in his mid-40s with tanned skin, dark eyes, and black hair streaked with blue highlights. He wears a maroon tuxedo with shiny gold cufflinks. His smile is warm, but his eyes look like he’s always calculating something.",
        "He recalls spending the evening in the library lounge telling travel stories. Around 2:15, the crowd left for the ballroom, and he stayed behind with brandy and business papers. At 2:40, Alfred brought him stationery. He remained there until the commotion began."
        "I would focus your search onto that butler, I know that had some gripes with him."
    );

    Suspect Alexander (
        "Alexander Grimshire",
        "is a tall, broad-shouldered 28-year-old with dark brown hair neatly styled. He wears a navy suit with a crisp white shirt and a matching tie, though it’s slightly loosened as if he’s restless. He often scans the room like he’s thinking two steps ahead.",
        "He recalls leaving the ballroom just before 2:00 to take a private business call in the upstairs office. The call involved Damian and angry investors, lasting until around 3:00. Moments after hanging up, he heard shattering glass and shouting, then rushed out to find chaos."
        "I know that my father was upset with our chef. He was having a secret relationship with my sister, and my father did not approve of it."
    );

    Suspect Celeste (
        "Celeste Grimshire",
        "is a beautiful 22-year-old with wavy brown hair over one shoulder. She has pale skin, bright green eyes, and wears a light blue silk dress with a high slit. She laughs easily, but her eyes hint at stubbornness and rebellion.",
        "She avoided the ballroom after dinner and went to the kitchen, where she talked with Dante about a new pastry recipe. They drank tea and chatted until just before 3:00, when she left to fetch her shawl. Soon after returning to her room, she heard shouting and chaos began."
        "I hope no one says me. Sure, I was upset at my father for forcing me to marry that dumbwitted chump, but I would never lay a finger on him."
    );

    Suspect Alfred (
        "Alfred Crane",
        "is a neat and serious man in his late 60s with silver hair and sharp grey eyes. He wears a perfect black butler’s uniform with polished brass buttons and a gold watch chain. He moves quietly and with purpose.",
        "He spent the evening tending to guests between the dining room and ballroom. Around midnight, he polished silver in the dining room, then arranged flowers in the foyer near 3:00. That’s when he heard the crash and shouting, and went to investigate."
        "Damian was always getting into it with that son of his...and you know, I always though Alexander was such a selfish young man for trying to get all of Damian's inheritance. I never heard if he did."
    );

    Suspect Dante (
        "Dante Vermillion",
        "is an Italian man in his early 30s with olive-toned skin, brown eyes, and dark hair swept back. He wears spotless white chef’s clothes and a small silver necklace with a van cleef charm. His hands are strong and a little scarred from years of cooking.",
        "He stayed in the kitchen most of the night, tidying after supper. Celeste joined him for tea and recipes until just before 3:00. He finished cleaning and put things away, only leaving for his quarters right before the shouting began."
        "The other night, Damian's wife found out that he had been cheating on her. I was still at the house, cleaning up from dinner, and boy she was angry."
    );


    // start game loop
    
    cout << endl;
    
    // start game loop

    // first starts with suspect interviews at police station

    while (running) {
        
        cout << "\n\033[1m====== What would you like to do? ======\033[0m\n";
        cout << endl;
        cout << "A) Go to Foyer\nB) Go to Bedroom\nC) Go to Kitchen\n";
        cout << "D) Go to Office\nE) Go to Library\nF) Review Suspects\n";
        cout << "G) Accuse Suspect\n";
        cout << "Q) Quit\n";
        cout << endl;
        std::cout << "Enter your choice: ";
        std::getline(std::cin, choice);
        if (!choice.empty()) {
            choice = std::string(1, std::tolower(choice[0]));
        }

        //  movement 
        if (choice == "A" || choice == "a") game.move("a");
        else if (choice == "B" || choice == "b") game.move("b");
        else if (choice == "C" || choice == "c") game.move("c");
        else if (choice == "D" || choice == "d") game.move("d");
        else if (choice == "E" || choice == "e") game.move("e");

        // ----------------- Talk to Suspects -----------------
        else if (choice == "F" || choice == "f") {
            char userChoice = game.TalkOptions();  
                if (userChoice == 'a') {
                    game.TalkToSuspect(Lenora);
                }
                else if (userChoice == 'b') {
                    game.TalkToSuspect(Jellal);
                }
                else if (userChoice == 'c') {
                    game.TalkToSuspect(Alexander);
                }
                else if (userChoice == 'd') {
                    game.TalkToSuspect(Celeste);
                }
                else if (userChoice == 'e') {
                    game.TalkToSuspect(Alfred);
                }
                else if (userChoice == 'f'){
                    game.TalkToSuspect(Dante);
            }    //stores player's selection
        } else if (choice == "g"){
            if (game.accuseSuspect()) {
                running = false;   // or just: break;
            }
        } else if (choice == "Q" || choice == "q") {
            cout << "\n\033[3mReally? Quitting? The case isn’t going to solve itself, \033[1mDetective " + game.getName() + "...\033[0m\n";
            cout << "\033[3m...Fine. Exiting the game. The murderer wins this round.\033[0m\n";
            running = false;
        }

        //  invalid input
        else cout << "Invalid choice. Try again.\n";
    }

    std::cout << "\n";
    std::cout << "\033[1;31m"; // bold red
    std::cout << "=============================================\n";
    std::cout << "                   END GAME                 \n";
    std::cout << "=============================================\n";
    std::cout << "\033[0m\n"; 

    return 0;
}