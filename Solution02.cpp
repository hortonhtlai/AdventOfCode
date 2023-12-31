#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Solution02.h"
#include "StringParser.h"

using namespace std;

int Solution02::solve(string &input) {
    sum = 0;
    StringParser stringParser;
    vector<string> gameVector;
    stringParser.split(gameVector, input, {"\n"});
    for (string game : gameVector) {
        redNum = 0;
        greenNum = 0;
        blueNum = 0;
        vector<string> pairVector;
        stringParser.split(pairVector, game, {":", ",", ";"});
        for (string pair : pairVector) {
            vector<string> termVector;
            stringParser.split(termVector, pair, {" "});
            processPairValues(termVector);
        }
        // verifyGame();
        addGamePower();
    }
    return sum;
};

void Solution02::processPairValues(vector<string> &termVector) {
    string word;
    int num;
    if (termVector[0].at(0) >= '0' && termVector[0].at(0) <= '9') {
        word = termVector[1];
        num = stoi(termVector[0]);
    } else {
        word = termVector[0];
        num = stoi(termVector[1]);
    }

    if (word == "Game") {
        gameNum = num;
    } else if (word == "red") {
        redNum = max(redNum, num);
    } else if (word == "green") {
        greenNum = max(greenNum, num);
    } else if (word == "blue") {
        blueNum = max(blueNum, num);
    }
};

void Solution02::verifyGame() {
    if (redNum <= 12 && greenNum <= 13 && blueNum <= 14) {
        sum = sum + gameNum;
    }
};

void Solution02::addGamePower() {
    sum = sum + redNum * greenNum * blueNum;
}