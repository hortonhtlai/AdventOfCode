#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "Solution11.h"
#include "StringParser.h"

using namespace std;

long long Solution11::solve(string& input) {
    sum = 0;
    StringParser stringParser;
    stringParser.map(image, input);
    for (unsigned int rowNum = 0; rowNum < image.size(); rowNum++) {
        for (unsigned int colNum = 0; colNum < image[rowNum].size(); colNum++) {
            if (image[rowNum][colNum] == '#') {
                galaxyRowSet.insert(rowNum);
                galaxyColSet.insert(colNum);
                galaxyVector.push_back(pair<int, int>(rowNum, colNum));
            }
        }
    }
    expandCoords();
    addGalaxyDistance();
    return sum;
}

void Solution11::expandCoords() {
    for (pair<long long, long long> &galaxy : galaxyVector) {
        int galaxyRow = galaxy.first;
        for (int i = 0; i < galaxyRow; i++) {
            if (galaxyRowSet.find(i) == galaxyRowSet.end()) {
                galaxy.first = galaxy.first + 100 - 1;
            }
        }
        int galaxyCol = galaxy.second;
        for (int i = 0; i < galaxyCol; i++) {
            if (galaxyColSet.find(i) == galaxyColSet.end()) {
                galaxy.second = galaxy.second + 100 - 1;
            }
        }
    }
};

void Solution11::addGalaxyDistance() {
    for (unsigned int i = 0; i < galaxyVector.size(); i++) {
        for (unsigned int j = i + 1; j < galaxyVector.size(); j++) {
            sum = sum + abs(galaxyVector[i].first - galaxyVector[j].first) + abs(galaxyVector[i].second - galaxyVector[j].second);
        }
    }
};