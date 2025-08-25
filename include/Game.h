#pragma once
#include <vector>
#include <string>

#include "Character.h"
#include "Clue.h"
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

        // prints intro including the mansion + title
        void printIntroduction();
        // prints 

        // introduces the suspects at the polic staion
        void printSuspectIntroduction();

        // movements 
        bool move(const std::string& roomName);


        // find room by name 
        Location* findRoom(const std::string& roomName) const;
        void visit(Location& room);



        // describes current loc
        void describe() const;

        // clues & statements (#5 & #12)
        void addClue(const Clue& c);
        void reviewClues() const;
        void addStatement(const std::string& s);
        void reviewStatements() const;
       
        // suspects (#11)
        void initSuspects();
        //void talkToSuspect(const string& suspectName);


       // optional helper for main loop
       void talkToNPC(const string& npcName);
};