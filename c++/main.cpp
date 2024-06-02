#include <fstream>
#include <iostream>
#include <string>
#include "acc_info.h"
#include "auth_service.h"
#include "bot_service.h"
#include "contact.h"

using namespace std;

//prototype headers
void about();
void intro();

int main(){ 

    //Declared the objects for each different class so we can use its functions
    AuthService authservice;
    BotService botservice;
    AccInfo accinfo;
    Contact contact;

    intro();
    string email;
    char option;
    do{
        cout << "\nPlease select what you want to do from the options below by entering their corresponding numbers (1-5)..." << endl;
        cout << "       1: Register       2: Login       3: About       4: Contact Us!     5: Quit\n";
        cout << "Enter your option: ";
        //For initial input
        cin >> option;//option 1 = register, option 2 = login, option 3 = about, option 4 = contact
        while(option != '1' && option != '2' && option != '3' && option != '4' && option != '5'){
            cout << "Please enter a valid option: ";
            cin >> option;
        }
        //have something check if the user is logged in or not
        switch (option){
            //if registration selected
            case '1':
                authservice.registerUser();
                cout << "Now you can login! Try it out!" << endl;
                //string email = authservice.login();
                //break; 
            //if login selected
            case '2':
                //if login was successful, call the botservice
                email = authservice.login();
                if(email != ""){
                    botservice.BotIntro(email);
                    break;
                }
                else
                    break;
            //if about selected
            case '3':
                about();
                break;
            //if contact selected
            case '4':
                contact.contact();
                break;
            case '5':
                break;
        }
        if(option == '2'){
            break;
        }
    }while(option != '5');
    cout << "You are logged out! You have to log back in to use our services!" << endl;
    cout << "Thank you for using BeavBots! Come back again!" <<endl;
    //if logout, print out the link to OSU instagram or give the instagram account name. Also, provide discord link. And say see you again next time!

    //Quit program
    return 0;
}

void intro(){
    cout << "Welcome to BeavBot! You can ask me anything you want related to the OSU Tennis Club!" << endl;
    string name;
    cout << "But before we dive in, could you please tell me your name ( or just make it anything funny :) )? ";
    cin >> name;
    cout << "Perfect! Hi " << name << "! ";
    cout << "Please register if you do not have an account, otherwise, login to use our service!" << endl;
}

void about(){
    cout << "\n\n\n--------------------------------------------- ABOUT --------------------------------------------------------" << endl;
    cout << "\nBeavBot, created in 2024, can answer questions in regards to the Oregon State University's Tennis Club." << endl; 
    cout << "Created by Daniel Lee, a current undergraduate attending OSU, BeavBot can help members of the OSU Tennis Club " << endl;
    cout << "as well as those who are interested in the Tennis Club's practice and event schedules, to access them without a hassle." << endl;
    cout << "Thank you for using our service!" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
}