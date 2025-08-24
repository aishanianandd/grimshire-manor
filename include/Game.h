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
        vector<Character> suspects;    // character.h to be implemented
        vector<Clue> clues;            // clue.h to be implemented
        Location* currentLocation_ = nullptr;


    public:
        Game();


    // helpers
        Location* findRoom(const std::string& roomName) const;
        bool move(const string& roomName);
        void describe() const;
};