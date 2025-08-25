#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "Type.h"
#include "Game.h"

using namespace std;

int main(){

    Game game;
    game.printIntroduction();
    

    // ask the player a question
    type("Are you up to the task, detective?\n\n");
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

    cout << endl;
    game.printSuspectIntroduction();
    cout << endl;
    
    // start game loop
    game.initSuspects(); // initialize options in the menu 
    

    while (running) {
        cout << "\n=== What would you like to do? ===\n";
        cout << "A) Go to Foyer\nB) Go to Bedroom\nC) Go to Kitchen\n";
        cout << "D) Go to Office\nE) Go to Library\nF) Talk to Suspects\n";
        cout << "Q) Quit\n";
        cout << "Enter your choice: ";
        getline(cin, choice);

        //  movement 
        if (choice == "A" || choice == "a") game.move("a");
        else if (choice == "B" || choice == "b") game.move("b");
        else if (choice == "C" || choice == "c") game.move("c");
        else if (choice == "D" || choice == "d") game.move("d");
        else if (choice == "E" || choice == "e") game.move("e");

        // ----------------- Talk to Suspects -----------------
        else if (choice == "F" || choice == "f") {
            string userChoice;
            cout << "Who do you want to talk to? (Lenora/Alexander/Celeste/Alfred/Dante/Jellal): ";
            getline(cin, userChoice);
            //game.talkToSuspect(userChoice); // dynamically fetch from suspects vector
        }

        // ----------------- Review clues -----------------
       // else if (choice == "C" || choice == "c") game.reviewClues();

        // ----------------- Review statements -----------------
      //  else if (choice == "S" || choice == "s") game.reviewStatements();

        //  quit 
        else if (choice == "Q" || choice == "q") {
            cout << "Exiting the game. Goodbye!\n";
            running = false;
        }

        //  invalid input
        else cout << "Invalid choice. Try again.\n";
    }

    return 0;
}