#pragma once
#include <string>

class Clue {
    private:
        std::string name;
        std::string description;
        std::string location;

    public:
        // class contructor
        Clue(const std::string& name, const std::string& description, const std::string& location);

        void printClue() const;                 // prints the clue in the format [name] : [description]
        static void printCountdown();           // prints how many turns/ clues they have left
        static bool useClue();                  // use before finding every clue to check if they can

        // clue getter methods
        const std::string& getName() const noexcept;
        const std::string& getLocation() const noexcept;
        const std::string& getDescription() const noexcept;
};
