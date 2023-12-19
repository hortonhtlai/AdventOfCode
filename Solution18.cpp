#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>

#include "Solution18.h"
#include "StringParser.h"

using namespace std;

long long Solution18::solve(string &input) {
    StringParser stringParser;
    vector<string> instructionVector;
    stringParser.split(instructionVector, input, {"\n"});
    pair<long long, long long> trenchStart = generateDigArea(instructionVector);
    visualizeTrench(instructionVector, trenchStart);
    for (unsigned int colNumCollapsed = 0; colNumCollapsed < topViewCollapsed[0].size(); colNumCollapsed++) {
            labelExterior(0, colNumCollapsed);
            labelExterior(topViewCollapsed.size() - 1, colNumCollapsed);
    }
    for (unsigned int rowNumCollapsed = 0; rowNumCollapsed < topViewCollapsed.size(); rowNumCollapsed++) {
            labelExterior(rowNumCollapsed, 0);
            labelExterior(rowNumCollapsed, topViewCollapsed[0].size() - 1);
    }
    multipleVerticalFactor();
    multiplyHorizontalFactor();
    return getLagoonSize();
};

pair<long long, long long> Solution18::generateDigArea(const vector<string> &instructionVector) {
    long long currRow = 0;
    long long currCol = 0;
    set<long long> rowSet;
    set<long long> colSet;
    rowSet.insert(currRow);
    colSet.insert(currCol);

    StringParser stringParser;
    for (const string &instruction : instructionVector) {
        vector<string> termVector;
        stringParser.split(termVector, instruction, {" ", "#", "(", ")"});
        char direction = termVector[2].back();
        termVector[2].pop_back();
        if (direction == '0') {
            currCol = currCol + stoll(termVector[2], nullptr, 16);
        } else if (direction == '1') {
            currRow = currRow + stoll(termVector[2], nullptr, 16);
        } else if (direction == '2') {
            currCol = currCol - stoll(termVector[2], nullptr, 16);
        } else if (direction == '3') {
            currRow = currRow - stoll(termVector[2], nullptr, 16);
        }
        rowSet.insert(currRow);
        colSet.insert(currCol);
    }

    long long minRow = *rowSet.begin();
    long long minCol = *colSet.begin();

    for (long long rowNum : rowSet) {
        rowVectorExpanded.push_back(rowNum - minRow);
    }
    for (long long colNum : colSet) {
        colVectorExpanded.push_back(colNum - minCol);
    }

    topViewCollapsed = vector<vector<long long>>(2 * rowVectorExpanded.size() - 1, vector<long long>(2 * colVectorExpanded.size() - 1, -1));
    return pair<long long, long long>(0 - minRow, 0 - minCol);
};

void Solution18::visualizeTrench(const vector<string> &instructionVector, const pair<long long, long long> &trenchStart) {
    long long rowNumExpanded = trenchStart.first;
    long long colNumExpanded = trenchStart.second;

    int rowNumCollapsed = 0;
    for (unsigned int i = 0; i < rowVectorExpanded.size(); i++) {
        if (rowVectorExpanded[i] == rowNumExpanded) {
            rowNumCollapsed = i;
        }
    }
    int colNumCollapsed = 0;
    for (unsigned int i = 0; i < colVectorExpanded.size(); i++) {
        if (colVectorExpanded[i] == colNumExpanded) {
            colNumCollapsed = i;
        }
    }

    int currRow = 2 * rowNumCollapsed;
    int currCol = 2 * colNumCollapsed;
    topViewCollapsed[currRow][currCol] = 1;

    StringParser stringParser;
    for (const string &instruction : instructionVector) {
        vector<string> termVector;
        stringParser.split(termVector, instruction, {" ", "#", "(", ")"});
        char direction = termVector[2].back();
        termVector[2].pop_back();
        if (direction == '0') {
            colNumExpanded = colNumExpanded + stoll(termVector[2], nullptr, 16);
            while (colVectorExpanded[colNumCollapsed] < colNumExpanded) {
                colNumCollapsed++;
                currCol++;
                topViewCollapsed[currRow][currCol] = colVectorExpanded[colNumCollapsed] - colVectorExpanded[colNumCollapsed - 1] - 1;
                currCol++;
                topViewCollapsed[currRow][currCol] = 1;
            }
        } else if (direction == '1') {
            rowNumExpanded = rowNumExpanded + stoll(termVector[2], nullptr, 16);
            while (rowVectorExpanded[rowNumCollapsed] < rowNumExpanded) {
                rowNumCollapsed++;
                currRow++;
                topViewCollapsed[currRow][currCol] = rowVectorExpanded[rowNumCollapsed] - rowVectorExpanded[rowNumCollapsed - 1] - 1;
                currRow++;
                topViewCollapsed[currRow][currCol] = 1;
            }
        } else if (direction == '2') {
            colNumExpanded = colNumExpanded - stoll(termVector[2], nullptr, 16);
            while (colVectorExpanded[colNumCollapsed] > colNumExpanded) {
                colNumCollapsed--;
                currCol--;
                topViewCollapsed[currRow][currCol] = colVectorExpanded[colNumCollapsed + 1] - colVectorExpanded[colNumCollapsed] - 1;
                currCol--;
                topViewCollapsed[currRow][currCol] = 1;
            }
        } else if (direction == '3') {
            rowNumExpanded = rowNumExpanded - stoll(termVector[2], nullptr, 16);
            while (rowVectorExpanded[rowNumCollapsed] > rowNumExpanded) {
                rowNumCollapsed--;
                currRow--;
                topViewCollapsed[currRow][currCol] = rowVectorExpanded[rowNumCollapsed + 1] - rowVectorExpanded[rowNumCollapsed] - 1;
                currRow--;
                topViewCollapsed[currRow][currCol] = 1;
            }
        }
    }
};

