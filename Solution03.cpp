#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "Solution03.h"

using namespace std;

int Solution03::solve(string &input) {
    sum = 0;
    generateSchematic(input);
    searchBorderAndAddIfGear();
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
            if (input.at(i) == '*') {
                pair<int, int> coords;
                coords.first = rowNum;
                coords.second = colNum;
                gearSet.insert(coords);
            }
            buffer.push_back(input.at(i));
            colNum++;
        }
    }
};

void Solution03::searchBorderAndAddIfGear() {
    for (set<pair<int, int>>::iterator setIterator = gearSet.begin(); setIterator != gearSet.end(); setIterator++) {
        vector<vector<bool>> border(3, vector<bool>(3, false));
        vector<int> partNum;
        for (int rowDiff = -1; rowDiff <= 1; rowDiff++) {
            for (int colDiff = -1; colDiff <= 1; colDiff++) {
                int rowNum = setIterator->first + rowDiff;
                int colNum = setIterator->second + colDiff;
                if (rowNum >= 0 && rowNum < (int) schematic.size() && colNum >= 0 && colNum < (int) schematic[0].size() 
                && schematic[rowNum][colNum] >= '0' && schematic[rowNum][colNum] <= '9' 
                && border[rowDiff + 1][colDiff + 1] == false) {
                    partNum.push_back(getPartNum(border, setIterator->first, setIterator->second, rowDiff, colDiff));
                }
            }
        }
        if (partNum.size() == 2) {
            sum = sum + partNum[0] * partNum[1];
        }
    }
};

int Solution03::getPartNum(vector<vector<bool>> &border, int gearRow, int gearCol, int rowDiff, int colDiff) {
    int rowNum = gearRow + rowDiff;
    int colNum = gearCol + colDiff;
    while (colNum - 1 >= 0 && schematic[rowNum][colNum - 1] >= '0' && schematic[rowNum][colNum - 1] <= '9') {
        colNum--;
    }
    string numString = "";
    while (colNum < (int) schematic[0].size() && schematic[rowNum][colNum] >= '0' && schematic[rowNum][colNum] <= '9') {
        numString.push_back(schematic[rowNum][colNum]);
        // schematic[rowNum][colNum] = '.';
        if (rowNum - gearRow >= -1 && rowNum - gearRow <= 1 && colNum - gearCol >= -1 && colNum - gearCol <= 1) {
            border[rowNum - gearRow + 1][colNum - gearCol + 1] = true;
        }
        colNum++;
    }
    return stoi(numString);
};