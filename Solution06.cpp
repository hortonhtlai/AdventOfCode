#include <iostream>
#include <string>

#include "Solution06.h"
#include "StringSplitter.h"

using namespace std;

int Solution06::solve(string &input) {
    product = 1;
    StringSplitter stringSplitter;
    vector<string> variableVector;
    stringSplitter.split(variableVector, input, {"\n"});
    for (string variable : variableVector) {
        vector<string> termVector;
        stringSplitter.split(termVector, variable, {":", " "});
        if (termVector[0] == "Time") {
            for (unsigned int i = 1; i < termVector.size(); i++) {
                timeVector.push_back(stoi(termVector[i]));
            }
        } else if (termVector[0] == "Distance") {
            for (unsigned int i = 1; i < termVector.size(); i++) {
                distanceVector.push_back(stoi(termVector[i]));
            }
        }
    }
    multiplyWinWays();
    return product;
};

void Solution06::multiplyWinWays() {
    for (unsigned int i = 0; i < timeVector.size(); i++) {
        int mid = timeVector[i] / 2;
        if (mid * (timeVector[i] - mid) <= distanceVector[i]) {
            product = 0;
        } else {
            int low = mid;
            int diff = mid;
            while (diff > 0) {
                if ((low - diff) * (timeVector[i] - low + diff) > distanceVector[i]) {
                    low = low - diff;
                } else {
                    diff = diff / 2;
                }
            }
            int high = mid;
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