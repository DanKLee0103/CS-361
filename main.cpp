#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <thread>
#include <chrono>

using namespace std;

//Function to check if a file is empty
bool isFileEmpty(const string& filename) {
    struct stat fileStat;
    if (stat(filename.c_str(), &fileStat) == 0) {
        return fileStat.st_size == 0;
    }
    return true;
}

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
    else if(option == 3){
        string category;
        cout << "Welcome to the Random Recipe Generator!" << endl;
        cout << "Looking for new recipes? Well, choose the category you want your recipe from (Breakfast, Lunch, Dinner, or Dessert): ";
        cin >> category;
        while(category != "Breakfast" && category != "breakfast" && category != "Lunch" && category != "lunch" && category != "Dinner" && category != "dinner" && category != "Dessert" && category != "dessert"){
            cout << "Please enter a valid category of recipes from (Breakfast, Lunch, Dinner, or Dessert): ";
            cin >> category;
        }
        ofstream outputfile("start.txt", ios::trunc);
        if (outputfile.is_open()) {
            outputfile << category << endl; //Append the word "run" followed by a newline
            outputfile.close();
        } 
        string line;

        // Wait until the file is not empty and no longer contains only "run"
        while (true) {
            if (!isFileEmpty("start.txt")) {
                ifstream inputfile("start.txt");
                if (inputfile.is_open()) {
                    bool hasContent = false;
                    while (getline(inputfile, line)) {
                        if (line != category && !line.empty()) {
                            hasContent = true;
                            break;
                        }
                    }
                    inputfile.close();
                    if (hasContent) {
                        ifstream input("start.txt");
                        if (input.is_open()) {
                            cout << "\n";
                            while (getline(input, line)){
                                cout << line << endl;
                            }
                            cout << "\n";
                            input.close(); 
                        }
                        break;
                    }
                }
            }
            this_thread::sleep_for(chrono::seconds(1)); // Wait before checking again
        }
        cout << "Thank you for using the random recipe generator!" << endl;
    }
    return 0;
}