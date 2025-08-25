#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "Type.h"
#include "Game.h"
#include "Suspect.h"

using namespace std;

int main(){

    Game game;
    game.printIntroduction();
    

    // ask the player a question
    type("Are you up to the task, detective?\n\n");
    cout << "A) Yes\nB) No\n";
    cout << endl;
    cout << "Enter your choice: ";


    // responses to the selected choice
    string choice;
    bool choiceMade = false;
    bool running = false;
    while(choiceMade == false){
        getline(cin, choice);
        if(choice == "a" || choice == "A" || choice == "yes" || choice == "Yes") {
            choiceMade = true;
            type("\nVery Well. The fate of the investigation now rests with you.\n");
            type("Tread carefully… every word, every glance, every clue matters.\n");
            type("Let us begin.\n");
            running = true;
        } else if(choice == "b" || choice == "B" || choice == "no" || choice == "No") {
            choiceMade = true;
            type("\n…Ah. Perhaps the weight of the Grimshire legacy is too much for one soul to bear.\n");
            type("But justice waits for no one, detective.\n");
            type("When you are ready… the manor will still be here.\n");
            running = false;
        } else {
            choiceMade = false;
            type("\nI didn’t quite catch that…\n");
            type("Is it a yes… or a no, detective?\n");
            type("The Grimshires don’t take kindly to indecision…\n");
            cout << endl;
            cout << "Enter your choice: ";
        }
    }

    Suspect Lenora(
        "Lenora Grimshire",
        "is an elegant woman in her early 50s. She has smooth chestnut-brown hair pinned up neatly with sparkling diamond clips. Her blue silk gown matches her sharp green eyes, and she wears long satin gloves. She moves gracefully, always with perfect posture.",
        "After I’d greeted everyone and made my rounds in the ballroom, I began to feel a bit lightheaded… too much champagne, perhaps. Around 1:30, I excused myself and went upstairs to my boudoir. I poured myself a glass of wine and settled in with my book — the music from the ballroom was still faintly drifting up the stairs. I must have dozed off sometime near 2:45. The next thing I remember was waking to shouting in the hall… it was all so sudden and dreadful."
        "I bet it was Damian's best friend. He was even more upset than I was about what happened between my husband and his wife."
    );

    Suspect Jellal(
        "Jellal Vexley",
        "is a charming man in his mid-40s with tanned skin, dark eyes, and black hair streaked with blue highlights. He wears a maroon tuxedo with shiny gold cufflinks. His smile is warm, but his eyes look like he’s always calculating something.",
        "Ah yes, I was in the library lounge most of the night. You know me — once I start telling my travel stories, people tend to linger. We had quite a lively crowd at first, but by about 2:15  they’d all wandered off to the ballroom for a dance. I stayed behind, poured myself another brandy, and settled by the fire to review some business papers I’d brought along. Alfred popped in around 2:40 with a fresh stack of stationery for me — very attentive fellow. Truth be told, I was glad for the quiet… Damian had been particularly charming with the ladies tonight, as he tends to be. Sometimes I think he forgets who his friends are. Still, I didn’t move from that chair until I heard the commotion."
        "I would focus your search onto that butler, I know that had some gripes with him."
    );

    Suspect Alexander (
        "Alexander Grimshire",
        "is a tall, broad-shouldered 28-year-old with dark brown hair neatly styled. He wears a navy suit with a crisp white shirt and a matching tie, though it’s slightly loosened as if he’s restless. He often scans the room like he’s thinking two steps ahead.",
        "Just before two o’clock, I stepped out of the ballroom — there was a confidential business matter that couldn’t wait. I took the call in the upstairs office where it was quieter. The conversation… well, it was delicate, and I needed privacy. Damian’s name came up more than once — certain investors are still furious about the way he handled a recent deal, and I was left cleaning up his mess. I can’t say I wasn’t frustrated; he’s cost me opportunities before. As far as I recall, the call went on right up until three o’clock. I’d barely hung up when I heard the crash — glass shattering, voices shouting. I left the office straightaway and found the whole place in chaos."
        "I know that my father was upset with our chef. He was having a secret relationship with my sister, and my father did not approve of it."
    );

    Suspect Celeste (
        "Celeste Grimshire",
        "is a beautiful 22-year-old with wavy brown hair over one shoulder. She has pale skin, bright green eyes, and wears a light blue silk dress with a high slit. She laughs easily, but her eyes hint at stubbornness and rebellion.",
        "The ballroom? Please… you know I can only take so much of those tedious society types. I slipped into the kitchen not long after dinner and found Dante there — we ended up talking about a new pastry recipe he’s been working on. It was far more interesting than watching half-drunk men stumble through a waltz. We just chatted, sipped some tea… oh, I think I left the kitchen a little before three to fetch my shawl. I’d barely gotten back to my room when I heard the shouting. It was all such a blur after that."
        "I hope no one says me. Sure, I was upset at my father for forcing me to marry that dumbwitted chump, but I would never lay a finger on him."
    );

    Suspect Alfred (
        "Alfred Crane",
        "is a neat and serious man in his late 60s with silver hair and sharp grey eyes. He wears a perfect black butler’s uniform with polished brass buttons and a gold watch chain. He moves quietly and with purpose.",
        "I was on my feet all evening, as you’d expect — making the rounds between the dining room and ballroom, keeping glasses topped up and seeing to the guests’ coats. Around 12:00, once things had settled into their rhythm, I began polishing the silver in the dining room between service rounds. By the time the clock was nearing 3:00, I’d moved on to arranging flowers in the foyer for the morning. That’s when I heard it — the crash, the shouting. I went straight to see what had happened."
        "Damian was always getting into it with that son of his...and you know, I always though Alexander was such a selfish young man for trying to get all of Damian's inheritance. I never heard if he did."
    );

    Suspect Dante (
        "Dante Vermillion",
        "is an Italian man in his early 30s with olive-toned skin, brown eyes, and dark hair swept back. He wears spotless white chef’s clothes and a small silver necklace with a van cleef charm. His hands are strong and a little scarred from years of cooking.",
        "I was in the kitchen for most of the night — plenty to do after the gala supper. Celeste joined me for a bit; we shared tea and talked about some new recipes I’d been working on. She left a little before 3:00, and I stayed behind to finish tidying up. I put away the silver, wiped the counters, made sure everything was ready for breakfast. I didn’t step out until I went to my quarters, just before the shouting started."
        "The other night, Damian's wife found out that he had been cheating on her. I was still at the house, cleaning up from dinner, and boy she was angry."
    );



    // start game loop
    
    cout << endl;
    game.printSuspectIntroduction();
    cout << endl;
    
    // start game loop

    while (running) {
        cout << "\n=== What would you like to do? ===\n";
        cout << endl;
        cout << "A) Go to Foyer\nB) Go to Bedroom\nC) Go to Kitchen\n";
        cout << "D) Go to Office\nE) Go to Library\nF) Talk to Suspects\n";
        cout << "Q) Quit\n";
        cout << endl;
        cout << "Enter your choice: ";
        getline(cin, choice);
        cout << endl;

        //  movement 
        if (choice == "A" || choice == "a") game.move("a");
        else if (choice == "B" || choice == "b") game.move("b");
        else if (choice == "C" || choice == "c") game.move("c");
        else if (choice == "D" || choice == "d") game.move("d");
        else if (choice == "E" || choice == "e") game.move("e");

        // ----------------- Talk to Suspects -----------------
        else if (choice == "F" || choice == "f") {
            char userChoice = game.TalkOptions();  
                if (userChoice == 'a') {
                    game.TalkToSuspect(Lenora);
                }
                else if (userChoice == 'b') {
                    game.TalkToSuspect(Jellal);
                }
                else if (userChoice == 'c') {
                    game.TalkToSuspect(Alexander);
                }
                else if (userChoice == 'd') {
                    game.TalkToSuspect(Celeste);
                }
                else if (userChoice == 'e') {
                    game.TalkToSuspect(Alfred);
                }
                else {
                    game.TalkToSuspect(Dante);
            }    //stores player's selection
        }
        else if (choice == "Q" || choice == "q") {
            cout << "Exiting the game. Goodbye!\n";
            running = false;
        }

        //  invalid input
        else cout << "Invalid choice. Try again.\n";
    }
    return 0;
}