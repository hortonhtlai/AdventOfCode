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
        addPreviousPrediction(readingVector);
    }
    return sum;
};

void Solution09::addPreviousPrediction(vector<string> &readingVector) {
    vector<int> oriNumVector;
    bool oriZeroFlag = true;
    for (string reading : readingVector) {
        oriNumVector.push_back(stoi(reading));
        if (stoi(reading) != 0) {
            oriZeroFlag = false;
        }
    }
    sum = sum + getPreviousValue(oriNumVector, oriZeroFlag);
};

int Solution09::getPreviousValue(vector<int> &oldNumberVector, bool oldZeroFlag) {
    if (oldZeroFlag == true) {
        return 0;
    } else {
        vector<int> newNumVector;
        bool newZeroFlag = true;
        for (unsigned int i = 1; i < oldNumberVector.size(); i++) {
            newNumVector.push_back(oldNumberVector[i] - oldNumberVector[i - 1]);
            if (oldNumberVector[i] - oldNumberVector[i - 1]) {
                newZeroFlag = false;
            }
        }
        return oldNumberVector[0] - getPreviousValue(newNumVector, newZeroFlag);
    }
};