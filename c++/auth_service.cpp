#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "auth_service.h"

using namespace std;

//to check if user logged in
bool AuthService::authenticateUser(string email, string password) {
    ifstream checkuser("users.txt");//ifstream does not have to open or close since it automatically handles that
    string line;
    while (getline(checkuser, line)) {
        //split the line into email and password
        size_t pos = line.find(": ");
        string user_email = line.substr(0, pos);//use substr keyword
        string user_password = line.substr(pos + 2);

        //check if the provided email and password match
        if(user_email == email && user_password == password)
            return true;  //user found
    }
    return false;  //user not found
}

//to have user input login information
string AuthService::login(){
    string email;
    string password;
    cout << "\n\n\nPlease enter your credentials below\n";
    cout << "Email: ";
    cin >> email;
    cout << "Password: ";
    cin >> password;

    //if authentication goes through, return true
    if(authenticateUser(email, password) == true){
        cout << "Login Successful! Welcome!" << endl;
        return email;
    }
    //else if authentication fails, return false
    else if(authenticateUser(email, password) == false){
        cout << "Login Failed! Please make sure your credentials are entered correctly!" << endl;
    }
    //otherwise, email is not found, so tell user to make a new account
    else{
        ifstream checkuser("users.txt");//ifstream does not have to open or close since it automatically handles that
        string line;
        while (getline(checkuser, line)) {
            //split the line into email and password
            size_t pos = line.find(": ");
            string user_email = line.substr(0, pos);//use substr keyword
            string user_password = line.substr(pos + 2);

            //only check if the provided email matches
            if(user_email == email)
                return email;  //user found
        }
    //if the user is never found it should return a fail message
        cout << "Login Failed! Please make sure you registered an account with this email!" << endl;
    }
    return "";
}

void AuthService::registerUser(){
    string email;
    string password;
    string double_check_password;
    cout << "\n\n\nPlease take note that your email must be valid while your password can be anything." << endl;
    cout << "For safety measures, however, it is recommended that you make your password strong but memorizable." << endl;
    cout << "If you do not remember your credentials, you must retrieve it by contacting us. Thank you!" << endl;

    cout << "Please enter your email and password" << endl;
    //Check email syntax
    cout << "Email: ";
    cin >> email;
    while(isValidEmail(email) != true){
        cout <<"Please re-enter a valid form of email: ";
        cin >> email;
    }

    //if there is already an account registered with an email, check and stop from duplicating
    ifstream checkuser("users.txt");
    string line;
    while (getline(checkuser, line)) {
        // Split the line into email and password
        size_t pos = line.find(": ");
        string user_email = line.substr(0, pos);//use substr keyword
        string user_password = line.substr(pos + 2);

        // Check if the provided email already matches the provided email
        if(user_email == email){
            cout << "There is already an associated account with this email! If you forgot your credentials, please contact us." << endl;
        }
            
    }

    //Double check password
    cout << "Password: ";
    cin >> password;
    cout << "Re-enter your password for confirmation: ";
    cin >> double_check_password;
    while(password != double_check_password){
        cout << "Please make sure you entered the same, correct password!" << endl;
        cout << "Enter password: ";
        cin >> password;
        cout << "Re-enter password: ";
        cin >> double_check_password;
    }

    //record the new user's email and password
    ofstream outputfile("users.txt", std::ios_base::app);
    if(outputfile.is_open()){
        // Write email and password to the file
        outputfile << email << ": " << password << endl;
        outputfile.close();
        cout << "Registration successful. Your credentials have been saved." << endl;
    } 
    else {
        std::cerr << "Unable to open users.txt for appending." << endl;
    }

    //create a new text file for the user using their email as the filename (this is to keep track of previously asked questions)
    ofstream userfile("users/" + email + ".txt");
    if (userfile.is_open()) {
        userfile.close();
        cout << "User file created for: " << email << endl;
    } else {
        cerr << "Unable to create user file for: " << email << endl;
    }

}

//Check this when user registers
bool AuthService::isValidEmail(string email) {
    //regular expression for validating email addresses
    std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    //check if the email matches the pattern
    return std::regex_match(email, pattern);
}