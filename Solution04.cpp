#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

#include "Solution04.h"
#include "StringSplitter.h"

using namespace std;

int Solution04::solve(string &input) {
    sum = 0;
    StringSplitter stringSplitter;
    vector<string> cardVector;
    stringSplitter.split(cardVector, input, {'\n'});
    for (string card : cardVector) {
        vector<string> listVector;
        stringSplitter.split(listVector, card, {':', '|'});
        vector<string> winningVector;
        stringSplitter.split(winningVector, listVector[1], {' '});
        vector<string> chosenVector;
        stringSplitter.split(chosenVector, listVector[2], {' '});
        addCardPoints(winningVector, chosenVector);
    }
    return sum;
};

void Solution04::addCardPoints(vector<string> &winningVector, vector<string> &chosenVector) {
    unordered_set<string> winningSet;
    for (string num : winningVector) {
        winningSet.insert(num);
    }
    int points = 0;
    for (string num : chosenVector) {
        if (winningSet.find(num) != winningSet.end()) {
            if (points == 0) {
                points = 1;
            } else {
                points = points << 1;
            }
        }
    }
    sum = sum + points;
};