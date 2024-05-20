#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

#include <thread> //For this_thread::sleep_for
#include <chrono> // For chrono::seconds

using namespace std;

void helper(string selection); //prototype
string select(string option);
bool check_run(string filename);

int main(){
    while (!check_run("start.txt")) {
        cout << "Waiting for the word 'run' in start.txt..." << endl;
        this_thread::sleep_for(chrono::seconds(2)); //Wait for 2 seconds before checking again
    }

    string option;
    this_thread::sleep_for(chrono::seconds(2));//Just to allow user more time to read
    cout << "Welcome to the random recipe generator! You want ideas for cooking but can't think of what you want?\n";
    this_thread::sleep_for(chrono::seconds(2));//Just to allow user more time to read
    cout << "Well, we have the right recipes just for you! You can select from many different categories: Breakfast, Lunch, Dinner, or Dessert\n";
    this_thread::sleep_for(chrono::seconds(2));//Just to allow user more time to read and not feel rushed
    cout << "Please enter the category of recipe you want: ";
    cin >> option;
    string selection = select(option);
    helper(selection);

    string cont;
    cout << "Would you like to look at another recipe? Enter yes or no: ";
    cin >> cont;              
    while(cont == "Yes" || cont == "yes" || cont == "Y" || cont == "y"){
        cout << "Please enter the category of recipes you want (Breakfast, Lunch, Dinner, or Dessert): ";
        cin >> option;
        selection = select(option);
        helper(selection);
        cout << "Would you like to look at another recipe? Enter yes or no: ";
        cin >> cont;  
    }
    cout << "Thank you for using the random recipe generator! Have a great day." << endl;
    return 0;
}

//function to check if the file contains the word "run"
bool check_run(string filename){
    ifstream file(filename);
    if (file.is_open()) {
        string word;
        while (file >> word) {
            if (word == "run") {
                file.close();
                ofstream clearfile(filename, ios::trunc); //Clear the file
                clearfile.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

string select(string option){
    while(option != "Breakfast" && option != "breakfast" && option != "Lunch" && option != "lunch" && 
          option != "Dinner" && option != "dinner" && option != "Dessert" && option != "dessert")
    {
        cout << "Please enter a valid option (Breakfast, Lunch, Dinner, Dessert): ";
        cin >> option;
    }
    return option;
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