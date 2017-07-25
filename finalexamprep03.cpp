#include <iostream>

using namespace std;

struct Student {
    int id;
    string fname;
    string lname;
};

int main() {
    Student joe;
    joe.fname = "Joe";
    joe.lname = "Mel";
    joe.id = 1001;

    cout << joe.fname << " " << joe.lname << " " << joe.id << endl;
    return 0;
}