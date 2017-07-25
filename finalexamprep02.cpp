#include <iostream>

using namespace std;

int main() {
    int x = 10;
    int *ptr;
    int j[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *jptr;

    cout << "x is " << x << endl;

    ptr = &x;

    cout << "address of x is " << ptr << endl;

    *ptr = 24;

    cout << "Value of x is " << x << endl;

    jptr = j;

    cout << " address of j index 0" << &j[0] << endl;
    cout << jptr << endl;

    cout << (jptr == &j[0]) << endl;

    cout << "Print the full array " << endl;

    for (int i = 0; i < 10; i++) {
        cout << jptr << " " << *jptr << endl;
        jptr++;
    }

    return 0;
}