/**
    Course: CSC211(4104)
    Filename : lab3.cpp
    Requried : lab3.txt
    Purpose: Read values from lab3.txt and then prompt values with the total sum.
    @author Suresh Melvin Sigera
    @date 06/07/2017
*/

#include <iostream>//standard input / output streams
#include <fstream>//file streams

using namespace std;

int main() {
    int values;
    int sum = 0;
    ifstream inFile;
    inFile.open("lab3.txt");

    if (inFile.is_open()) {
        //cout << "File is open";
        while (!inFile.eof()) {
            inFile >> values;
            sum += values;
            cout << values << endl;
        }
        cout << "The sum is " << sum;
        inFile.close();
    } else {
        cerr << "Cannot open the file" << endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}//end main function
