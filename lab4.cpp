/**
    Course: CSC211(4104)
    Filename : lab1.cpp
    Requried : giftPrices.txt
    Purpose: Read the gift name, and price, and rating from a text file. Then prompt the products with its name, price,
    and rating.
    @author Suresh Melvin Sigera
    @date 06/07/2017
*/

#include <iostream> //standard input / output streams
#include <iomanip>  //IO manipulators
#include <fstream>  //file streams

using namespace std;

bool highlyRated(double);

int main() {
    int tn_records = 0; // total number of records
    int tn_highly_rated_gifts = 0; // total number of records highly rated gifts
    int request;
    string giftname;
    string status = "No"; //default we set the status to NO
    double giftprice = 0.00;
    double rating = 0.00;

    ifstream inFile;
    inFile.open("giftPrices.txt");

    if (inFile.is_open()) {
        //cout << "File is open " << endl;
        cout << "GIFTS" << setw(20) << "PRICE" << setw(30) << "HIGHLY RATED" <<endl;
        cout << setfill('-') << setw(60) << "-" << endl;

        while (!inFile.eof()) {
            inFile >> giftname >> giftprice >> rating;
            cout << setfill(' ');
            request = highlyRated(rating);
            //setting up the rating status
            if (request == 0) {
                status = "NO";
            } else {
                status = "YES";
                tn_highly_rated_gifts++;
            }
            cout << setw(15)<< left << giftname << right << setw(10) << setprecision(4) << giftprice << setw(25) << status << endl;
            // computing the total number of gifts in that are on the file.
            tn_records++;
        }
        cout << endl << endl;
        cout << "There are " << setw(2) << tn_records << " on the list." << endl;
        cout << "There are " << setw(2) << tn_highly_rated_gifts << " gifts with 5 stars on the list." << endl;
        inFile.close();
    } else {
        cerr << "Cannot open the file." << endl;
        exit(EXIT_FAILURE);
    }
}


/**
 * @brief Return true if the item has 4 or more stars and false otherwise.
 * @param rating Type bool
 * @return true or false
 * @date June 8th, 2016
 * @author Suresh Melvin Sigera
 */
bool highlyRated(double rating) {
    if (rating >= 4)
        return true;
    else
        return false;
}