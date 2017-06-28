/**
    Course: CSC211(4104)
    Filename : lab7.cpp
    Requried : grades2.txt
    Purpose: Read 20 student records from the file (first name, last name and five grades). Then print
    student first name, last name test, five test scores with the letter grade for each student.
    @author Suresh Melvin Sigera
    @date 06/07/2017
*/

#include <iostream> //standard input / output streams
#include <iomanip>  //IO manipulators
#include <fstream>  //file streams

using namespace std;

int main() {

    int const MAX_RECORDS = 20;

    int number_of_exams = 5;
    int record_index = 0;
    int score = 0;

    string lg[MAX_RECORDS];

    struct Student_Type {
        string StudentFirstName;
        string StudentLastName;
        int grades[5];
    };

    Student_Type student[MAX_RECORDS];

    ifstream inFile;

    inFile.open("grades2.txt");

    //cout << "File is open";
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            inFile >> student[record_index].StudentFirstName >> student[record_index].StudentLastName;
            for (int j = 0; j < number_of_exams; j++) {
                inFile >> student[record_index].grades[j];
            }
            record_index++;
        }
        //cout << "File is close" << endl;
        inFile.close();

        //process the grades for each student
        for (int i = 0; i < record_index; i++) {
            //reset the score
            score = 0;
            for (int j = 0; j < 5; j++) {
                score += student[i].grades[j] / number_of_exams;
            }
            //cout << score << endl;
            if (score <= 100 && score >= 97) {
                lg[i] = "A+";
            } else if (score <= 96 && score >= 93) {
                lg[i] = "A";
            } else if (score <= 92 && score >= 90) {
                lg[i] = "A-";
            } else if (score <= 89 && score >= 87) {
                lg[i] = "B+";
            } else if (score <= 86 && score >= 83) {
                lg[i] = "B";
            } else if (score <= 82 && score >= 80) {
                lg[i] = "B-";
            } else if (score <= 79 && score >= 77) {
                lg[i] = "C+";
            } else if (score <= 76 && score >= 73) {
                lg[i] = "C";
            } else if (score <= 72 && score >= 70) {
                lg[i] = "C-";
            } else if (score <= 69 && score >= 67) {
                lg[i] = "D+";
            } else if (score <= 66 && score >= 65) {
                lg[i] = "D-";
            } else if (score < 65) {
                lg[i] = "F";
            }
        }
        //print all the records
        cout << setw(15) << left << "Name" << setw(38) << right << "Test Scores" << setw(36) << "Letter Grade" << endl;
        for (int i = 0; i < record_index; i++) {
            cout << left << setw(10) << student[i].StudentFirstName << left << setw(32) << student[i].StudentLastName;
            for (int j = 0; j < number_of_exams; j++) {
                cout << setw(5) << student[i].grades[j];
            }
            cout << setw(10) << " " << left << setw(20) << lg[i];
            cout << endl;
        }
    } else {
        cerr << "Cannot open the file";
        exit(EXIT_FAILURE);
    }

    return 0;

}//end main