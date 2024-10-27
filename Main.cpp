//Anthony Sarabia
//
#include <iostream>          
#include <chrono>            
#include <vector>            
#include <list>              
#include <set>               
#include <fstream>           
#include <string>            
#include <iomanip>          
#include <algorithm>         // For std::sort
using namespace std;
using namespace std::chrono; 

//CONSTANTS
// Constants
const string FILENAME = "codes.txt";     // Name of the input file containing codes
const int NUM_ELEMENTS = 20000;         // Total number of elements to process
const string INSERT_VALUE = "TESTING";  // Value to insert into data structures

//Function Prototypes
long long sortList(list<string>& l);
long long sortVector(vector<string>& v);
long long readSet(set<string>& s);
long long readList(list<string>& l);
long long readVector(vector<string>& v);
long long insertVector(vector<string>& v);
long long insertList(list<string>& l);
long long insertSet(set<string>& s);
long long deleteVector(vector<string>& v);
long long deleteList(list<string>& l);
long long deleteSet(set<string>& s);


int main() {

    //Conatiners

    //Table

    //store timing results here for each structure/operation

    //read

    //sort

    //insert

    //delete

    //output 

    return 0;
}

//FUNCTION BODIES
long long sortList(list<string>& l) {

}
long long sortVector(vector<string>& v) {

}
long long readSet(set<string>& s) {

    //local variables
    string line;
    int count = 0;
    auto start = high_resolution_clock::now(); // Record the start time of the read operation
    ifstream infile(FILENAME);

}
long long readList(list<string>& l) {

}
long long readVector(vector<string>& v) {
    //local variables
    string line;
    int count = 0;
    auto start = high_resolution_clock::now(); // Record the start time of the read operation
    ifstream infile(FILENAME);

    //file validation
    if (!infile.is_open()) {
        // If the file cannot be opened, display an error message and exit
        cout << "Error: Unable to open file " << FILENAME << " for vector.\n";
        exit(1);
    }

    //create a loop until all elements have been read, the insert line to vector using push_back

    while (count < NUM_ELEMENTS) {

        v.push_back(line); //push back into vector here
    }


    //close file
    infile.close();

   //end time of the read operation
    auto end = high_resolution_clock::now();

    // calculate the duration 
    auto duration = duration_cast<microseconds>(end - start).count();

    return duration;
}
long long insertVector(vector<string>& v) {

}
long long insertList(list<string>& l) {

}
long long insertSet(set<string>& s) {

}
long long deleteVector(vector<string>& v) {

}
long long deleteList(list<string>& l) {

}
long long deleteSet(set<string>& s) {

}

