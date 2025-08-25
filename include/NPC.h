#ifndef NONPLAYERCHARACTER_H
#define NONPLAYERCHARACTER_H

#include <string>

class NonPlayerCharacter {
	public:
		NonPlayerCharacter(const std::string name,
						   const std::string description,
						   const std::string alibi);		//constructor

		std::string getName() const;				//returns NPC name
		std::string getDescription() const;			//returns when player selects "talk"
		std::string getAlibi() const;				//returns when player selects "question"
	private:
		std::string name;
		std::string description;
		std::string alibi;
};

#endif