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
        bool checkHorizontalReflection(const vector<vector<char>> &patternMap, int rowNum);
        bool checkVerticalReflection(const vector<vector<char>> &patternMap, int colNum);
        bool columnsEqual(const vector<vector<char>> &patternMap, int colNum1, int colNum2);
};

#endif