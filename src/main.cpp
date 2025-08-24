#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "Game.h"

using namespace std;

// made a function to type slowly like a typewriter, instead of the speedy cout
// makes it more ominous..? suspensful..? trust
void type(string text, int speed = 30){
    for(int i = 0; i < text.length(); i++){
        cout << text[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
}

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

    // responses to the selected choice
    string choice;
    bool choiceMade = false;
    while(choiceMade == false){
        getline(cin, choice);
        if(choice == "a" || choice == "A" || choice == "yes" || choice == "Yes") {
            choiceMade = true;
            type("\nVery Well. The fate of the investigation now rests with you.\n");
            type("Tread carefully… every word, every glance, every clue matters.\n");
            type("Let us begin.\n");
        } else if(choice == "b" || choice == "B" || choice == "no" || choice == "No") {
            choiceMade = true;
            type("\n…Ah. Perhaps the weight of the Grimshire legacy is too much for one soul to bear.\n");
            type("But justice waits for no one, detective.\n");
            type("When you are ready… the manor will still be here.\n");
        } else {
            choiceMade = false;
            type("\nI didn’t quite catch that…\n");
            type("Is it a yes… or a no, detective?\n");
            type("The Grimshires don’t take kindly to indecision…\n");
            cout << endl;
            cout << "Enter your choice: ";
        }
    }
}