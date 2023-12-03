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
        set<pair<int, int>> symbolSet;
        void generateSchematic(string &input);
        void searchAndClearBorder();
        void AddAndClearNumber(int rowNum, int colNum);
};

#endif