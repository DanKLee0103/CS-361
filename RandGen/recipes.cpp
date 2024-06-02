#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

#include <thread> //For this_thread::sleep_for
#include <chrono> // For chrono::seconds

using namespace std;

void helper(string selection); //prototype
string check_run(string filename);

int main(){
    string category;
    while ((category = check_run("start.txt")) != "Breakfast" && category != "breakfast" && category != "Lunch" &&
           category != "lunch" && category != "Dinner" && category != "dinner" && category != "Dessert" &&
           category != "dessert") {
        cout << "Waiting for a category in start.txt..." << endl;
        this_thread::sleep_for(chrono::seconds(2)); // Wait for 2 seconds before checking again
    }
    helper(category);
    return 0;
}

//function to check if the file contains the word "run"
string check_run(string filename){
    ifstream file(filename);
    string word;
    if (file.is_open()) {
        while (file >> word) {
            if (word == "Breakfast" || word == "breakfast" || word == "Lunch" || word == "lunch" || word == "Dinner" || word == "dinner" || word == "Dessert" || word == "dessert") {
                file.close();
                ofstream clearfile(filename, ios::trunc); //Clear the file
                clearfile.close();
                return word;
            }
        }
        file.close();
    }
    return word;
}

void helper(string selection){
    srand(time(0)); //Set seed for random number generation
     //Generate a random number between 1 and 10
    int rand_num = rand() % 10 + 1; //0-9 but always add 1 to make it 1-10

    string filename;
    string line;

    while(1){
        //case "breakfast"
        if (selection == "Breakfast" || selection == "breakfast"){
            //filename
            filename = "recipes/breakfast/" + to_string(rand_num) + ".txt";

            //open the file and print its contents
            ifstream file(filename);
            ofstream destinationfile("start.txt", ios::trunc); // Open in truncate mode

            if (file.is_open() && destinationfile.is_open()) {
                cout << "\n\n";
                while (getline(file, line)) {
                    cout << line << endl;
                    destinationfile << line << endl;
                    //this_thread::sleep_for(chrono::duration<double>(0.5));
                }
                file.close();
                destinationfile.close();
                cout << "\n\n\n";
            } 
            //error if directory/folder not found
            else
                cerr << "Error: Unable to open file " << filename << endl;
            
            break;
        }

        //case "lunch"
        else if (selection == "Lunch" || selection == "lunch"){
            //filename
            filename = "recipes/lunch/" + to_string(rand_num) + ".txt";

            //open the file and print its contents
            ifstream file(filename);
            ofstream destinationfile("start.txt", ios::trunc); // Open in truncate mode

            if (file.is_open() && destinationfile.is_open()) {
                cout << "\n\n";
                while (getline(file, line)) {
                    cout << line << endl;
                    destinationfile << line << endl;
                }
                file.close();
                destinationfile.close();
                cout << "\n\n\n";
            } 
            //error if directory/folder not found
            else
                cerr << "Error: Unable to open file " << filename << endl;
            
            break;
        }

        //case "dinner"
        else if (selection == "Dinner" || selection == "dinner"){
            //filename
            filename = "recipes/dinner/" + to_string(rand_num) + ".txt";

            //open the file and print its contents
            ifstream file(filename);
            ofstream destinationfile("start.txt", ios::trunc); // Open in truncate mode

            if (file.is_open() && destinationfile.is_open()) {
                cout << "\n\n";
                while (getline(file, line)) {
                    cout << line << endl;
                    destinationfile << line << endl;
                    //this_thread::sleep_for(chrono::duration<double>(0.5));
                }
                file.close();
                destinationfile.close();
                cout << "\n\n\n";
            }
            //error if directory/folder not found
            else
                cerr << "Error: Unable to open file " << filename << endl;
            
            break;
        }

        //case "dessert"
        else if (selection == "Dessert" || selection == "dessert"){
            //filename
            filename = "recipes/dessert/" + to_string(rand_num) + ".txt";

            //open the file and print its contents
            ifstream file(filename);
            ofstream destinationfile("start.txt", ios::trunc); // Open in truncate mode

            if (file.is_open() && destinationfile.is_open()) {
                cout << "\n\n";
                while (getline(file, line)) {
                    cout << line << endl;
                    destinationfile << line << endl;
                    //this_thread::sleep_for(chrono::duration<double>(0.5));
                }
                file.close();
                destinationfile.close();
                cout << "\n\n\n";
            } 
            //error if directory/folder not found
            else
                cerr << "Error: Unable to open file " << filename << endl;
            
            break;
        }

        else
            break;
    }
}