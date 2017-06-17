#include <iostream> //standard input / output streams
#include <iomanip>  //IO manipulators

using namespace std;

int main() {
    int r, c;
    int martix[4][3] = {
            {-1, 7,  1},
            {3,  4,  -1},
            {1,  3,  5},
            {6,  -3, 1}
    };
    //outer loop
    for (r = 0; r < 3; r++) {
        //cout << " i is " << i <<endl << "========" << endl;
        int sum = 0;
        //inner loop
        for (c = 0; c < 4; c++) {

            cout << martix[r][c] << endl;
            //sum = sum+ martix[i][j];
            //cout << setw(10) << " The sum is " << sum <<endl;
            //cout << " j is " << j << endl;
        }
        cout << endl;
    }

    return 0;
}