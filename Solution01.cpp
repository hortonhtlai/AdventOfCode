#include <iostream>
#include <string>
#include <vector>

#include "Solution01.h"
#include "StringParser.h"

using namespace std;

int Solution01::solve(string &input) {
    sum = 0;
    StringParser stringParser;
    vector<string> caliVector;
    stringParser.split(caliVector, input, {"\n"});
    for (string caliData : caliVector) {
        addCaliValue(caliData);
    }
    return sum;
};

void Solution01::addCaliValue(string &caliDatapt) {
    int tenthDigit = -1;
    for (unsigned int forward = 0; forward < caliDatapt.length() && tenthDigit == -1; forward++) {
        tenthDigit = getDigitIfValid(caliDatapt, forward);
    }
    int unitDigit = -1;
    for (int reverse = caliDatapt.length() - 1; reverse >= 0 && unitDigit == -1; reverse--) {
        unitDigit = getDigitIfValid(caliDatapt, reverse);
    }
    sum = sum + 10 * tenthDigit + unitDigit;
};

int Solution01::getDigitIfValid(string &caliDatapt, int index) {
    if (caliDatapt.at(index) >= '0' && caliDatapt.at(index) <= '9') {
        return caliDatapt.at(index) - '0';
    }
    vector<string> spellings = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (unsigned int i = 0; i < spellings.size(); i++) {
        if (caliDatapt.substr(index, spellings[i].length()) == spellings[i]) {
            return i;
        }
    }
    return -1;
};