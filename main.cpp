#include <iostream>
#include <string>
#include <cctype>
#include "NonPlayerCharacter.h"

using namespace std;

char TalkOptions() {  
    char input;

    cout << "Who would you like to talk to?" << endl;

    do {
        cout << "(a) Damian's wife, Lenora Grimshire" << endl;
        cout << "(b) Damian's best friend, Jellal Vexley" << endl;
        cout << "(c) Damian's son, Alexander Grimshire" << endl;
        cout << "(d) Damian's duaghter, Celeste Grimshire" << endl;
        cout << "(e) The butler, Alfred Crane" << endl;
        cout << "(f) The chef, Dante Vermillion" << endl;
        cout << "Please enter a letter a-f" << endl;

        cin >> input;
        input = tolower(input);     //in case the player enters capital

        if (input < 'a' || input > 'f') {
            cout << "Invalid input. Please enter a letter a-f" << endl;
            cin >> input;
        }

    } while (input < 'a' || input > 'f');

    return input;
}

void TalkToNPC(const NonPlayerCharacter& npc) {
    char input;
    bool askedAlibi = false;
    bool askedBlame = false;

    cout << npc.getName() << " " << npc.getDescription() << endl;
    
    do {
        cout << "How would you like to proceed?" << endl;

        if (!askedAlibi)
            cout << "(a) question " << npc.getName() << " about their whereabouts during the time of the murder" << endl;
       
        if (!askedBlame)
            cout << "(b) ask " << npc.getName() << " if they have any suspects in mind" << endl;

        cout << "(c) exit the conversation" << endl;
        cout << "Please enter a letter a-c" << endl;

        cin >> input;
        input = tolower(input);

        if (input == 'a' && !askedAlibi) {
            cout << "You ask " << npc.getName() << " what their alibi is." << endl;
            cout << npc.getAlibi() << endl;
            askedAlibi = true;
        }
        else if (input == 'b' && !askedBlame) {
            cout << "You ask " << npc.getName() << " who they suspect." << endl;
            cout << npc.getBlame() << endl;
            askedBlame = true;
        }
        else if (input == 'c') {
            cout << "You have ended the conversation with " << npc.getName() << endl;
            return;
        }
        else {
            cout << "That was an invalid input or you may have asked that already. Try again" << endl;
        }

        if (askedAlibi && askedBlame) {
            cout << npc.getName() << " doesn't have anything else to share, they exit the conversation." << endl;
            return;
        }

    } while (true);
}

