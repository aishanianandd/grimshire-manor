#pragma once
#include <string>

using namespace std;

class character{
    private:
        string name;
        string alibi;
    public:
        character(const string& name, const string& alibi);  // add characters as story progresses w/ this constructor
        void printInfo();
        string getName();
        string getAlibi();
}