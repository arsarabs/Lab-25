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
void display(const vector<string>& operation, 
    const vector<long long>& vectorTimes,
    const vector<long long>& listTimes, 
    const vector<long long>& setTimes);

int main() {

    //Conatiners
    vector<string> v;
    list<string> l;
    set<string> s;

    //Table
    vector<string> operations = { "Read", "Sort", "Insert", "Delete" };

    //store timing results here for each structure/operation
    vector<long long> vectorTimes(4, 0);
    vector<long long> listResult(4, 0);
    vector<long long> setResult(4, 0);

    //read
    vectorTimes[0] = readVector(v);
    listResult[0] = readList(l);
    setResult[0] = readSet(s);
    //sort
    vectorTimes[1] = sortVector(v);
    listResult[1] = sortList(l);
    setResult[1] = -1; // this lets us know sort time not applicaable
    //insert
     
    vectorTimes[2] = insertVector(v);
    listResult[2] = insertList(l);
    setResult[2] = insertSet(s);

    //delete
    vectorTimes[3] = deleteVector(v);
    listResult[3] = deleteList(l);
    setResult[3] = deleteSet(s);
    //output
    // 
    display(operations, vectorTimes, listResult, setResult); 

    return 0;
}

//FUNCTION BODIES
long long sortList(list<string>& l) {
    // Record the start time of the sort operation
    auto start = high_resolution_clock::now();

    //WORK HERE: we can use the sort-list member function
    l.sort();

    // Record end time of the sort operation
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start).count();

    return duration; 
}
long long sortVector(vector<string>& v) {
    // Record the start time of the sort operation
    auto start = high_resolution_clock::now();

    //WORK HERE: the only difference when sorting a vector is using a simple algorithm
    sort(v.begin(), v.end());


    // Record end time of the sort operation
    auto end = high_resolution_clock::now();


    auto duration = duration_cast<microseconds>(end - start).count();

    return duration; 
}
long long readSet(set<string>& s) {
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
    while (count < NUM_ELEMENTS) {
        if (!getline(infile, line)) {
            // If EOF is reached, clear the EOF flag and reset the file pointer to the beginning
            infile.clear();     
            infile.seekg(0);    
            continue;
        }
        // Insert the read line into the set (THIS IS THE ONLY DIFFERENCE)
        s.insert(line);
        count++; // Increment the counter
    }

    //close file
    infile.close();

    //end time of the read operation
    auto end = high_resolution_clock::now();

    // calculate the duration 
    auto duration = duration_cast<microseconds>(end - start).count();

    return duration;

}
long long readList(list<string>& l) {
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
    while (count < NUM_ELEMENTS) {
        if (!getline(infile, line)) {
            // If EOF is reached, clear the EOF flag and reset the file pointer to the beginning
            infile.clear();
            infile.seekg(0);
            continue;
        }
       //But how do we insert when working with a list? We can use push back. Of course.
        l.push_back(line);
        count++; // and increment
    }
    //close file
    infile.close();

    //end time of the read operation
    auto end = high_resolution_clock::now();

    // calculate the duration 
    auto duration = duration_cast<microseconds>(end - start).count();

    return duration;
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
        if (!getline(infile, line)) {
            // If EOF is reached, clear the EOF flag and reset the file pointer to the beginning
            infile.clear();
            infile.seekg(0);
            continue;
        }
        v.push_back(line); //push back into vector here
        count++; //almost forgot to increment
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
    // Record the start time of the insert operation
    auto start = high_resolution_clock::now();

    size_t vec_mid = v.size() / 2;
    v.insert(v.begin() + vec_mid, INSERT_VALUE);

    // Record end time of the insert operation
    auto end = high_resolution_clock::now();

    // Calculate 
    auto duration = duration_cast<microseconds>(end - start).count();

    return duration; // duration in microseconds
}
long long insertList(list<string>& l) {
    // Record the start time of the insert operation
    auto start = high_resolution_clock::now();

    // Record end time of the insert operation
    auto end = high_resolution_clock::now();

    // Calculate 
    auto duration = duration_cast<microseconds>(end - start).count();

    return duration; // duration in microseconds
}
long long insertSet(set<string>& s) {
    // Record the start time of the insert operation
    auto start = high_resolution_clock::now();

    s.insert(INSERT_VALUE);

    // Record end time of the insert operation
    auto end = high_resolution_clock::now();

    // Calculate 
    auto duration = duration_cast<microseconds>(end - start).count();

    return duration; // duration in microseconds
}
long long deleteVector(vector<string>& v) {
    // Record the start time of the insert operation
    auto start = high_resolution_clock::now(); 

    //get mid point
    size_t vec_mid = v.size() / 2;

    // Erase the element at the middle position
    v.erase(v.begin() + vec_mid);

    // Record end time of the insert operation
    auto end = high_resolution_clock::now();

    // Calculate 
    auto duration = duration_cast<microseconds>(end - start).count();

    return duration; // duration in microseconds
}
long long deleteList(list<string>& l) {
    // Record the start time of the insert operation
    auto start = high_resolution_clock::now();

   // create iterator pointing to beginning of list, advance to middle, then erase
    auto it = l.begin();
    advance(it, l.size() / 2);
    l.erase(it);

    // Record end time of the insert operation
    auto end = high_resolution_clock::now();

    // Calculate 
    auto duration = duration_cast<microseconds>(end - start).count();

    return duration; // duration in microseconds
}
long long deleteSet(set<string>& s) {
    // Record the start time of the insert operation
    auto start = high_resolution_clock::now();

    // create iterator pointing to beginning of set, advance to middle, then erase
    auto it = s.begin();
    advance(it, s.size() / 2);
    s.erase(it);

    // Record end time of the insert operation
    auto end = high_resolution_clock::now();

    // Calculate 
    auto duration = duration_cast<microseconds>(end - start).count();

    return duration; // duration in microseconds
}
void display(const vector<string>& operation, const vector<long long>& vectorTimes, const vector<long long>& listTimes, const vector<long long>& setTimes) {

    //updated output with iomanip
    cout << left << setw(12) << "Operation"
        << right << setw(12) << "Vector"
        << right << setw(12) << "List"
        << right << setw(12) << "Set" << endl;

    //for loop for display
    for (size_t i = 0; i < operation.size(); ++i) {
        cout << left << setw(12) << operation[i] << "    ";

        if (vectorTimes[i] != -1) {
            cout << right << setw(10) << vectorTimes[i] << "    ";
        }
        else {
            cout << right << setw(10) << "-1" << "    ";
        }
        if (listTimes[i] != -1) {
            cout << right << setw(10) << listTimes[i] << "    ";
        }
        else {
            cout << right << setw(10) << "-1" << "    ";
        }
        if (setTimes[i] != -1) {
            cout << right << setw(10) << setTimes[i] << "    ";
        }
        else {
            cout << right << setw(10) << "-1" << "    ";
        }
        cout << endl;
    }
}

