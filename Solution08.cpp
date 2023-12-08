#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Solution08.h"
#include "StringParser.h"

using namespace std;

int Solution08::solve(string &input) {
    count = 0;
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
    return count;
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
    string position = "AAA";
    while (position != "ZZZ") {
        position = shortcut[position];
        count = count + instructions.length();
    }
};