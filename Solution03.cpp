#include <iostream>
#include <string>
#include <vector>

#include "Solution03.h"
#include "StringParser.h"

using namespace std;

int Solution03::solve(string &input) {
    sum = 0;
    StringParser stringParser;
    stringParser.map(schematic, input);
    for (unsigned int rowNum = 0; rowNum < schematic.size(); rowNum++) {
        for (unsigned int colNum = 0; colNum < schematic[rowNum].size(); colNum++) {
            if (schematic[rowNum][colNum] == '*') {
                searchBorderAndAddIfGear(rowNum, colNum);
            }
        }
    }
    return sum;
};

void Solution03::searchBorderAndAddIfGear(int gearRow, int gearCol) {
    vector<vector<bool>> border(3, vector<bool>(3, false));
    vector<int> partNum;
    for (int rowDiff = -1; rowDiff <= 1; rowDiff++) {
        for (int colDiff = -1; colDiff <= 1; colDiff++) {
            int rowNum = gearRow + rowDiff;
            int colNum = gearCol + colDiff;
            if (rowNum >= 0 && rowNum < (int) schematic.size() && colNum >= 0 && colNum < (int) schematic[0].size() 
            && schematic[rowNum][colNum] >= '0' && schematic[rowNum][colNum] <= '9' 
            && border[rowDiff + 1][colDiff + 1] == false) {
                partNum.push_back(getPartNum(border, gearRow, gearCol, rowDiff, colDiff));
            }
        }
    }
    if (partNum.size() == 2) {
        sum = sum + partNum[0] * partNum[1];
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