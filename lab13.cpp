/**
    Course: CSC211(4104)
    Filename : lab13.cpp
    Requried : temperature.txt
    Purpose: Read the list of values (temperature) from the file and assign it to a dynamic int pointer and then
    calculate the average of all the values
    @author Suresh Melvin Sigera
    @date 07/17/2017
*/
#include <iostream> //file streams
#include "temperature.h" //user defined temperature class

using namespace std;

int main() {
    Temperature weather;
    weather.readFile();
}