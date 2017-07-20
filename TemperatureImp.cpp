#include <iostream> //standard input / output streams
#include "temperature.h"    //custom header file

/**
 * @details Read the first record in the file, based on that value,allocate the pointer array, and read all the values.
 * and all the getAverage method.
 * @author Suresh Melvin Sigera
 */
void Temperature::readFile() {
    ifstream inFile;
    inFile.open("temperature.txt");

    if (inFile.is_open()) {
        //cout<<"File is open";
        while (!inFile.eof()) {
            inFile >> numDays; //first read the number of records.
            temperature = new int[numDays]; //based number of records allocate the pointer array.
            for (int i = 0; i < numDays; i++) {
                inFile >> temperature[i]; //read all the values.
            }
        }
        getAverage(temperature); //call the getAverage method.
        inFile.close(); //close the file.
    } else {
        cerr << "Cannot read the file";
        exit(EXIT_FAILURE);
    }
}

/**
 * @details getAverage function calculate the all the values stored in the *temperature and print out its average.
 * @author Suresh Melvin Sigera
 * @param ptr
 */
void Temperature::getAverage(const int *ptr) {
    for (int i = 0; i < *ptr; i++) {
        cout << *ptr << " ";
        ptr++;
        average += (double) *ptr;
    }
    cout << endl << "The Average is " << average;
}