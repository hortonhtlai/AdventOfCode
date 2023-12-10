#ifndef SOLUTION10_H
#define SOLUTION10_H

#include <string>
#include <vector>

using namespace std;

class Solution10 {
    public:
        int solve(string &input);

    private:
        int loopLength;
        vector<vector<char>> field;
        pair<int, int> initPipeStart(int rowNum, int colNum);
        void followPipePart(vector<pair<int, int>> &output, int rowNum, int colNum);
        void followPipeLoop(int startRow, int startCol);
};

#endif