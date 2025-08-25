#ifndef SUSPECT_H
#define SUSPECT_H

#include <string>

class Suspect {
	public:
		Suspect(const std::string name,
						   const std::string description,
						   const std::string alibi);		//constructor

		std::string getName() const;				//returns NPC name
		std::string getDescription() const;			//returns when player selects "talk"
		std::string getAlibi() const;				//returns when player selects "question"
		void TalkToSuspect(const Suspect& suspect) const;
	private:
		std::string name;
		std::string description;
		std::string alibi;
};

#endif