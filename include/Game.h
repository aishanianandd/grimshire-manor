#pragma once
#include <vector>
#include <string>

#include "Character.h"
#include "Clue.h"


// #include "Game.h" commented bc, is this supposed to be here?
>>>>>>> 649f65b (Implemented Clue Discovery (#5), NPC Statements (#12), and Suspect Alibis (#11))
#include "Location.h"

using std::vector;
using std::string;

class Game {
    private: 
        bool running;

        std::vector<Character> suspects;    // character.h to be implemented
        std::vector<Clue> clues;            // clue.h to be implemented
        vector<string> heardStatements;  // to store statements (#12)
        Location* currentLocation_ = nullptr;


    public:


    // helpers

        // movements 
        bool move(const std::string& roomName);


        // find room by name 
        Location* findRoom(const std::string& roomName) const;



        // describes current loc
        void describe() const;

        // clues & statements (#5 & #12)
        void addClue(const Clue& c);
        void reviewClues() const;
        void addStatement(const std::string& s);
        void reviewStatements() const;
       
        // suspects (#11)
        void initSuspects();


       // optional helper for main loop
       void talkToNPC(const string& npcName);
};