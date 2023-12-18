#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Solution18.h"
#include "StringParser.h"

using namespace std;

int Solution18::solve(string &input) {
    StringParser stringParser;
    vector<string> directionVector;
    stringParser.split(directionVector, input, {"\n"});
    pair<int, int> trenchStart = generateDigArea(directionVector);
    visualizeTrench(directionVector, trenchStart);
    for (unsigned int colNum = 0; colNum < topView[0].size(); colNum++) {
            labelExterior(0, colNum);
            labelExterior(topView.size() - 1, colNum);
    }
    for (unsigned int rowNum = 0; rowNum < topView.size(); rowNum++) {
            labelExterior(rowNum, 0);
            labelExterior(rowNum, topView[0].size() - 1);
    }
    return getLagoonSize();
};

pair<int, int> Solution18::generateDigArea(const vector<string> &directionVector) {
    int maxRow = 0;
    int maxCol = 0;
    int currRow = 0;
    int currCol = 0;
    int minRow = 0;
    int minCol = 0;
    StringParser stringParser;
    for (const string &direction : directionVector) {
        vector<string> termVector;
        stringParser.split(termVector, direction, {" "});
        if (termVector[0] == "U") {
            currRow = currRow - stoi(termVector[1]);
            minRow = min(minRow, currRow);
        } else if (termVector[0] == "D") {
            currRow = currRow + stoi(termVector[1]);
            maxRow = max(maxRow, currRow);
        } else if (termVector[0] == "L") {
            currCol = currCol - stoi(termVector[1]);
            minCol = min(minCol, currCol);
        } else if (termVector[0] == "R") {
            currCol = currCol + stoi(termVector[1]);
            maxCol = max(maxCol, currCol);
        }
    }
    topView = vector<vector<char>>(maxRow - minRow + 1, vector<char>(maxCol - minCol + 1, '.'));
    return pair<int, int>(0 - minRow, 0 - minCol);
};

void Solution18::visualizeTrench(const vector<string> &directionVector, const pair<int, int> &trenchStart) {
    int rowNum = trenchStart.first;
    int colNum = trenchStart.second;
    topView[rowNum][colNum] = '#';
    StringParser stringParser;
    for (const string &direction : directionVector) {
        vector<string> termVector;
        stringParser.split(termVector, direction, {" "});
        for (int meters = 0; meters < stoi(termVector[1]); meters++) {
            if (termVector[0] == "U") {
                rowNum--;
            } else if (termVector[0] == "D") {
                rowNum++;
            } else if (termVector[0] == "L") {
                colNum--;
            } else if (termVector[0] == "R") {
                colNum++;
            }
            topView[rowNum][colNum] = '#';
        }
    }
};

void Solution18::labelExterior(int rowNum, int colNum) {
    if (rowNum >= 0 && rowNum < (int) topView.size() && colNum >= 0 && colNum < (int) topView[0].size() && topView[rowNum][colNum] == '.') {
        topView[rowNum][colNum] = 'X';
        labelExterior(rowNum + 1, colNum);
        labelExterior(rowNum - 1, colNum);
        labelExterior(rowNum, colNum + 1);
        labelExterior(rowNum, colNum - 1);
    }
}

int Solution18::getLagoonSize() {
    int size = 0;
    for (unsigned int rowNum = 0; rowNum < topView.size(); rowNum++) {
        for (unsigned int colNum = 0; colNum < topView[0].size(); colNum++) {
            if (topView[rowNum][colNum] != 'X') {
                size++;
            }
        }
    }
    return size;
};