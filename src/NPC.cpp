#include "NPC.h"
#include <string>

using namespace std;

NonPlayerCharacter::NonPlayerCharacter(string n, string d, string a) 
    : name(n), description(d), alibi(a) {}

string NonPlayerCharacter::getName() const {
    return name;
}

string NonPlayerCharacter::getDescription() const {
    return description;
}

string NonPlayerCharacter::getAlibi() const {
    return alibi;
}