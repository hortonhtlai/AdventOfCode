#ifndef SOLUTION10_H
#define SOLUTION10_H

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution10 {
    public:
        int solve(string &input);

    private:
        int loopLength;
        int startRow;
        int startCol;
        int tiles;
        vector<vector<char>> field;
        unordered_set<int> pipeSet;
        void followPipeLoop();
        void initStartPipe(int rowNum, int colNum);
        void followPipePart(vector<pair<int, int>> &output, int rowNum, int colNum);
        void countTiles();
        bool northLinked(int rowNum, int colNum);
        bool southLinked(int rowNum, int colNum);
        bool eastLinked(int rowNum, int colNum);
        bool westLinked(int rowNum, int colNum);
};

#endif