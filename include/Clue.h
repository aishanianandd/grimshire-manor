#pragma once
#include <string>

using namespace std;

class Clue {
    private:
        string name;
        string description;
        string location;
        int num = 4;
    public:
        Clue(const string name, const string description, const string location);
        void printClue() const;
        static void printCountdown();
        string getName() const;
        string getLocation() const;
        static bool useClue();  // use before finding every clue to check if they can 
};