#include <iostream>
#include "clockType.h"

int main() {
    ClockType myClock;
    ClockType yourClock;

    myClock.setTime(5, 4, 30);
    cout << "myClock" << endl;
    myClock.printTime();
    cout << endl;
    cout << "Your Clock" << endl;
    yourClock.setTime(5, 4, 30);
    yourClock.printTime();

    if (myClock.equalTime(yourClock)) {
        cout << endl << "Both times are equal";
    } else {
        cout << endl << "Both time are not equal";
    }
}