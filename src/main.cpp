#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

// made a function to type slowly like a typewriter, instead of the speedy cout
// makes it more ominous..? suspensful..? trust
void type(string text, int speed = 30){
    for(int i = 0; i < text.length(); i++){
        cout << text[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
}

int main(){}