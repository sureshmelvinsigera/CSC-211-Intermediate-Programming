/**
    Course: CSC211(4104)
    Filename : lab2.cpp
    Purpose: Ask the user to enter 10 numerical values, and then prompt the inserted values with the total sum.

    @author Suresh Melvin Sigera
    @date 06/07/2017
*/

#include <iostream>//standard input / output streams

using namespace std;

int main() {
    int matrix[5][2];
    int sum = 0;

    cout << "Please enter the 10 numbers " << endl;

    //ask the user to enter the 10 numerical values.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> matrix[j][i];
        }
    }

    //print the inserted values while calculating the sum of the total.
    cout << "The 10 numbers are : " << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[j][i] << ' ';
            sum += matrix[j][i];
        }
        cout << endl;
    }

    //prompt the sum
    cout << "The sum of 10 numbers is " << sum << endl;

    return 0;
}//end main function
