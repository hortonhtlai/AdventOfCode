#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "Solution07.h"
#include "StringParser.h"

using namespace std;

void addWildCards(unordered_map<int, int> &frequencyPattern) {
    if (frequencyPattern.find(-1) != frequencyPattern.end()) {
        int numWildCards = frequencyPattern[-1];
        int patternMax = 0;
        for (auto mapIterator = frequencyPattern.begin(); mapIterator != frequencyPattern.end(); mapIterator++) {
            patternMax = max(patternMax, mapIterator->first);
        }
        frequencyPattern[patternMax] = frequencyPattern[patternMax] - 1;
        if (frequencyPattern.find(patternMax + numWildCards) == frequencyPattern.end()) {
            frequencyPattern[patternMax + numWildCards] = 1;
        } else {
            frequencyPattern[patternMax + numWildCards] = frequencyPattern[patternMax + numWildCards] + 1;
        }
    }
}

int getTypeStrength(string &hand) {
    unordered_map<char, int> cardFrequency;
    unordered_map<int, int> frequencyPattern;
    for (char card : hand) {
        if (cardFrequency.find(card) == cardFrequency.end()) {
            cardFrequency[card] = 1;
        } else {
            cardFrequency[card] = cardFrequency[card] + 1;
        }
    }
    for (auto mapIterator = cardFrequency.begin(); mapIterator != cardFrequency.end(); mapIterator++) {
        if (mapIterator->first == 'J') {
            frequencyPattern[-1] = cardFrequency[mapIterator->first];
        } else {
            int frequency = cardFrequency[mapIterator->first];
            if (frequencyPattern.find(frequency) == frequencyPattern.end()) {
                frequencyPattern[frequency] = 1;
            } else {
                frequencyPattern[frequency] = frequencyPattern[frequency] + 1;
            }
        }
    }
    addWildCards(frequencyPattern);
    if (frequencyPattern[5] == 1) return 6;
    if (frequencyPattern[4] == 1 && frequencyPattern[1] == 1) return 5;
    if (frequencyPattern[3] == 1 && frequencyPattern[2] == 1) return 4;
    if (frequencyPattern[3] == 1 && frequencyPattern[1] == 2) return 3;
    if (frequencyPattern[2] == 2 && frequencyPattern[1] == 1) return 2;
    if (frequencyPattern[2] == 1 && frequencyPattern[1] == 3) return 1;
    if (frequencyPattern[1] == 5) return 0;
    return -1;
};

int getCardStrength(char &card) {
    vector<char> cardHierarchy = {'J', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'Q', 'K', 'A'};
    for (unsigned int i = 0; i < cardHierarchy.size(); i++) {
        if (card == cardHierarchy[i]) {
            return i;
        }
    }
    return -1;
};

bool compare(pair<string, int> &pair1, pair<string, int> &pair2) {
    int typeStrength1 = getTypeStrength(pair1.first);
    int typeStrength2 = getTypeStrength(pair2.first);
    if (typeStrength1 != typeStrength2) {
        return typeStrength1 < typeStrength2;
    } else {
        for (unsigned int i = 0; i < pair1.first.size(); i++) {
            int cardStrength1 = getCardStrength(pair1.first.at(i));
            int cardStrength2 = getCardStrength(pair2.first.at(i));
            if (cardStrength1 != cardStrength2) {
                return cardStrength1 < cardStrength2;
            }
        }
    }
    return false;
};

int Solution07::solve(string &input) {
    sum = 0;
    StringParser stringParser;
    vector<string> handVector;
    stringParser.split(handVector, input, {"\n"});
    for (string hand : handVector) {
        vector<string> termVector;
        stringParser.split(termVector, hand, {" "});
        pairs.push_back(pair<string, int>(termVector[0], stoi(termVector[1])));
    }
    sort(pairs.begin(), pairs.end(), compare);
    for (unsigned int i = 0; i < pairs.size(); i++) {
        // cout << pairs[i].first << endl;
        sum = sum + pairs[i].second * (i + 1);
    }
    return sum;
};