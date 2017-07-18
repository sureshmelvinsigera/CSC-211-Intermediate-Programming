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