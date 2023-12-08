#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Solution08.h"
#include "StringParser.h"

using namespace std;

long long Solution08::solve(string &input) {
    // count = 0;
    StringParser stringParser;
    vector<string> lineVector;
    stringParser.split(lineVector, input, {"\n"});
    instructions = lineVector[0];
    for (unsigned int i = 1; i < lineVector.size(); i++) {
        vector<string> nodeVector;
        stringParser.split(nodeVector, lineVector[i], {" ", "=", "(", ",", ")"});
        network[nodeVector[0]] = pair<string, string>(nodeVector[1], nodeVector[2]);
    }
    generateShortcut();
    traverseNetwork();
    return findLCM() * instructions.length();
};

void Solution08::generateShortcut() {
    for (auto mapIterator = network.begin(); mapIterator != network.end(); mapIterator++) {
        string position = mapIterator->first;
        for (char step : instructions) {
            if (step == 'L') {
                position = network[position].first;
            } else if (step == 'R') {
                position = network[position].second;
            }
        }
        shortcut[mapIterator->first] = position;
    }
};

void Solution08::traverseNetwork() {
    for (auto mapIterator = shortcut.begin(); mapIterator != shortcut.end(); mapIterator++) {
        if (mapIterator->first.at(2) == 'A') {
            string position = mapIterator->first;
            int jump = 0;
            while (position.at(2) != 'Z') {
                position = shortcut[position];
                jump++;
            }
            count.push_back(jump);
        }
    }
};

long long Solution08::findLCM() {
    long long lcm = 1;
    long long factorProduct = 1;
    for (long long jump : count) {
        long long testFactor = 2;
        while (testFactor <= lcm && testFactor <= jump) {
            if (lcm % testFactor == 0 && jump % testFactor == 0) {
                lcm = lcm / testFactor;
                jump = jump / testFactor;
                factorProduct = factorProduct * testFactor;
            } else {
                testFactor++;
            }
        }
        lcm = lcm * jump;
    }
    return lcm * factorProduct;
};