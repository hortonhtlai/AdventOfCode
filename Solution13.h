#ifndef SOLUTION13_H
#define SOLUTION13_H

#include <string>
#include <vector>

using namespace std;

class Solution13 {
    public:
        int solve(string &input);
    
    private:
        int summary;
        void findAndAddReflection(const vector<vector<char>> &patternMap);
        int getDiffIfHorizontalReflection(const vector<vector<char>> &patternMap, int rowNum);
        int getDiffIfRowsEqual(const vector<vector<char>> &patternMap, int rowNum1, int rowNum2);
        int getDiffIfVerticalReflection(const vector<vector<char>> &patternMap, int colNum);
        int getDiffIfColsEqual(const vector<vector<char>> &patternMap, int colNum1, int colNum2);
};

#endif