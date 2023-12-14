#include <iostream>
#include <string>
#include <vector>

#include "Solution14.h"
#include "StringParser.h"

using namespace std;

int Solution14::solve(string &input) {
    load = 0;
    StringParser stringParser;
    stringParser.map(platform, input);
    for (unsigned int rowNum = 0; rowNum < platform.size(); rowNum++) {
        for (unsigned int colNum = 0; colNum < platform[0].size(); colNum++) {
            if (platform[rowNum][colNum] == 'O') {
                slideRockAndAddLoad(rowNum, colNum);
            }
        }
    }
    return load;
};

void Solution14::slideRockAndAddLoad(int rowNum, int colNum) {
    platform[rowNum][colNum] = '.';
    while (rowNum > 0 && platform[rowNum - 1][colNum] == '.') {
        rowNum--;
    }
    platform[rowNum][colNum] = 'O';
    load = load + platform.size() - rowNum;
}