#include "Type.h"
#include <iostream>
#include <thread>
#include <chrono>

void type(const std::string& text, int speed) {
    for (std::size_t i = 0; i < text.length(); ++i) {
        std::cout << text[i] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(speed));
    }
}
