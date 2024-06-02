#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "bot_service.h"

using namespace std;

void BotService::BotIntro(string email){
    int input;
    cout << "Hey there! Please enter any questions you have in regards to the tennis club! Also, you can see or delete previous questions you've asked!" << endl;
    cout << "Enter 1 to ask a question, 2 to delete a question, 3 to see your previous questions, or 4 to logout: ";
    cin >> input;
    while(input != 1 && input != 2 && input != 3 && input != 4){
        cout << "Please enter either 1 to ask a question, 2 to delete a question(s), 3 to see your previous questions, or 4 to logout: ";
        cin >> input;
    }
    while(input != 4){
        switch(input){
            //if input was to ask a question
            case 1:
                Response(email);
                cout << "Enter 1 to ask a question, 2 to delete a question, 3 to see all previous questions, or 4 to logout: ";
                cin >> input;
                while(input != 1 && input != 2 && input != 3 && input != 4){
                    cout << "Please enter 1 to ask a question, 2 to delete a question, 3 to see all previous questions, or 4 to logout: ";
                    cin >> input;
                }
                break;
            //if input was to delete a question
            case 2:
                BotDelete(email);
                cout << "Enter 1 to ask a question, 2 to delete a question, 3 to see all previous questions, or 4 to logout: ";
                cin >> input;
                while(input != 1 && input != 2 && input != 3 && input != 4){
                    cout << "Please enter 1 to ask a question, 2 to delete a question, 3 to see all previous questions, or 4 to logout: ";
                    cin >> input;
                }
                break;
            case 3:
                ifstream inputfile("users/" + email + ".txt");
                if (!inputfile.is_open()) {
                    cerr << "Error: Unable to open file" << endl;
                    return;
                }

                cout << "Here is the list of previously asked questions!" << endl;
                string line;
                int counter = 0;
                while (getline(inputfile, line)){
                    counter++;
                    cout << counter << ".) " << line << endl;
                }

                inputfile.close();
                cout << "Enter 1 to ask a question, 2 to delete a question, 3 to see all previous questions, or 4 to logout: ";
                cin >> input;
                while(input != 1 && input != 2 && input != 3 && input != 4){
                    cout << "Please enter 1 to ask a question, 2 to delete a question, 3 to see all previous questions, or 4 to logout: ";
                    cin >> input;
                }
                break;
        }
    }
    cout << "Logged out! Thank you for using our service!" << endl;
}

