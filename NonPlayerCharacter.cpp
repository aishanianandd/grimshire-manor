#include "NonPlayerCharacter.h"
#include <string>

using namespace std;

NonPlayerCharacter::NonPlayerCharacter(string n, string d, string a, string b) 
    : name(n), description(d), alibi(a), blame(b) {}

string NonPlayerCharacter::getName() const {
    return name;
}

string NonPlayerCharacter::getDescription() const {
    return description;
}

string NonPlayerCharacter::getAlibi() const {
    return alibi;
}		

string NonPlayerCharacter::getBlame() const {
    return blame;
}