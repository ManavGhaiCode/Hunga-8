/*

* This is an emulator so things might not match up if you build this in Hardware.
* Have fun looking at my code. Kindly review my code, If you have the time!

* One more thing this is made with GCC and std is C++ 17

*/

#include <iostream>
#include <functional>
#include <thread>

#include "../Common/Instructions.h"
#include "./Memory.h"

#ifdef __linux__
    #include <unistd.h>
#elif _WIN32 || _WIN64
    #include "./usleep.h"
#endif

bool on = true;
int hz = 1;

void foo() {
    std::cout << "Hello World!" << std::endl;
}

int main() {
    std::cout << "Welcome to the Hunga-8!" << std::endl;
    hz = 10;

    while (on) {
        foo();
        usleep(1000000 / hz);
    }
}