void BotService::Response(string email){
    //check for keywords in the question and provide responses accordingly
    int logout = 0;
    int moreq = 0;
    while(logout == 0){
        
        ofstream outputfile("users/" + email + ".txt", std::ios::app);
        if (!outputfile.is_open()) {
            cerr << "Error: Unable to open file" << endl;
            return;
        }

        string question;
        cout << "Please enter your question: ";
        cin.ignore(256, '\n');
        std::getline(std::cin, question);
        // cout << "HI" << question << endl;

        outputfile << question << endl;
        outputfile.close();

        //convert the question to lowercase for case-insensitive matching
        transform(question.begin(), question.end(), question.begin(), ::tolower);

        if (question.find("weather") != std::string::npos) {
            cout << "The weather is sunny today." << endl;
            cout << "Anymore questions? Enter 1 for yes, 2 for no: ";
            cin >> moreq;
            while(moreq != 1 && moreq != 2){
                cout << "Invalid option! Please enter 1 for yes, 2 for no: ";
                cin >> moreq;
            }
            if(moreq == 2){
                logout = 1;
            }
        } 
        else if (question.find("time") != std::string::npos) {
            cout << "It's currently 10:00 AM." << endl;
            cout << "Anymore questions? Enter 1 for yes, 2 for no: ";
            cin >> moreq;
            while(moreq != 1 && moreq != 2){
                cout << "Invalid option! Please enter 1 for yes, 2 for no: ";
                cin >> moreq;
            }
            if(moreq == 2){
                logout = 1;
            }
        } 
        else if (question.find("hello") != std::string::npos || question.find("hi") != std::string::npos) {
            cout << "Hello! How can I help you?" << endl;
            cout << "Anymore questions? Enter 1 for yes, 2 for no: ";
            cin >> moreq;
            while(moreq != 1 && moreq != 2){
                cout << "Invalid option! Please enter 1 for yes, 2 for no: ";
                cin >> moreq;
            }
            if(moreq == 2){
                logout = 1;
            }
        } 
        else if(question.find("match") != std::string::npos || question.find("matches") != std::string::npos) {
            cout << "Note that these matches are for the most recently upcoming event/tournament!" << endl;
            cout << "Which match do you want to select? Please look and select the match you want information on in the list below." << endl;
            //List all of the matches for the next upcoming event
            cout << "Currently, the draws for the next upcoming event (Alumni Cup) is unavailable as they are yet to be created. We apologize for the inconvenience." << endl;
            cout << "Anymore questions? Enter 1 for yes, 2 for no: ";
            cin >> moreq;
            while(moreq != 1 && moreq != 2){
                cout << "Invalid option! Please enter 1 for yes, 2 for no: ";
                cin >> moreq;
            }
            if(moreq == 2){
                logout = 1;
            }
        } 
        else if(question.find("event") != std::string::npos || question.find("events") != std::string::npos) {
            int event_choice = 0;
            cout << "Which event do you want to select? Please look and select the event you want information on in the list below." << endl;
            cout << "1.) Alumni Cup" << endl;
            cout << "2.) Final Cup" << endl;
            cout << "Which one do you want to see the details for? Please enter the corresponding number: ";
            cin >> event_choice;
            while(event_choice !=1 && event_choice !=2){
                cout << "Please select an available event!" << endl;
                cout << "Re-enter the number: " << endl;
            }
            if(event_choice == 1){
                cout << "------------------Alumni Cup------------------\n";
                cout << "Teams: OSU A, OSU B, OSU C, Alumni A, Alumni B, Alumni C" << endl;
                cout << "\nMembers\n";
                cout << "OSU A: Kamakshi Gina, Valdimárr Walela, Arlotto Franziska, Pushpa Waltheof, Even Fedora" << endl;
                cout << "OSU B: Wieland Kenneth, Maks Ilya, Slavka Aco, Sadıq Fito, Aravind Hawa" << endl;
                cout << "OSU C: Gaheriet Lawrie, Elisabet Sultana, Irina Aiolos, Jeannot Lojze, Władysława Boris" << endl;
                cout << "Alumni A: Pauline Geri, Martin Ljuban, Nanuk Dorotheos, Naseem Máximo, Ophiuchus Lleucu" << endl;
                cout << "Alumni B: Eithne Neferuptah, Timur Aniket, Antica Heitiare, Martins Sujatha, Olamide Ralitsa" << endl;
                cout << "Alumni C: Kehinde Kadyr, Asim Silvija, Nuri Zhaklina, Ottilia Irfan, Semele Gohar" << endl;
                cout << "\nSchedule\n";
                cout << "5/24/2024 - 5PM - Alumni A vs OSU C" << endl;
                cout << "5/24/2024 - 6PM - Alumni B vs OSU A" << endl;
                cout << "5/24/2024 - 7PM - Alumni C vs OSU B" << endl;
            }
            else if(event_choice == 2){
                cout << "------------------Final Cup------------------\n";
                cout << "TBA" << endl;
            }
            cout << "Anymore questions? Enter 1 for yes, 2 for no: ";
            cin >> moreq;
            while(moreq != 1 && moreq != 2){
                cout << "Invalid option! Please enter 1 for yes, 2 for no: ";
                cin >> moreq;
            }
            if(moreq == 2){
                logout = 1;
            }
        }  
        else if(question.find("when") != std::string::npos || question.find("who") != std::string::npos || question.find("play") != std::string::npos || question.find("playing") != std::string::npos) {
            int team = 0;
            cout << "For which team do you want information on?" << endl;
            cout << "1.) OSU A\n";
            cout << "2.) OSU B\n";
            cout << "3.) OSU B\n";
            cout << "4.) Alumni A\n";
            cout << "5.) Alumni B\n";
            cout << "6.) Alumni C\n";
            cout << "Please enter the corresponding number of the team you want information on: " << endl;
            cin >> team;
            while(team < 1 || team > 6){
                cout << "Please re-enter a valid corresponding number for the team you want data for: ";
                cin >> team;
            }
            switch (team){
                case 1:
                    cout << "The current schedule for OSU A is as below:\n";
                    cout << "    Alumni Cup - 5/24/2024 - 6PM - vs Alumni B" << endl;
                    cout << "    Final Cup - TBA" << endl;
                    break;
                case 2:
                    cout << "The current schedule for OSU B is as below:\n";
                    cout << "    Alumni Cup - 5/24/2024 - 7PM - vs Alumni C" << endl;
                    cout << "    Final Cup - TBA" << endl;
                    break;
                case 3:
                    cout << "The current schedule for OSU C is as below:\n";
                    cout << "    Alumni Cup - 5/24/2024 - 5PM - vs Alumni A" << endl;
                    cout << "    Final Cup - TBA" << endl;
                    break;
                case 4:
                    cout << "The current schedule for Alumni A is as below:\n";
                    cout << "    Alumni Cup - 5/24/2024 - 5PM - vs OSU C" << endl;
                    cout << "    Final Cup - TBA" << endl;
                    break;
                case 5: 
                    cout << "The current schedule for Alumni B is as below:\n";
                    cout << "    Alumni Cup - 5/24/2024 - 6PM - vs OSU A" << endl;
                    cout << "    Final Cup - TBA" << endl;
                    break;
                case 6:
                    cout << "The current schedule for Alumni C is as below:\n";
                    cout << "    Alumni Cup - 5/24/2024 - 7PM - vs OSU B" << endl;
                    cout << "    Final Cup - TBA" << endl;
                    break;
            }
            cout << "Anymore questions? Enter 1 for yes, 2 for no: ";
            cin >> moreq;
            while(moreq != 1 && moreq != 2){
                cout << "Invalid option! Please enter 1 for yes, 2 for no: ";
                cin >> moreq;
            }
            if(moreq == 2){
                logout = 1;
            }
        } 
        else {
            cout << "Sorry, I don't understand your question." << endl;
            cout << "Anymore questions? Enter 1 for yes, 2 for no: ";
            cin >> moreq;
            while(moreq != 1 && moreq != 2){
                cout << "Invalid option! Please enter 1 for yes, 2 for no: ";
                cin >> moreq;
            }
            if(moreq == 2){
                logout = 1;
            }
        }
    }
    
}

