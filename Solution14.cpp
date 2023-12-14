#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Solution14.h"
#include "StringParser.h"

using namespace std;

int Solution14::solve(string &input) {
    load = 0;
    StringParser stringParser;
    stringParser.map(platform, input);
    vector<vector<char>> oldPlatform = platform;
    for (unsigned int i = 0; i < 1000000000; i++) {
        slideRocksNorth();
        slideRocksWest();
        slideRocksSouth();
        slideRocksEast();
        string stateKey = "";
        for (unsigned int rowNum = 0; rowNum < platform.size(); rowNum++) {
            for (unsigned int colNum = 0; colNum < platform[0].size(); colNum++) {
                stateKey = stateKey + platform[rowNum][colNum];
            }
        }
        if (cache.find(stateKey) == cache.end()) {
            cache[stateKey] = i;
        } else {
            int cycle = i - cache[stateKey];
            i = 1000000000 - (1000000000 - i) % cycle;
        }
    }
    addLoad();
    return load;
};

void Solution14::slideRocksNorth() {
    for (unsigned int rowNum = 0; rowNum < platform.size(); rowNum++) {
        for (unsigned int colNum = 0; colNum < platform[0].size(); colNum++) {
            if (platform[rowNum][colNum] == 'O') {
                platform[rowNum][colNum] = '.';
                int newRow = rowNum;
                while (newRow > 0 && platform[newRow - 1][colNum] == '.') {
                    newRow--;
                }
                platform[newRow][colNum] = 'O';
            }
        }
    }
}

void Solution14::slideRocksWest() {
    for (unsigned int colNum = 0; colNum < platform[0].size(); colNum++) {
        for (unsigned int rowNum = 0; rowNum < platform.size(); rowNum++) {
            if (platform[rowNum][colNum] == 'O') {
                platform[rowNum][colNum] = '.';
                int newCol = colNum;
                while (newCol > 0 && platform[rowNum][newCol - 1] == '.') {
                    newCol--;
                }
                platform[rowNum][newCol] = 'O';
            }
        }
    }
}

void Solution14::slideRocksSouth() {
    for (int rowNum = (int) platform.size() - 1; rowNum >= 0; rowNum--) {
        for (unsigned int colNum = 0; colNum < platform[0].size(); colNum++) {
            if (platform[rowNum][colNum] == 'O') {
                platform[rowNum][colNum] = '.';
                unsigned int newRow = rowNum;
                while (newRow < platform.size() - 1 && platform[newRow + 1][colNum] == '.') {
                    newRow++;
                }
                platform[newRow][colNum] = 'O';
            }
        }
    }
}

void Solution14::slideRocksEast() {
    for (int colNum = (int) platform[0].size() - 1; colNum >= 0; colNum--) {
        for (unsigned int rowNum = 0; rowNum < platform.size(); rowNum++) {
            if (platform[rowNum][colNum] == 'O') {
                platform[rowNum][colNum] = '.';
                unsigned int newCol = colNum;
                while (newCol < platform[0].size() - 1 && platform[rowNum][newCol + 1] == '.') {
                    newCol++;
                }
                platform[rowNum][newCol] = 'O';
            }
        }
    }
}

void Solution14::addLoad() {
    for (unsigned int rowNum = 0; rowNum < platform.size(); rowNum++) {
        for (unsigned int colNum = 0; colNum < platform[0].size(); colNum++) {
            if (platform[rowNum][colNum] == 'O') {
                load = load + platform.size() - rowNum;
            }
        }
    }
}