int main() {
    //create NPCs

    NonPlayerCharacter Lenora(
        "Lenora Grimshire",
        "is an elegant woman in her early 50s. She has smooth chestnut-brown hair pinned up neatly with sparkling diamond clips. Her blue silk gown matches her sharp green eyes, and she wears long satin gloves. She moves gracefully, always with perfect posture.",
        "After I’d greeted everyone and made my rounds in the ballroom, I began to feel a bit lightheaded… too much champagne, perhaps. Around 1:30, I excused myself and went upstairs to my boudoir. I poured myself a glass of wine and settled in with my book — the music from the ballroom was still faintly drifting up the stairs. I must have dozed off sometime near 2:45. The next thing I remember was waking to shouting in the hall… it was all so sudden and dreadful.",
        "I bet it was Damian's best friend. He was even more upset than I was about what happened between my husband and his wife."
    );

    NonPlayerCharacter Jellal(
        "Jellal Vexley",
        "is a charming man in his mid-40s with tanned skin, dark eyes, and black hair streaked with blue highlights. He wears a maroon tuxedo with shiny gold cufflinks. His smile is warm, but his eyes look like he’s always calculating something.",
        "Ah yes, I was in the library lounge most of the night. You know me — once I start telling my travel stories, people tend to linger. We had quite a lively crowd at first, but by about 2:15  they’d all wandered off to the ballroom for a dance. I stayed behind, poured myself another brandy, and settled by the fire to review some business papers I’d brought along. Alfred popped in around 2:40 with a fresh stack of stationery for me — very attentive fellow. Truth be told, I was glad for the quiet… Damian had been particularly charming with the ladies tonight, as he tends to be. Sometimes I think he forgets who his friends are. Still, I didn’t move from that chair until I heard the commotion.",
        "I would focus your search onto that butler, I know that had some gripes with him."
    );

    NonPlayerCharacter Alexander (
        "Alexander Grimshire",
        "is a tall, broad-shouldered 28-year-old with dark brown hair neatly styled. He wears a navy suit with a crisp white shirt and a matching tie, though it’s slightly loosened as if he’s restless. He often scans the room like he’s thinking two steps ahead.",
        "Just before two o’clock, I stepped out of the ballroom — there was a confidential business matter that couldn’t wait. I took the call in the upstairs office where it was quieter. The conversation… well, it was delicate, and I needed privacy. Damian’s name came up more than once — certain investors are still furious about the way he handled a recent deal, and I was left cleaning up his mess. I can’t say I wasn’t frustrated; he’s cost me opportunities before. As far as I recall, the call went on right up until three o’clock. I’d barely hung up when I heard the crash — glass shattering, voices shouting. I left the office straightaway and found the whole place in chaos.",
        "I know that my father was upset with our chef. He was having a secret relationship with my sister, and my father did not approve of it."
    );

    NonPlayerCharacter Celeste (
        "Celeste Grimshire",
        "is a beautiful 22-year-old with wavy brown hair over one shoulder. She has pale skin, bright green eyes, and wears a light blue silk dress with a high slit. She laughs easily, but her eyes hint at stubbornness and rebellion.",
        "The ballroom? Please… you know I can only take so much of those tedious society types. I slipped into the kitchen not long after dinner and found Dante there — we ended up talking about a new pastry recipe he’s been working on. It was far more interesting than watching half-drunk men stumble through a waltz. We just chatted, sipped some tea… oh, I think I left the kitchen a little before three to fetch my shawl. I’d barely gotten back to my room when I heard the shouting. It was all such a blur after that.",
        "I hope no one says me. Sure, I was upset at my father for forcing me to marry that dumbwitted chump, but I would never lay a finger on him."
    );

    NonPlayerCharacter Alfred (
        "Alfred Crane",
        "is a neat and serious man in his late 60s with silver hair and sharp grey eyes. He wears a perfect black butler’s uniform with polished brass buttons and a gold watch chain. He moves quietly and with purpose.",
        "I was on my feet all evening, as you’d expect — making the rounds between the dining room and ballroom, keeping glasses topped up and seeing to the guests’ coats. Around 12:00, once things had settled into their rhythm, I began polishing the silver in the dining room between service rounds. By the time the clock was nearing 3:00, I’d moved on to arranging flowers in the foyer for the morning. That’s when I heard it — the crash, the shouting. I went straight to see what had happened.",
        "Damian was always getting into it with that son of his...and you know, I always though Alexander was such a selfish young man for trying to get all of Damian's inheritance. I never heard if he did."
    );

    NonPlayerCharacter Dante (
        "Dante Vermillion",
        "is an Italian man in his early 30s with olive-toned skin, brown eyes, and dark hair swept back. He wears spotless white chef’s clothes and a small silver necklace with a van cleef charm. His hands are strong and a little scarred from years of cooking.",
        "I was in the kitchen for most of the night — plenty to do after the gala supper. Celeste joined me for a bit; we shared tea and talked about some new recipes I’d been working on. She left a little before 3:00, and I stayed behind to finish tidying up. I put away the silver, wiped the counters, made sure everything was ready for breakfast. I didn’t step out until I went to my quarters, just before the shouting started.",
        "The other night, Damian's wife found out that he had been cheating on her. I was still at the house, cleaning up from dinner, and boy she was angry."
    );

    char userChoice = TalkOptions();      //stores player's selection

    if (userChoice == 'a') {
        TalkToNPC(Lenora);
    }
    else if (userChoice == 'b') {
        TalkToNPC(Jellal);
    }
    else if (userChoice == 'c') {
        TalkToNPC(Alexander);
    }
    else if (userChoice == 'd') {
        TalkToNPC(Celeste);
    }
    else if (userChoice == 'e') {
        TalkToNPC(Alfred);
    }
    else {
        TalkToNPC(Dante);
    }

    return 0;
}