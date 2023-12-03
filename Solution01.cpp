#include <iostream>
#include <vector>
#include <string>

#include "solution01.h"
#include "StringSplitter.h"

using namespace std;

int Solution01::solve(string input) {
    StringSplitter stringSplitter;
    vector<string> caliVector;
    stringSplitter.split(caliVector, input, {'\n'});
    for (string caliString : caliVector) {
        int tenthDigit = -1;
        for (unsigned int forward = 0; forward < caliString.length() && tenthDigit == -1; forward++) {
            if (caliString.at(forward) >= '0' && caliString.at(forward) <= '9') {
                tenthDigit = caliString.at(forward) - '0';
            }
        }
        int unitDigit = -1;
        for (int reverse = caliString.length()-1; reverse >= 0 && unitDigit == -1; reverse--) {
            if (caliString.at(reverse) >= '0' && caliString.at(reverse) <= '9') {
                unitDigit = caliString.at(reverse) - '0';
            }
        }
        sum = sum + 10 * tenthDigit + unitDigit;
    }
    return sum;
};