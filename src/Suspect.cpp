#include "Suspect.h"
#include <iostream>

Suspect::Suspect(const std::string& name,
                 const std::string& description,
                 const std::string& alibi)
    : name(name), description(description), alibi(alibi) {}

const std::string& Suspect::getName() const noexcept {
    return name;
}

const std::string& Suspect::getDescription() const noexcept {
    return description;
}

const std::string& Suspect::getAlibi() const noexcept {
    return alibi;
}

void Suspect::talkToSuspect(const Suspect& suspect) const {
    std::cout << "\nName: " << suspect.getName() << '\n'
              << "Description: " << suspect.getDescription() << '\n'
              << "Alibi: " << suspect.getAlibi() << "\n\n";
}
