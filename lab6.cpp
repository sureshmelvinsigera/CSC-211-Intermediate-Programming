#include <iostream> //standard input / output streams
#include <iomanip>  //IO manipulators
#include <fstream>  //file streams

using namespace std;

int main() {
    const int max_records = 15;
    int number_of_students = 25;
    int number_of_exams = 5;
    int record_index = 0;
    string std_names[number_of_students];
    float std_grades[number_of_students][number_of_exams];
    ifstream inFile;

//    cout << "Enter the number of students : ";
//    cin >> number_of_students;
//    cout << endl << "Enter the number of exams : ";
//    cin >> number_of_exams;

    inFile.open("grades.txt");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            inFile >> std_names[record_index];
            for (int e = 0; e < number_of_exams; e++) {
                inFile >> std_grades[record_index][e];
                //cout << endl << std_names[record_index] << " " << std_grades[record_index][e];
            }
            record_index++;
        }
        inFile.close();
//        for(int i=0; i<number_of_students; i++){
//            cout<< endl << std_names[i];
//            for(int j=0; j<number_of_exams; j++){
//                cout<< i << j;
//            }
//        }
    } else {
        cerr << endl << "Cannot open the file";
        exit(EXIT_FAILURE);
    }
}