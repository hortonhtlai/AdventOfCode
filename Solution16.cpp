#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include "Solution16.h"
#include "StringParser.h"

#define UP 2
#define DOWN 3
#define LEFT 5
#define RIGHT 7

using namespace std;

int Solution16::solve(string &input) {
    energized = 0;
    StringParser stringParser;
    vector<vector<char>> contraption;
    stringParser.map(contraption, input);
    traceBeamsAndAddEnergized(contraption);
    return energized;
};

void Solution16::traceBeamsAndAddEnergized(const vector<vector<char>> &contraption) {
    vector<vector<int>> incomingBeams;
    for (unsigned int rowNum = 0; rowNum < contraption.size(); rowNum++) {
        vector<int> row;
        for (unsigned int colNum = 0; colNum < contraption[0].size(); colNum++) {
            row.push_back(1);
        }
        incomingBeams.push_back(row);
    }

    stack<pair<pair<int, int>, int>> toDoBeams;
    toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(0, 0), RIGHT));

    while (!toDoBeams.empty()) {
        pair<pair<int, int>, int> nextBeam = toDoBeams.top();
        toDoBeams.pop();
        if (nextBeam.first.first >= 0 && nextBeam.first.first < (int) contraption.size() 
        && nextBeam.first.second >= 0 && nextBeam.first.second < (int) contraption[0].size()) {
            int existingBeams = incomingBeams[nextBeam.first.first][nextBeam.first.second];
            if (existingBeams % nextBeam.second != 0) {
                if (existingBeams == 1) {
                    energized++;
                }
                incomingBeams[nextBeam.first.first][nextBeam.first.second] = existingBeams * nextBeam.second;
                processBeamEncounters(contraption[nextBeam.first.first][nextBeam.first.second], nextBeam, toDoBeams);
            }
        }
    }
};

void Solution16::processBeamEncounters(char object, const pair<pair<int, int>, int> &nextBeam, stack<pair<pair<int, int>, int>> &toDoBeams) {
    int rowNum = nextBeam.first.first;
    int colNum = nextBeam.first.second;
    int beamDirection = nextBeam.second;
    switch (object) {
        case '/':
            processPositiveMirror(rowNum, colNum, beamDirection, toDoBeams);
            break;
        case '\\':
            processNegativeMirror(rowNum, colNum, beamDirection, toDoBeams);
            break;
        case '|':
            processVerticalSplitter(rowNum, colNum, beamDirection, toDoBeams);
            break;
        case '-':
            processHorizontalSplitter(rowNum, colNum, beamDirection, toDoBeams);
            break;
        default:
            processEmptySpace(rowNum, colNum, beamDirection, toDoBeams);
    }
};

void Solution16::processPositiveMirror(int rowNum, int colNum, int beamDirection, stack<pair<pair<int, int>, int>> &toDoBeams) {
    switch (beamDirection) {
        case UP:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum, colNum + 1), RIGHT));
            break;
        case DOWN:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum, colNum - 1), LEFT));
            break;
        case LEFT:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum + 1, colNum), DOWN));
            break;
        default:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum - 1, colNum), UP));
    }
};

void Solution16::processNegativeMirror(int rowNum, int colNum, int beamDirection, stack<pair<pair<int, int>, int>> &toDoBeams) {
    switch (beamDirection) {
        case UP:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum, colNum - 1), LEFT));            
            break;
        case DOWN:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum, colNum + 1), RIGHT));
            break;
        case LEFT:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum - 1, colNum), UP));
            break;
        default:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum + 1, colNum), DOWN));
    }
};

void Solution16::processVerticalSplitter(int rowNum, int colNum, int beamDirection, stack<pair<pair<int, int>, int>> &toDoBeams) {
    switch (beamDirection) {
        case UP:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum - 1, colNum), UP));
            break;
        case DOWN:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum + 1, colNum), DOWN));
            break;
        default:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum - 1, colNum), UP));
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum + 1, colNum), DOWN));
    }
};

void Solution16::processHorizontalSplitter(int rowNum, int colNum, int beamDirection, stack<pair<pair<int, int>, int>> &toDoBeams) {
    switch (beamDirection) {
        case LEFT:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum, colNum - 1), LEFT));
            break;
        case RIGHT:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum, colNum + 1), RIGHT));
            break;
        default:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum, colNum - 1), LEFT));
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum, colNum + 1), RIGHT));
    }
};

void Solution16::processEmptySpace(int rowNum, int colNum, int beamDirection, stack<pair<pair<int, int>, int>> &toDoBeams) {
    switch (beamDirection) {
        case UP:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum - 1, colNum), UP));
            break;
        case DOWN:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum + 1, colNum), DOWN));
            break;
        case LEFT:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum, colNum - 1), LEFT));
            break;
        default:
            toDoBeams.push(pair<pair<int, int>, int>(pair<int, int>(rowNum, colNum + 1), RIGHT));
    }
};