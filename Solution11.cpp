#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

#include "Solution11.h"
#include "StringParser.h"

using namespace std;

int Solution11::solve(string& input) {
    sum = 0;
    StringParser stringParser;
    stringParser.map(image, input);
    expandImage();
    for (unsigned int rowNum = 0; rowNum < image.size(); rowNum++) {
        for (unsigned int colNum = 0; colNum < image[rowNum].size(); colNum++) {
            if (image[rowNum][colNum] == '#') {
                galaxyVector.push_back(pair<int, int>(rowNum, colNum));
            }
        }
    }
    addGalaxyDistance();
    return sum;
}

void Solution11::expandImage() {
    unordered_set<int> galaxyRows;
    unordered_set<int> galaxyCols;
    for (unsigned int rowNum = 0; rowNum < image.size(); rowNum++) {
        for (unsigned int colNum = 0; colNum < image[rowNum].size(); colNum++) {
            if (image[rowNum][colNum] == '#') {
                galaxyRows.insert(rowNum);
                galaxyCols.insert(colNum);
            }
        }
    }
    int imageRows = image.size();
    int imageCols = image[0].size();
    for (int rowNum = imageRows - 1; rowNum >= 0; rowNum--) {
        if (galaxyRows.find(rowNum) == galaxyRows.end()) {
            image.insert(image.begin() + rowNum, vector<char>(imageCols, '.'));
        }
    }
    for (int colNum = imageCols - 1; colNum >= 0; colNum--) {
        if (galaxyCols.find(colNum) == galaxyCols.end()) {
            for (unsigned int rowNum = 0; rowNum < image.size(); rowNum++) {
                image[rowNum].insert(image[rowNum].begin() + colNum, '.');
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