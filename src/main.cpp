#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "Type.h"
#include "Game.h"

using namespace std;

int main(){
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

    // ask the player a question
    type("Are you up to the task, detective?\n\n");
    cout << "A) Yes\nB) No\n";
    cout << endl;
    cout << "Enter your choice: ";

    Game game;

    // responses to the selected choice
    string choice;
    bool choiceMade = false;
    bool running = false;
    while(choiceMade == false){
        getline(cin, choice);
        if(choice == "a" || choice == "A" || choice == "yes" || choice == "Yes") {
            choiceMade = true;
            type("\nVery Well. The fate of the investigation now rests with you.\n");
            type("Tread carefully… every word, every glance, every clue matters.\n");
            type("Let us begin.\n");
            running = true;
        } else if(choice == "b" || choice == "B" || choice == "no" || choice == "No") {
            choiceMade = true;
            type("\n…Ah. Perhaps the weight of the Grimshire legacy is too much for one soul to bear.\n");
            type("But justice waits for no one, detective.\n");
            type("When you are ready… the manor will still be here.\n");
            running = false;
        } else {
            choiceMade = false;
            type("\nI didn’t quite catch that…\n");
            type("Is it a yes… or a no, detective?\n");
            type("The Grimshires don’t take kindly to indecision…\n");
            cout << endl;
            cout << "Enter your choice: ";
        }
    }


    // Start game loop
    game.initSuspects(); // initialize options in the menu 

    while (running) {
        cout << "\n=== What would you like to do? ===\n";
        cout << "F) Go to Foyer\nB) Go to Bedroom\nK) Go to Kitchen\n";
        cout << "O) Go to Office\nL) Go to Library\n";
        cout << "Q) Quit\n";
        cout << "Enter your choice: ";
        getline(cin, choice);

        // ----------------- Movement -----------------
        if (choice == "A" || choice == "a") game.move("a");
        else if (choice == "B" || choice == "b") game.move("b");
        else if (choice == "C" || choice == "c") game.move("c");
        else if (choice == "D" || choice == "d") game.move("d");
        else if (choice == "E" || choice == "e") game.move("e");

        // ----------------- Talk to NPC -----------------
       // else if (choice == "T" || choice == "t") {
          //  string npcChoice;
          //  cout << "Who do you want to talk to? (Lenora/Alexander/Celeste/Alfred/Dante/Jellal): ";
          //  getline(cin, npcChoice);
          //  game.talkToNPC(npcChoice); // dynamically fetch from suspects vector
       // }

        // ----------------- Review clues -----------------
       // else if (choice == "C" || choice == "c") game.reviewClues();

        // ----------------- Review statements -----------------
      //  else if (choice == "S" || choice == "s") game.reviewStatements();

        // ----------------- Quit -----------------
        else if (choice == "Q" || choice == "q") {
            cout << "Exiting the game. Goodbye!\n";
            running = false;
        }

        // ----------------- Invalid input -----------------
        else cout << "Invalid choice. Try again.\n";
    }

    return 0;
}