#pragma once
#include <string>
#include <vector>
class Location {
    public:
    std::string name;
    std::string description;
    std::vector<std::string> options;
    std::string menuChoice;

    Location(std::string name, std::string description);


    void describe() const; // removed location:: 
    void addOption(const std::string& option);
    void showOptions();           // prints a)/b)/c)/... and "x) back"
    void showLocationOptions();
    void interact();
};

class Foyer : public Location { public: Foyer(); };
class Library : public Location { public: Library(); };
class Office  : public Location { public: Office(); };
class Kitchen : public Location { public: Kitchen(); };
class Bedroom : public Location { public: Bedroom(); };