#pragma once
#include <string>
#include <vector>
class Location {
    public:
    std::string name;
    std::string description;

    Location(std::string name, std::string description);
    void describe() const;
    virtual ~Location() = default;
};

class Foyer : public Location { public: Foyer(); };
class Library : public Location { public: Library(); };
class Office  : public Location { public: Office(); };
class Kitchen : public Location { public: Kitchen(); };
class Bedroom : public Location { public: Bedroom(); };