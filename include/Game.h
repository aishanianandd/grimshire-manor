#pragma once
#include <vector>
#include <string>

#include "Character.h"
#include "Clue.h"
#include "Game.h"
#include "Location.h"

class Game {
    private: 
        bool running;
        std::vector<Character> suspects;    // character.h to be implemented
        std::vector<Clue> clues;            // clue.h to be implemented
        Location* currentLocation_ = nullptr;
    public:
        bool move(const std::string& roomName);

    // helpers
        Location* findRoom(const std::string& roomName) const;
        bool move(const std::string& roomName);
        void describe() const;
};