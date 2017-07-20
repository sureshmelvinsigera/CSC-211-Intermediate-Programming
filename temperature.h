#include <iostream> //standard input / output streams
#include <fstream>  //file streams

using namespace std;

class Temperature {
public:
    /**Function to Read the first record in the file, based on that value,allocate the pointer array, and read all the
     * values.
     * Precondition *temperature is set to NULL.
     * Postcondition call getAverage method after finish reading the file.
     * */
    void readFile();

    /**Function to read all the values stored in the *temperature and print out its average.
     * Precondition *temperature should contain all the values from the files. The pointer should be read only.
     * Postcondition add all the records and divide by number of record to find the average,and print average.
    * */
    void getAverage(const int *ptr);

private:
    int *temperature = NULL;
    int numDays;
    double average;
};