void Solution18::labelExterior(int rowNum, int colNum) {
    stack<pair<int, int>> frontier;
    frontier.push(pair<int, int>(rowNum, colNum));
    while (!frontier.empty()) {
        pair<int, int> currPosition = frontier.top();
        rowNum = currPosition.first;
        colNum = currPosition.second;
        frontier.pop();
        if (rowNum >= 0 && rowNum < (long long) topViewCollapsed.size() && colNum >= 0 && colNum < (long long) topViewCollapsed[0].size() && topViewCollapsed[rowNum][colNum] == -1) {
            topViewCollapsed[rowNum][colNum] = 0;
            frontier.push(pair<int, int>(rowNum + 1, colNum));
            frontier.push(pair<int, int>(rowNum - 1, colNum));
            frontier.push(pair<int, int>(rowNum, colNum + 1));
            frontier.push(pair<int, int>(rowNum, colNum - 1));
        }
    }
}

void Solution18::multipleVerticalFactor() {
    for (unsigned int colNumCollapsed = 0; colNumCollapsed < topViewCollapsed[0].size(); colNumCollapsed++) {
        long long colFactor = 0;
        for (unsigned int rowNumCollapsed = 0; rowNumCollapsed < topViewCollapsed.size(); rowNumCollapsed++) {
            if (topViewCollapsed[rowNumCollapsed][colNumCollapsed] != 0) {
                if (topViewCollapsed[rowNumCollapsed][colNumCollapsed] > 0 && colFactor == 0) {
                    colFactor = topViewCollapsed[rowNumCollapsed][colNumCollapsed];
                } else if (topViewCollapsed[rowNumCollapsed][colNumCollapsed] < 0) {
                    topViewCollapsed[rowNumCollapsed][colNumCollapsed] = topViewCollapsed[rowNumCollapsed][colNumCollapsed] * colFactor;
                }
            }
        }
    }
};

void Solution18::multiplyHorizontalFactor() {
    for (unsigned int rowNumCollapsed = 0; rowNumCollapsed < topViewCollapsed.size(); rowNumCollapsed++) {    
        long long rowFactor = 0;
        for (unsigned int colNumCollapsed = 0; colNumCollapsed < topViewCollapsed[0].size(); colNumCollapsed++) {
            if (topViewCollapsed[rowNumCollapsed][colNumCollapsed] != 0) {
                if (topViewCollapsed[rowNumCollapsed][colNumCollapsed] > 0 && rowFactor == 0) {
                    rowFactor = topViewCollapsed[rowNumCollapsed][colNumCollapsed];
                } else if (topViewCollapsed[rowNumCollapsed][colNumCollapsed] < 0) {
                    topViewCollapsed[rowNumCollapsed][colNumCollapsed] = topViewCollapsed[rowNumCollapsed][colNumCollapsed] * rowFactor;
                }
            }
        }
    }
};

long long Solution18::getLagoonSize() {
    long long size = 0;
    for (unsigned int rowNumCollapsed = 0; rowNumCollapsed < topViewCollapsed.size(); rowNumCollapsed++) {
        for (unsigned int colNumCollapsed = 0; colNumCollapsed < topViewCollapsed[0].size(); colNumCollapsed++) {
            if (topViewCollapsed[rowNumCollapsed][colNumCollapsed] < 0) {
                size = size - topViewCollapsed[rowNumCollapsed][colNumCollapsed];
            } else if (topViewCollapsed[rowNumCollapsed][colNumCollapsed] > 0) {
                size = size + topViewCollapsed[rowNumCollapsed][colNumCollapsed];
            }
        }
    }
    return size;
};