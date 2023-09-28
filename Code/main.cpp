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
    #include <windows.h>
#endif

void SetInterval(std::function<void(void)> function, int interval) {
    std::thread th([&]() {
        while(true) {
            sleep(interval);
            function();
        }
    });

    th.detach();
}

bool on;
int hz;

int main() {
    std::cout << "Welcome to the Hunga-8!" << std::endl;
    hz = 10;

    SetInterval(nullptr, 1000 / hz);

    while (on) {
        
    }

    return 0;
}