void BotService::BotDelete(string email){
    
    ifstream inputfile("users/" + email + ".txt");
    if (!inputfile.is_open()) {
        cerr << "Error: Unable to open file" << endl;
        return;
    }

    cout << "Here is the list of previously asked questions!" << endl;
    string line;
    int counter = 0;
    while (getline(inputfile, line)) {
        counter++;
        cout << counter << ".) " << line << endl;
    }

    inputfile.close();
    
    int delete_option;
    cout << "Would you like to delete one or all questions?\n";
    cout << "If you want to delete one, enter 1. If you want to delete all, enter 2: ";
    cin >> delete_option;
    while(delete_option < 1 && delete_option > 2){
        cout << "Please enter a valid option! If you want to delete one, enter 1. If you want to delete all, enter 2: ";
        cin >> delete_option;
    }
    switch(delete_option){
        //delete one question only
        case 1: {
            // Open user email file
            string filename = "users/" + email + ".txt";
            int lineNumToDelete;
            cout << "Enter the question number to delete (starting from 1): ";
            cin >> lineNumToDelete;
            while(lineNumToDelete < 1){
                cout << "Please re-enter a valid question number to delete: ";
                cin >> lineNumToDelete;
            }
            deleteLineFromFile(filename, lineNumToDelete);
            break;
        }
        //delete all questions
        case 2: {
            // Open user email file
            string filename = "users/" + email + ".txt";
            // Implement logic to delete all lines from the file
            ofstream outputfile(filename);
            outputfile.close();
            break;
        }
        default:
            break;
    }
}

void BotService::deleteLineFromFile(string filename, int lineNumToDelete) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    vector<string> lines;
    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();

    if (lineNumToDelete < 1 || lineNumToDelete > lines.size()) {
        cerr << "Error: Invalid line number" << endl;
        return;
    }

    lines.erase(lines.begin() + lineNumToDelete - 1);

    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << " for writing" << endl;
        return;
    }

    for (const auto& l : lines) {
        outputFile << l << endl;
    }

    outputFile.close();
    cout << "Line deleted successfully from file " << filename << endl;
}
