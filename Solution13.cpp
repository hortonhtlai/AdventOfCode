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
        if (getDiffIfHorizontalReflection(patternMap, rowNum) == 1) {
            summary = summary + 100 * rowNum;
            return;
        }
    }

    for (unsigned int colNum = 1; colNum < patternMap[0].size(); colNum++) {
        if (getDiffIfVerticalReflection(patternMap, colNum) == 1) {
                summary = summary + colNum;
                return;
        }
    }
};

int Solution13::getDiffIfHorizontalReflection(const vector<vector<char>> &patternMap, int rowNum) {
    int diff = 0;
    for (int rowDiff = 0; rowDiff < rowNum && rowDiff < (int) patternMap.size() - rowNum; rowDiff++) {
        diff = diff + getDiffIfRowsEqual(patternMap, rowNum - 1 - rowDiff, rowNum + rowDiff);
    }
    return diff;
};

int Solution13::getDiffIfRowsEqual(const vector<vector<char>> &patternMap, int rowNum1, int rowNum2) {
    int diff = 0;
    for (unsigned int colNum = 0; colNum < patternMap[0].size(); colNum++) {
        if (patternMap[rowNum1][colNum] != patternMap[rowNum2][colNum]) {
            diff++;
        }
    }
    return diff;
};

int Solution13::getDiffIfVerticalReflection(const vector<vector<char>> &patternMap, int colNum) {
    int diff = 0;
    for (int colDiff = 0; colDiff < colNum && colDiff < (int) patternMap[0].size() - colNum; colDiff++) {
        diff = diff + getDiffIfColsEqual(patternMap, colNum - 1 - colDiff, colNum + colDiff);
    }
    return diff;
};

int Solution13::getDiffIfColsEqual(const vector<vector<char>> &patternMap, int colNum1, int colNum2) {
    int diff = 0;
    for (unsigned int rowNum = 0; rowNum < patternMap.size(); rowNum++) {
        if (patternMap[rowNum][colNum1] != patternMap[rowNum][colNum2]) {
            diff++;
        }
    }
    return diff;
};