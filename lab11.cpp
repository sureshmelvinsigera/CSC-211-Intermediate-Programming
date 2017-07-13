/**
    Course: CSC211(4104)
    Filename : lab11.cpp
    Requried : temperature.txt
    Purpose: Read the list of values (temperature) from the file and assign it to a dynamic int pointer and then
    calculate the average of all the values
    @author Suresh Melvin Sigera
    @date 07/13/2017
*/


#include <iostream> //standard input / output streams
#include <fstream>  //file streams

using namespace std;

int main() {

    int *temperature;
    int numDays;
    double average = 0;

    ifstream inFile;
    inFile.open("temperature.txt");

    if (inFile.is_open()) {
        while (!inFile.eof()) {
            inFile >> numDays;
            temperature = new int[numDays];
            for (int i = 0; i < numDays; i++) {
                inFile >> temperature[i];
            }
        }
        for (int i = 0; i < numDays; i++) {
            cout << temperature[i] << " ";
            average += temperature[i];
        }
        cout << endl << "Average is " << average / numDays;

    } else {
        cerr << "Cannot read the file";
        exit(EXIT_FAILURE);
    }
    return 0;
}