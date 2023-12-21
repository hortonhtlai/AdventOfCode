#include <iostream>
#include <string>
#include <vector>

#include "Solution21.h"
#include "StringParser.h"

using namespace std;

int Solution21::solve(string &input) {
    StringParser stringParser;
    stringParser.map(farmMap, input);

    for (unsigned int rowNum = 0; rowNum < farmMap.size(); rowNum++) {
        for (unsigned int colNum = 0; colNum < farmMap[0].size(); colNum++) {
            if (farmMap[rowNum][colNum] == 'S') {
                reachedGardenPlots.insert(pair<int, int>(rowNum, colNum));
            }
        }
    }

    for (int stepNum = 0; stepNum < 6; stepNum++) {
        takeOneStep();
    }

    return reachedGardenPlots.size();
};

void Solution21::takeOneStep() {
    set<pair<int, int>> nextGardenPlots;
    for (auto setIterator = reachedGardenPlots.begin(); setIterator != reachedGardenPlots.end(); setIterator++) {
        int rowNum = setIterator->first;
        int colNum = setIterator->second;
        
        if (rowNum > 0 && (farmMap[rowNum - 1][colNum] == '.' || farmMap[rowNum - 1][colNum] == 'S')) {
            nextGardenPlots.insert(pair<int, int>(rowNum - 1, colNum));
        }
        if (rowNum < (int) farmMap.size() - 1 && (farmMap[rowNum + 1][colNum] == '.' || farmMap[rowNum + 1][colNum] == 'S')) {
            nextGardenPlots.insert(pair<int, int>(rowNum + 1, colNum));
        }
        if (colNum > 0 && (farmMap[rowNum][colNum - 1] == '.' || farmMap[rowNum][colNum - 1] == 'S')) {
            nextGardenPlots.insert(pair<int, int>(rowNum, colNum - 1));
        }
        if (colNum < (int) farmMap[0].size() - 1 && (farmMap[rowNum][colNum + 1] == '.' || farmMap[rowNum][colNum + 1] == 'S')) {
            nextGardenPlots.insert(pair<int, int>(rowNum, colNum + 1));
        }
    }
    reachedGardenPlots = set<pair<int, int>>(nextGardenPlots);
};