#pragma once
#include <vector>
#include <string>

#include "character.h"
#include "clue.h"
#include "game.h"
#include "location.h"

class Game {
    private: 
        bool running;
        std::vector<character> suspects;    // character.h to be implemented
        std::vector<clue> clues;            // clue.h to be implemented
        Location* currentLocation_ = nullptr;
    public:
        bool move(const std::string& roomName);

    // helpers
        Location* findRoom(const std::string& roomName) const;
        bool move(const std::string& roomName);
        void describe() const;
};