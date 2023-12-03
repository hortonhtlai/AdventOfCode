#include <iostream>

#include "Solution03.h"

using namespace std;

int Solution03::solve(string &input) {
    sum = 0;
    generateSchematic(input);
    searchAndClearBorder();
    return sum;
};

void Solution03::generateSchematic(string &input) {
    vector<char> buffer;
    int rowNum = 0;
    int colNum = 0;
    for (unsigned int i = 0; i <= input.length(); i++) {
        if (i == input.length() || input.at(i) == '\n') {
            schematic.push_back(buffer);
            buffer = vector<char>();
            rowNum++;
            colNum = 0;
        } else {
            if ((input.at(i) < '0' || input.at(i) > '9') && input.at(i) != '.') {
                pair<int, int> coords;
                coords.first = rowNum;
                coords.second = colNum;
                symbolSet.insert(coords);
            }
            buffer.push_back(input.at(i));
            colNum++;
        }
    }
};

void Solution03::searchAndClearBorder() {
    for (set<pair<int, int>>::iterator setIterator = symbolSet.begin(); setIterator != symbolSet.end(); setIterator++) {
        for (int rowDiff = -1; rowDiff <= 1; rowDiff++) {
            for (int colDiff = -1; colDiff <= 1; colDiff++) {
                int rowNum = setIterator->first + rowDiff;
                int colNum = setIterator->second + colDiff;
                if (rowNum >= 0 && rowNum < schematic.size() && colNum >= 0 && colNum < schematic[0].size() && schematic[rowNum][colNum] >= '0' && schematic[rowNum][colNum] <= '9') {
                    AddAndClearNumber(rowNum, colNum);
                }
            }
        }
    }
};

void Solution03::AddAndClearNumber(int rowNum, int colNum) {
    while (colNum - 1 >= 0 && schematic[rowNum][colNum - 1] >= '0' && schematic[rowNum][colNum - 1] <= '9') {
        colNum--;
    }
    string numString = "";
    while (colNum < schematic[0].size() && schematic[rowNum][colNum] >= '0' && schematic[rowNum][colNum] <= '9') {
        numString.push_back(schematic[rowNum][colNum]);
        schematic[rowNum][colNum] = '.';
        colNum++;
    }
    sum = sum + stoi(numString);
};