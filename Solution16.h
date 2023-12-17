#ifndef SOLUTION16_H
#define SOLUTION16_H

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution16 {
    public:
        int solve(string& input);

    private:
        int maxEnergized;
        int traceBeamsAndGetEnergized(const vector<vector<char>> &contraption, int beamRow, int beamCol, int beamDirection);
        void processBeamEncounters(char object, const pair<pair<int, int>, int> &nextBeam, stack<pair<pair<int, int>, int>> &toDoBeams);
        void processPositiveMirror(int rowNum, int colNum, int beamDirection, stack<pair<pair<int, int>, int>> &toDoBeams);
        void processNegativeMirror(int rowNum, int colNum, int beamDirection, stack<pair<pair<int, int>, int>> &toDoBeams);
        void processVerticalSplitter(int rowNum, int colNum, int beamDirection, stack<pair<pair<int, int>, int>> &toDoBeams);
        void processHorizontalSplitter(int rowNum, int colNum, int beamDirection, stack<pair<pair<int, int>, int>> &toDoBeams);
        void processEmptySpace(int rowNum, int colNum, int beamDirection, stack<pair<pair<int, int>, int>> &toDoBeams);
};

#endif