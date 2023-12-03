#ifndef SOLUTION03_H
#define SOLUTION03_H

#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution03 {
    public:
        int solve(string &input);

    private:
        int sum;
        vector<vector<char>> schematic;
        set<pair<int, int>> gearSet;
        void generateSchematic(string &input);
        void searchBorderAndAddIfGear();
        int getPartNum(vector<vector<bool>> &border, int gearRow, int gearCol, int rowDiff, int colDiff);
};

#endif