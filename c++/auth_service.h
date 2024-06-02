#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

class AuthService {
public:
    bool authenticateUser(string , string);
    string login();
    void registerUser();
    bool logout();

private:
    bool isValidEmail(string);
};

#endif