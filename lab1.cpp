/**
    Course: CSC211(4104)
    Filename : lab1.cpp
    Purpose: Ask the user to enter 10 numerical values, and then prompt the inserted values with the total sum

    @author Suresh Melvin Sigera
    @date 06/07/2017
*/

#include <iostream> //standard input / output streams

using namespace std;

int main() {
    int values[10];
    int sum = 0;

    cout << "Please enter the 10 numerical values to calculate the total" << endl;

    //ask the user to enter the 10 numerical values.
    for (int i = 0; i < 10; i++) {
        cin >> values[i];
    }

    cout << "The input values are : " << endl;

    //print the inserted values while calculating the sum of the total.
    for (int i = 0; i < 10; i++) {
        cout << " " << values[i];
        sum += values[i];
    }

    //prompt the sum
    cout << endl << "The sum is : " << sum;

    return 0;
}//end main function