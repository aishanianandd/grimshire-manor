[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/DM7iZNjj)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=20043151)
# The Grimshire Manor
 
 > Authors: [Ashita Srinivasmurthy](https://github.com/ashita-816), [Rian McCreery](https://github.com/hmccr001), [Aishani Anand](https://github.com/aishanianandd), [Kesia Fernandes](https://github.com/kcafernandes)

## Project Description
### Murder Mystery RPG – Text-Based Game

Our project is a text-based murder mystery game set in Grimshire Manor, where the player takes on the role of a detective investigating the suspicious death of Damian Grimshire. The goal is to uncover the truth by interviewing suspects, exploring rooms, and piecing together clues to identify the killer.

We developed this project in C++ using VSCode, with all gameplay taking place in the terminal. To create an atmosphere in the terminal, we use ASCII art and bold, italics, and color text effects. Players interact by typing input, choosing which suspects to interrogate, which rooms to investigate, and when to make their final accusation.

### Features

- Interactive suspect interviews with unique motives and alibis

- ASCII art and styled text for an immersive experience

- Multiple explorable locations with interactive NPCs

- Collection of clues and statements to aid deduction

- Accusation system that lets the player decide on the murderer

---

### Why is it important or interesting to us?

> We grew up enjoying mystery stories and detective games and this project gave us the chance to recreate that experience with our own style. By building it ourselves, we could focus on our narrative and on the mechanics of a standard murder mystery game. Our goal is to give players the thrill of solving a case in an interactive environment.

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
  

#### Suspects:
>- Each Suspect has a name, role, alibi, and dialogue options
  

#### Clues:
>- Each clue has information such as where it was found and who it implicates or supports


#### Actions Available to the Player

>- **Investigate** the current location for clues
>- **Talk** to Suspects using multiple dialogue options
>- **Move** to a different location
>- **Analyze** the collected clues and suspect info
>- **Accuse** a suspect
  

#### Win/Lose Conditions

>- Player must guess who the murderer is
>- Game ends if the player guesses correctly or incorrectly
>- Player may also lose if they run out of turns
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
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > To run The Grimshire Manor, clone this GitHub repository on any Linux-based terminal with support for git and make. Then, use the following commands:
>
```bash
make clean
make
./game
```
## Testing
 > We tested our project using unit tests, using the **GoogleTest** framework (included as a submodule). All test files are located in the `tests` directory, with each `.cpp` file dedicated to testing a specific class or module, and we use CMake to configure the build and run all tests.
> 
> To build and run all tests, use the following commands:

```bash
mkdir -p build
cd build
cmake ..
./build/runtests
```
 
