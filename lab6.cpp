#include <iostream> //standard input / output streams
#include <iomanip>  //IO manipulators
#include <fstream>  //file streams

using namespace std;

int main() {
    const int max_records = 15;
    int number_of_students = 25;
    int number_of_exams = 5;
    int record_index = 0;
    int score = 0;
    float std_grades[number_of_students][number_of_exams];
    string std_names[number_of_students];
    string lg[number_of_students];
    ifstream inFile;

//    cout << "Enter the number of students : "  << endl;
//    cin >> number_of_students;
//    cout << "Enter the number of exams : " << endl;
//    cin >> number_of_exams;

    inFile.open("grades.txt");
    if (inFile.is_open()) {
        //cout << endl << "File is open";
        while (!inFile.eof()) {
            inFile >> std_names[record_index];
            for (int e = 0; e < number_of_exams; e++) {
                inFile >> std_grades[record_index][e];
            }
            record_index++;
        }
        inFile.close();
        //cout << endl << "File is closed" << endl;
        //process the grades for each student
        for (int i = 0; i < record_index; i++) {
            score = 0;
            for (int j = 0; j < number_of_exams; j++) {
                score += std_grades[i][j] / number_of_exams;
            }
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
        cout << setw(15) << left << "Name" << setw(38) << right << "Test Scores" << setw(36) << "Letter Grade" << endl;
        for (int i = 0; i < number_of_students; i++) {
            cout << left << setw(36) << std_names[i];
            for (int e = 0; e < number_of_exams; e++) {
                cout << setw(5) << std_grades[i][e];
            }
            cout << setw(20) << " " << left << setw(20) << lg[i] << endl;
        }
    } else {
        cerr << endl << "Cannot open the file";
        exit(EXIT_FAILURE);
    }
}//end main function