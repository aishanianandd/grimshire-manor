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


 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.``
 >   * Break down the "Epics" into smaller actionable user stories. Convert them into issues and assign them to team members. Place these in the `Sprint Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Each team member needs to submit the Peer Evaluation Form on Canvas for this phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase  II, and a description of their contributions. Remember that each team member should submit the form individually.
 > * Schedule two check-ins using Calendly. Both time slots should be during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from the User Interface Design Document Template of CMSC 345 at the University of Maryland Global Campus)

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). Nodes represent the different screens in your program and arrows represent the way to navigate from one screen to another. It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs and expected output, or any graphical user interface components if applicable (e.g. buttons, text boxes, etc). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram
> <img width="3040" height="1984" alt="Class Diagram" src="https://github.com/user-attachments/assets/bbc074f2-64bf-4593-a814-cf0648efa4b4" />

 
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
 
