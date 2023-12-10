#include <iostream>
#include <string>
#include <vector>

#include "Solution10.h"
#include "StringParser.h"

using namespace std;

int Solution10::solve(string &input) {
    loopLength = 0;
    StringParser stringParser;
    stringParser.map(field, input);
    for (unsigned int rowNum = 0; rowNum < field.size() && loopLength == 0; rowNum++) {
        for (unsigned int colNum = 0; colNum < field[rowNum].size() && loopLength == 0; colNum++) {
            if (field[rowNum][colNum] == 'S') {
                followPipeLoop(rowNum, colNum);
            }
        }
    }
    return loopLength / 2;
};

void Solution10::followPipeLoop(int startRow, int startCol) {
    pair<int, int> initPipe = initPipeStart(startRow, startCol);
    int prevRow = startRow;
    int prevCol = startCol;
    int currRow = initPipe.first;
    int currCol = initPipe.second;
    loopLength = 1;
    while (field[currRow][currCol] != 'S') {
        vector<pair<int, int>> linkedPipes;
        followPipePart(linkedPipes, currRow, currCol);
        int nextRow;
        int nextCol;
        if (linkedPipes[0].first != prevRow || linkedPipes[0].second != prevCol) {
            nextRow = linkedPipes[0].first;
            nextCol = linkedPipes[0].second;
        } else {
            nextRow = linkedPipes[1].first;
            nextCol = linkedPipes[1].second;  
        }
        prevRow = currRow;
        prevCol = currCol;
        currRow = nextRow;
        currCol = nextCol;
        loopLength++;
    }
};

pair<int, int> Solution10::initPipeStart(int startRow, int startCol) {
    if (startRow > 0) {
        if (field[startRow - 1][startCol] == '|' || field[startRow - 1][startCol] == '7' || field[startRow - 1][startCol] == 'F') {
            return pair<int, int>(startRow - 1, startCol);
        }
    }
    if (startRow < (int) field.size() - 1) {
        if (field[startRow + 1][startCol] == '|' || field[startRow + 1][startCol] == 'L' || field[startRow + 1][startCol] == 'J') {
            return pair<int, int>(startRow + 1, startCol);
        }
    }
    if (startCol > 0) {
        if (field[startRow][startCol - 1] == '-' || field[startRow][startCol - 1] == 'L' || field[startRow][startCol - 1] == 'F') {
            return pair<int, int>(startRow, startCol - 1);
        }
    }
    return pair<int, int>(startRow, startCol + 1);
}

void Solution10::followPipePart(vector<pair<int, int>> &output, int rowNum, int colNum) {
    if (field[rowNum][colNum] == '|' || field[rowNum][colNum] == 'L' || field[rowNum][colNum] == 'J') {
        output.push_back(pair<int, int>(rowNum - 1, colNum));
    }
    if (field[rowNum][colNum] == '|' || field[rowNum][colNum] == '7' || field[rowNum][colNum] == 'F') {
        output.push_back(pair<int, int>(rowNum + 1, colNum));
    }
    if (field[rowNum][colNum] == '-' || field[rowNum][colNum] == 'J' || field[rowNum][colNum] == '7') {
        output.push_back(pair<int, int>(rowNum, colNum - 1));
    }
    if (field[rowNum][colNum] == '-' || field[rowNum][colNum] == 'L' || field[rowNum][colNum] == 'F') {
        output.push_back(pair<int, int>(rowNum, colNum + 1));
    }
};