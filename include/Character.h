#pragma once
#include <string>

using namespace std;

class Character {
    private:
        string name;
        string alibi;
    public:
        Character(const string& name, const string& alibi);     // add characters as story progresses w/ this constructor
        void printInfo();                                       // prints all info: character name + dialogue
        string getName();                                       // returns character name
        string getAlibi();                                      // return their alibi
};