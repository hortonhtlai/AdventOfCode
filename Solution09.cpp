#include <iostream>
#include <string>
#include <vector>

#include "Solution09.h"
#include "StringParser.h"

using namespace std;

int Solution09::solve(string &input) {
    sum = 0;
    StringParser stringParser;
    vector<string> historyVector;
    stringParser.split(historyVector, input, {"\n"});
    for (string history : historyVector) {
        vector<string> readingVector;
        stringParser.split(readingVector, history, {" "});
        addNextPrediction(readingVector);
    }
    return sum;
};

void Solution09::addNextPrediction(vector<string> &readingVector) {
    vector<int> oldVector;
    bool oldFlag = true;
    for (string reading : readingVector) {
        oldVector.push_back(stoi(reading));
        if (stoi(reading) != 0) {
            oldFlag = false;
        }
    }
    vector<int> newVector;
    bool newFlag = true;
    while (oldFlag == false) {
        sum = sum + oldVector[oldVector.size() - 1];
        for (unsigned int i = 1; i < oldVector.size(); i++) {
            newVector.push_back(oldVector[i] - oldVector[i - 1]);
            if (oldVector[i] - oldVector[i - 1] != 0) {
                newFlag = false;
            }
        }
        oldVector = newVector;
        oldFlag = newFlag;
        newVector = vector<int>();
        newFlag = true;
    }
}