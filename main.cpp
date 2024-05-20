#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int option = 0;
    cout << "This is a test program! Select from your options (1-3): ";
    cin >> option;
    while(option != 1 && option != 2 && option != 3){
        cout << "Please enter a valid option (1-3): ";
        cin >> option;
    }
    if(option == 1){
        cout <<"Does something..." << endl;
    }
    else if(option == 2) {
        cout << "Does something..." << endl;
    }
    else if (option == 3) {
    ofstream outputfile("start.txt", ios::app);
    if (outputfile.is_open()) {
        outputfile << "run" << endl; //Append the word "run" followed by a newline
        outputfile.close();
    } 
    else
        cerr << "Error: Unable to open file start.txt for appending." << endl;
    }
    return 0;
}