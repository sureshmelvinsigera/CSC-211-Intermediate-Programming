#include <iostream> //standard input / output streams
#include <fstream>  //file streams
#include <iomanip>  //parametric manipulators
#include <string>

using namespace std;

class bookType {

public:

    //sets the bookTitle to  s
    void setBookTitle(string s);

    //sets the private member bookISBN to the parameter
    void setBookISBN(string ISBN);

    //sets the private member bookPrice to cost
    void setBookPrice(double cost);

    //sets the private member copiesInStock to noOfCopies
    void setCopiesInStock(int noOfCopies);

    //prints the bookTitle, bookISBN, the bookPrice and the copiesInStock
    void printInfo() const;

    //adds addBooks to the quantityInStock, so that the quantity in stock now has it original value plus the parameter
    // sent to this function
    void updateQuantity(int addBooks);

    //returns the bookISBN
    string getBookISBN() const;

    //returns the bookPrice
    double getBookPrice() const;

    //returns the quantity in stock
    int showQuantityInStock() const;

    void readData();

    void showMenu();

private:

    string bookName;

    string bookISBN;

    double price;

    int quantity;

};

int main() {
    bookType books[100];
    //books->readData();
    //books->showMenu();

    string bookName;
    string bookISBN;
    double price;
    int quantity;
    int records;

    ifstream inFile;
    inFile.open("bookdata.txt");

    if (inFile.is_open()) {
        while (!inFile.eof()) {
            inFile >> bookName >> bookISBN >> price >> quantity;
            books[records].setBookTitle(bookName);
            books[records].setBookPrice(price);
            books[records].setBookISBN(bookISBN);
            books[records].setCopiesInStock(quantity);
            records++;
        }
    } else {
        cerr << endl << "Cannot open the file ";
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<records; i++){
        cout << "["<<i+1<<"]" << "book" << endl;
        books[i].printInfo();
        cout << "-----" <<endl;
    }
}

void bookType::showMenu() {
    char input;

    cout << setw(15) << left << "Welcome to the Staten Island Bank" << endl;
    do {
        cout << endl << "P) printInfo";
        cin >> input;

        if(input== 'p' || input == 'P'){
            printInfo();
        }

    } while (input != 'Q' || input != 'q');
}

void bookType::readData() {
    int records;
    ifstream inFile;
    inFile.open("bookdata.txt");

    if (inFile.is_open()) {
        while (!inFile.eof()) {
            inFile >> bookName >> bookISBN >> price >> quantity;
            ++records;
        }
    } else {
        cerr << endl << "Cannot open the file ";
        exit(EXIT_FAILURE);
    }
}

double bookType::getBookPrice() const {
    return price;
}

string bookType::getBookISBN() const {
    return bookISBN;
}

int bookType::showQuantityInStock() const {
    return quantity;
}

void bookType::updateQuantity(int addBooks) {
    quantity += addBooks;
}

void bookType::printInfo() const {
    cout << "Book Name " << bookName << endl;
    cout << "Book ISBN " << bookISBN << endl;
    cout << "Book Price " << price << endl;
    cout << "In stock "<< quantity << endl;
    cout << endl;
}

void bookType::setCopiesInStock(int noOfCopies) {
    quantity += noOfCopies;
}

void bookType::setBookTitle(string s) {
    bookName = s;
}

void bookType::setBookISBN(string ISBN) {
    bookISBN = ISBN;
}

void bookType::setBookPrice(double cost) {
    price = cost;
}


