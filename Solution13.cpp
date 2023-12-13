#include <iostream>
#include <string>
#include <vector>

#include "Solution13.h"
#include "StringParser.h"

using namespace std;

int Solution13::solve(string &input) {
    summary = 0;
    StringParser stringParser;
    vector<string> patternVector;
    stringParser.split(patternVector, input, {"\n\n"});
    for (string pattern : patternVector) {
        vector<vector<char>> patternMap;
        stringParser.map(patternMap, pattern);
        findAndAddReflection(patternMap);
    }
    return summary;
};

void Solution13::findAndAddReflection(const vector<vector<char>> &patternMap) {
    for (unsigned int rowNum = 1; rowNum < patternMap.size(); rowNum++) {
        if (checkHorizontalReflection(patternMap, rowNum)) {
            summary = summary + 100 * rowNum;
            return;
        }
    }

    for (unsigned int colNum = 1; colNum < patternMap[0].size(); colNum++) {
        if (checkVerticalReflection(patternMap, colNum)) {
                summary = summary + colNum;
                return;
        }
    }
};

bool Solution13::checkHorizontalReflection(const vector<vector<char>> &patternMap, int rowNum) {
    for (int rowDiff = 0; rowDiff < rowNum && rowDiff < (int) patternMap.size() - rowNum; rowDiff++) {
        if (patternMap[rowNum - 1 - rowDiff] != patternMap[rowNum + rowDiff]) {
            return false;
        }
    }
    return true;
};

bool Solution13::checkVerticalReflection(const vector<vector<char>> &patternMap, int colNum) {
    for (int colDiff = 0; colDiff < colNum && colDiff < (int) patternMap[0].size() - colNum; colDiff++) {
        if (columnsEqual(patternMap, colNum - 1 - colDiff, colNum + colDiff) == false) {
            return false;
        }
    }
    return true;
};

bool Solution13::columnsEqual(const vector<vector<char>> &patternMap, int colNum1, int colNum2) {
    for (unsigned int rowNum = 0; rowNum < patternMap.size(); rowNum++) {
        if (patternMap[rowNum][colNum1] != patternMap[rowNum][colNum2]) {
            return false;
        }
    }
    return true;
};