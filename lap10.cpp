#include <iostream> //standard input / output streams

using namespace std;

class ClockType {
public :

    /**Function to set the time.
     * The time is set according to the parameters.
     * Post condition: hr = hours; min = minutes; sec= seconds;
     * The function checks whether the values of hours, minutes, or seconds are valid. If a value is invalid, the
     * default value 0 is assigned.
     * */
    void setTime(int, int, int);

    /**
     * Function to return the time
     * Postcondition: hours = hr; minutes = min; seconds = sec;
     */
    void getTime(int &, int &, int &) const;

    /**
     * Function to print the time.
     * Postcondition: The time is printed in the form - hh:mm:ss
     */
    void printTime() const;

    /**
     * Function to increment the time by one second.
     * Postcondition: The time is incremented by one second. If the before-increment time is 23:59:59, the time is
     * reset to 00:00:00.
     */
    void incrementSeconds();

    /**
     * Function to increment the time by one minute.
     * Postcondition: The time is incremented by one minute. If the before-increment time is 23:59:53, the time is
     * reset to 00:00:53.
     */
    void incrementMinutes();

    /**
     * Function to increment the time by one hour. If the
     * Postcondition: The time is incremented by one hour. If the before-increment time is 23:45:53, the time is reset
     * to 00:45:53.
     */
    void incrementHours();

    /**
     * Function to compare the two times.
     * Postcondition: Returns true if this time is equal to otherClock;
     * otherwise, returns false.
     * @return True or False
     */
    bool equalTime(const ClockType &) const;

private:
    int hr;
    int min;
    int sec;
};

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

void ClockType::setTime(int hours, int minutes, int seconds) {
    if (0 <= hours && hours < 24) {
        hr = hours;
    } else {
        hr = 0;
    }
    if (0 <= minutes && minutes < 60) {
        min = minutes;
    } else {
        min = 0;
    }
    if (0 < seconds && seconds < 60) {
        sec = seconds;
    } else {
        sec = 0;
    }
}

void ClockType::getTime(int &hours, int &minutes, int &seconds) const {
    hours = hr;
    minutes = min;
    seconds = sec;
}

void ClockType::printTime() const {
    if (hr < 10) {
        cout << "0";
    }
    cout << hr << " : ";
    if (min < 10) {
        cout << "0";
    }
    cout << min << " : ";
    if (sec < 10) {
        cout << "0";
    }
    cout << sec << " : ";
}

void ClockType::incrementHours() {
    hr++;
    if (hr > 23) {
        hr = 0;
    }
}

void ClockType::incrementMinutes() {
    min++;
    if (min > 59) {
        min = 0;
        incrementHours();
    }
}

void ClockType::incrementSeconds() {
    sec++;
    if (sec > 59) {
        sec = 0;
        incrementMinutes();
    }
}

bool ClockType::equalTime(const ClockType &otherClock) const {
    return (hr == otherClock.hr &&
            min == otherClock.min &&
            sec == otherClock.sec);
}