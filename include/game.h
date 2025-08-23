#pragma once
#include <vector>
#include <string>

#include "character.h"
#include "clue.h"
#include "game.h"

class game {
    private: 
        bool running;
        std::vector<character> suspects;    // character.h to be implemented
        std::vector<clue> clues;            // clue.h to be implemented
        std::vector<location> locations;    // location.h to be implemented
}