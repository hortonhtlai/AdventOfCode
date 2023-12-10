#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

#include "Solution10.h"
#include "StringParser.h"

using namespace std;

int Solution10::solve(string &input) {
    loopLength = 0;
    tiles = 0;
    StringParser stringParser;
    stringParser.map(field, input);
    for (unsigned int rowNum = 0; rowNum < field.size() && loopLength == 0; rowNum++) {
        for (unsigned int colNum = 0; colNum < field[rowNum].size() && loopLength == 0; colNum++) {
            if (field[rowNum][colNum] == 'S') {
                startRow = rowNum;
                startCol = colNum;
                followPipeLoop();
            }
        }
    }
    countTiles();
    return tiles;
};

void Solution10::followPipeLoop() {
    initStartPipe(startRow, startCol);
    int prevRow = startRow;
    int prevCol = startCol;
    int currRow = startRow;
    int currCol = startCol;
    while (loopLength == 0 || currRow != startRow || currCol != startCol) {
        pipeSet.insert(currRow * field[0].size() + currCol);
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

void Solution10::initStartPipe(int startRow, int startCol) {
    bool north = false;
    bool south = false;
    bool east = false;
    bool west = false;
    if (startRow > 0) {
        north = southLinked(startRow - 1, startCol);
    }
    if (startRow < (int) field.size() - 1) {
        south = northLinked(startRow + 1, startCol);
    }
    if (startCol > 0) {
        west = eastLinked(startRow, startCol - 1);
    }
    if (startCol < (int) field[startRow].size() - 1) {
        east = westLinked(startRow, startCol + 1);
    }
    if (north && south) field[startRow][startCol] = '|';
    if (east && west) field[startRow][startCol] = '-';
    if (north && east) field[startRow][startCol] = 'L';
    if (north && west) field[startRow][startCol] = 'J';
    if (south && west) field[startRow][startCol] = '7';
    if (south && east) field[startRow][startCol] = 'F';
}

void Solution10::followPipePart(vector<pair<int, int>> &output, int rowNum, int colNum) {
    if (northLinked(rowNum, colNum)) {
        output.push_back(pair<int, int>(rowNum - 1, colNum));
    }
    if (southLinked(rowNum, colNum)) {
        output.push_back(pair<int, int>(rowNum + 1, colNum));
    }
    if (westLinked(rowNum, colNum)) {
        output.push_back(pair<int, int>(rowNum, colNum - 1));
    }
    if (eastLinked(rowNum, colNum)) {
        output.push_back(pair<int, int>(rowNum, colNum + 1));
    }
};

void Solution10::countTiles() {
    for (unsigned int rowNum = 0; rowNum < field.size(); rowNum++) {
        bool enclosed = false;
        bool north = false;
        bool south = false;
        for (unsigned int colNum = 0; colNum < field[rowNum].size(); colNum++) {
            if (pipeSet.find(rowNum * field[0].size() + colNum) == pipeSet.end() && enclosed == true) {
                tiles++;
            } else if (pipeSet.find(rowNum * field[0].size() + colNum) != pipeSet.end()) {
                if (!westLinked(rowNum, colNum)) {
                    north = false;
                    south = false;
                }
                if (northLinked(rowNum, colNum)) {
                    north = true;
                }
                if (southLinked(rowNum, colNum)) {
                    south = true;
                }
                if (north && south) {
                    enclosed = !enclosed;
                }
            }
        }
    }
}

bool Solution10::northLinked(int rowNum, int colNum) {
    return field[rowNum][colNum] == '|' || field[rowNum][colNum] == 'L' || field[rowNum][colNum] == 'J';
}

bool Solution10::southLinked(int rowNum, int colNum) {
    return field[rowNum][colNum] == '|' || field[rowNum][colNum] == '7' || field[rowNum][colNum] == 'F';
}

bool Solution10::eastLinked(int rowNum, int colNum) {
    return field[rowNum][colNum] == '-' || field[rowNum][colNum] == 'L' || field[rowNum][colNum] == 'F';
}

bool Solution10::westLinked(int rowNum, int colNum) {
    return field[rowNum][colNum] == '-' || field[rowNum][colNum] == 'J' || field[rowNum][colNum] == '7';
}