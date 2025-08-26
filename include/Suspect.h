#pragma once
#include <string>

class Suspect {
	private:
		std::string name;
		std::string description;
		std::string alibi;

	public:
		Suspect(const std::string& name,
				const std::string& description,
				const std::string& alibi);

		const std::string& getName() const noexcept;        // npc name
		const std::string& getDescription() const noexcept; // shows when player selects "talk"
		const std::string& getAlibi() const noexcept;       // shows when player selects "question"

		void talkToSuspect(const Suspect& suspect) const;   // interaction with another suspect (to be implemented)
};
