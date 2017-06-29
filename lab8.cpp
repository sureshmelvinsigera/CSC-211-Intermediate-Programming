/**
Course: CSC211(4104)
Filename : lab8.cpp
Purpose: Ask the user the input two hex decimal values and output the sum.
@author Suresh Melvin Sigera
@date 06/15/2017
*/

#include <iostream> // library that contain basic input/output functions
#include <cstring>  // to manipulate C strings and arrays
#include <math.h>   // to compute common mathematical operations and transformations

using namespace std;

int hex_to_int(char *const, int);

int main() {

    char *hex_value = new char[0];
    int counter = 0;
    int hex_sum = 0;
    int user_inputs = 2;

    // ask the user to input two hex numbers
    do {
        cout << "Please enter the Hex value ";
        cin >> hex_value;
        //call the hex_to_int function
        hex_sum += hex_to_int(hex_value, strlen(hex_value));
        counter++;
    } while (counter != user_inputs);

    cout << "Sum is " << hex_sum;

    return 0;
}

/**
 * @brief Return decimal equivalent of the hex value.
 * @param hex Type const int, length Type int
 * @return int
 * @date June 15th, 2016
 * @author Suresh Melvin Sigera
 * */
int hex_to_int(char *const hex, int length) {
    int decimal = 0;
    length = length - 1;

    for (int i = length; i >= 0; i--) {
        int pos = length;
        if (hex[i] >= 48 && hex[i] <= 57) { //between 0-9
            decimal += (hex[i] - 48) * pow(16, (pos - i));
            //cout << hex[i] << " " << decimal  << endl;
        } else if (hex[i] >= 65 && hex[i] <= 70) {  //between A-F
            decimal += (hex[i] - 55) * pow(16, (pos - i));
            //cout << hex[i] << " " << decimal << endl;;
        } else if (hex[i] >= 97 && hex[i] <= 102) {  //between a-f
            decimal += (hex[i] - 87) * pow(16, (pos - i));
            //cout << hex[i] << " " << decimal << endl;
        }
        //cout << hex[i] << " * " << (pos - i) << " " << decimal << endl;
    }
    return decimal;
}