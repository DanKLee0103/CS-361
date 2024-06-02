#ifndef BOT_SERVICE_H
#define BOT_SERVICE_H
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

class BotService {
public:
    void BotDelete(string);    
    void Response(string);
    void BotIntro(string);

private:
    void deleteLineFromFile(string, int);
};

#endif