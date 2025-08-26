#pragma once
#include <vector>
#include <string>

#include "Clue.h"
#include "Location.h"
#include "Suspect.h"

class Game {
    private:
        bool running;    
        std::string name;

        std::vector<Suspect> suspects;            // switched from vector<Character>
        std::vector<Clue> clues;
        std::vector<std::string> heardStatements;

        Location* currentLocation_ = nullptr;     // raw pointer as in your current .cpp

        // Used in accuseSuspect(); kept as a member so your current Game.cpp compares to it directly
        const std::string TRUE_KILLER = "Celeste Grimshire";

    public:
        ~Game();
        // game flow
        void printIntroduction();
        bool move(const std::string& choice);     // choose a room and interact
        void setName(const std::string& n);
        std::string getName();                    // matches your Game.cpp return type

        // clues + statements
        void addClue(const Clue& c);
        void reviewClues() const;
        void addStatement(const std::string& s);
        void reviewStatements() const;

        // interact w/ suspects
        char TalkOptions();
        void TalkToSuspect(Suspect& suspect);
        void printSuspectIntroduction();
        bool accuseSuspect();

        // optional helper used by the main loop
        void talkToNPC(const std::string& npcName);
};
