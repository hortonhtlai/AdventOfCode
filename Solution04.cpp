#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

#include "Solution04.h"
#include "StringParser.h"

using namespace std;

int Solution04::solve(string &input) {
    sum = 0;
    StringParser stringParser;
    vector<string> cardVector;
    stringParser.split(cardVector, input, {"\n"});
    for (string card : cardVector) {
        vector<string> listVector;
        stringParser.split(listVector, card, {":", "|"});
        vector<string> headerVector;
        stringParser.split(headerVector, listVector[0], {" "});
        setAndAddOriginals(headerVector);
        vector<string> winningVector;
        stringParser.split(winningVector, listVector[1], {" "});
        vector<string> chosenVector;
        stringParser.split(chosenVector, listVector[2], {" "});
        winAndAddCopies(winningVector, chosenVector);
    }
    for (unordered_map<int, int>::iterator mapIterator = cardPile.begin(); mapIterator != cardPile.end(); mapIterator++) {
        sum = sum + mapIterator->second;
    }
    return sum;
};

void Solution04::winAndAddCopies(vector<string> &winningVector, vector<string> &chosenVector) {
    unordered_set<string> winningSet;
    for (string num : winningVector) {
        winningSet.insert(num);
    }
    int matches = 0;
    for (string num : chosenVector) {
        if (winningSet.find(num) != winningSet.end()) {
            matches++;
        }
    }
    for (int i = 1; i <= matches; i++) {
        addCard(cardNum + i, cardPile[cardNum]);
    }
};

void Solution04::setAndAddOriginals(vector<string> &headerVector) {
    if (headerVector[0] == "Card") {
        cardNum = stoi(headerVector[1]);
        addCard(cardNum, 1);
    }
};

void Solution04::addCard(int newCardNum, int newCardCount) {
    if (cardPile.find(newCardNum) == cardPile.end()) {
        cardPile[newCardNum] = newCardCount;
    } else {
        cardPile[newCardNum] = cardPile[newCardNum] + newCardCount;
    }
}