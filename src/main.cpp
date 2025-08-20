#include <iostream>
#include <string>
#include <thread>
#include <chrono>

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