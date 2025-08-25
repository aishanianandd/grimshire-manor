#ifndef NONPLAYERCHARACTER_H
#define NONPLAYERCHARACTER_H

#include <string>

class NonPlayerCharacter {
	public:
		NonPlayerCharacter(const std::string name,
						   const std::string description,
						   const std::string alibi,
						   const std::string blame);		//constructor

		std::string getName() const;				//returns NPC name
		std::string getDescription() const;			//returns when player selects "talk"
		std::string getAlibi() const;				//returns when player selects "question"
		std::string getBlame() const;			//return when player selects "question further"
	private:
		std::string name;
		std::string description;
		std::string alibi;
		std::string blame;
};

#endif