#include <iostream>
#include <string>
#include <vector>

#include "Solution15.h"
#include "StringParser.h"

using namespace std;

int Solution15::solve(string &input) {
    sum = 0;
    StringParser stringParser;
    vector<string> stepVector;
    stringParser.split(stepVector, input, {","});
    for (unsigned int i = 0; i < stepVector.size(); i++) {
        addHashValue(stepVector[i]);
    }
    return sum;
};

void Solution15::addHashValue(const string &step) {
    int value = 0;
    for (unsigned int i = 0; i < step.size(); i++) {
        value = value + (int) step.at(i);
        value = value * 17;
        value = value % 256;
    }
    sum = sum + value;
};