[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/DM7iZNjj)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=20043151)
# Murder Mystery
 
 > Authors: [Ashita Srinivasmurthy](https://github.com/ashita-816), [Rian McCreery](https://github.com/hmccr001), [Aishani Anand](https://github.com/aishanianandd), [Kesia Fernandes](https://github.com/kcafernandes)

> ## Project Description
 > Our text-based role playing game will have a murder mystery theme, where the player will take on the role of a detective. 

### Murder Mystery RPG – Text-Based Game

A text-based role-playing game made in C++ where the player assumes the role of a detective solving a murder case through exploration and logical reasoning.

---

### Why is it important or interesting to us?

> It’s fun to build and easy to demo since text-based means we can focus more on logic and systems instead of graphics.  
>
> It also mixes storytelling with problem-solving where we can prioritize creativity in writing a compelling narrative, while also improving our software developing skills and gaining more experience.

---

### Tools and Technologies Used

- Language: C++ 
- CMake / Make / g++ / clang++ for compilation
- GitHub & Scrum Board for collaboration
- GoogleTest for unit testing
- Valgrind for debugging

---

### Input / Output

#### Input:
- Player uses commands like `investigate`, `talk`, `switch locations`, and `analyze`.
- Choices and interactions are input to progress through the game.

#### Output:
- Description of locations and characters
- Menu of possible actions (inputs)
- Inventory of clues and suspect info
- Win/Lose screen

---

### What are the features that the project provides?


#### Environment:
>- Multiple locations to visit
>- Each location includes interactive NPCs, clues, and items
  

#### Characters:
>- Each NPC (non-player character) has a name, role, alibi, and dialogue options
  

#### Clues:
>- Each clue has information such as where it was found and who it implicates or supports


#### Actions Available to the Player

>- **Investigate** the current location for clues
>- **Talk** to NPCs using multiple dialogue options
>- **Move** to a different location
>- **Analyze** the collected clues and suspect info
>- **Accuse** a suspect
  

#### Win/Lose Conditions

>- Player must guess who the murderer is
>- Game ends if the player guesses correctly or incorrectly
>- Player may also lose if they run out of time or turns
>
>
---
## User Interface Specification

### Navigation Diagram
> <img width="1183" height="564" alt="Screenshot 2025-08-20 at 12 29 19 PM" src="https://github.com/user-attachments/assets/1a94289b-ec47-41c1-8b47-7a6ac201ceb8" />

### Screen Layouts
> Click [here](https://docs.google.com/document/d/1NH2fJ62OaL5OKfC7YfcQBNCQ8bFwoK7yt_qhrNwcQig/edit?usp=sharing) to view screen layouts.

## Class Diagram
> <img width="3040" height="1984" alt="Class Diagram" src="https://github.com/user-attachments/assets/bbc074f2-64bf-4593-a814-cf0648efa4b4" />

## SOLID Principles

Single Responsibility Principle (SRP)

We applied SRP by splitting the game into focused classes like Game, Location, Action, NPC, and Clue, each handling only one responsibility.
This helped because each class became simpler to test, and changing one behavior (like dialogue) didn’t break unrelated parts of the game.

Open/Closed Principle (OCP)

We applied OCP by introducing abstract classes (Action, Location) so we can add new commands or rooms without modifying existing code.
This helped because new features could be added as subclasses instead of editing the core game logic, reducing the chance of bugs.

Liskov Substitution Principle (LSP)

We applied LSP by ensuring that all subclasses (Talk, Move, Investigate, etc.) follow the same Action interface, and all room types extend Location.
This helped because the Game can treat all actions and rooms the same way, making the system flexible and consistent.

Interface Segregation Principle (ISP)

We applied ISP by keeping interfaces small, like Action only having execute() and name(), and Location exposing only what actions need.
This helped because no class was forced to implement unused methods, which kept the design cleaner and easier to extend.

Dependency Inversion Principle (DIP)

We applied DIP by making the Game depend on abstractions (Action, Location) instead of concrete subclasses.
This helped because new actions or rooms can be swapped in without changing the game loop, keeping the code stable and testable.
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
