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
        vector<string> termVector;
        if (stepVector[i].back() == '-') {
            stringParser.split(termVector, stepVector[i], {"-"});
            removeLens(termVector);
        } else {
            stringParser.split(termVector, stepVector[i], {"="});
            updateLens(termVector);
        }
        // addHashValue(stepVector[i]);
    }
    addFocusingPowers();
    return sum;
};

int Solution15::getHashValue(const string &step) {
    int value = 0;
    for (unsigned int i = 0; i < step.size(); i++) {
        value = value + (int) step.at(i);
        value = value * 17;
        value = value % 256;
    }
    return value;
};

void Solution15::removeLens(vector<string> &termVector) {
    int boxNum = getHashValue(termVector[0]);
    if (boxes.find(boxNum) != boxes.end()) {
        for (auto slotIterator = boxes[boxNum].begin(); slotIterator != boxes[boxNum].end(); slotIterator++) {
            if (slotIterator->first == termVector[0]) {
                boxes[boxNum].erase(slotIterator);
                return;
            }
        }
    }
};

void Solution15::updateLens(vector<string> &termVector) {
    int boxNum = getHashValue(termVector[0]);
    if (boxes.find(boxNum) == boxes.end()) {
        boxes[boxNum] = vector<pair<string, int>>();
    }
    for (pair<string, int> &slot : boxes[boxNum]) {
        if (slot.first == termVector[0]) {
            slot.second = stoi(termVector[1]);
            return;
        }
    }
    boxes[boxNum].push_back(pair<string, int>(termVector[0], stoi(termVector[1])));
};

void Solution15::addFocusingPowers() {
    for (auto boxIterator = boxes.begin(); boxIterator != boxes.end(); boxIterator++) {
        for (unsigned int slot = 0; slot < boxes[boxIterator->first].size(); slot++) {
            sum = sum + (boxIterator->first + 1) * (slot + 1) * boxes[boxIterator->first][slot].second;
        }
    }
};