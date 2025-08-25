#include "Type.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void type(const string& text, int speed) {
    for (unsigned int i = 0; i < text.length(); i++) {
        cout << text[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
}
