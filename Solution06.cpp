#include <iostream>
#include <string>

#include "Solution06.h"
#include "StringParser.h"

using namespace std;

long long Solution06::solve(string &input) {
    product = 1;
    StringParser stringParser;
    vector<string> variableVector;
    stringParser.split(variableVector, input, {"\n"});
    for (string variable : variableVector) {
        vector<string> termVector;
        stringParser.split(termVector, variable, {":"});
        if (termVector[0] == "Time") {
            for (unsigned int i = 1; i < termVector.size(); i++) {
                timeVector.push_back(stoll(stringParser.remove(termVector[i], {" "})));
            }
        } else if (termVector[0] == "Distance") {
            for (unsigned int i = 1; i < termVector.size(); i++) {
                distanceVector.push_back(stoll(stringParser.remove(termVector[i], {" "})));
            }
        }
    }
    multiplyWinWays();
    return product;
};

void Solution06::multiplyWinWays() {
    for (unsigned int i = 0; i < timeVector.size(); i++) {
        long long mid = timeVector[i] / 2;
        if (mid * (timeVector[i] - mid) <= distanceVector[i]) {
            product = 0;
        } else {
            long long low = mid;
            long long diff = mid;
            while (diff > 0) {
                if ((low - diff) * (timeVector[i] - low + diff) > distanceVector[i]) {
                    low = low - diff;
                } else {
                    diff = diff / 2;
                }
            }
            long long high = mid;
            diff = mid;
            while (diff > 0) {
                if ((high + diff) * (timeVector[i] - high - diff) > distanceVector[i]) {
                    high = high + diff;
                } else {
                    diff = diff / 2;
                }
            }
            product = product * (high - low + 1);
        }
    }
};