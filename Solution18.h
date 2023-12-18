#ifndef SOLUTION18_H
#define SOLUTION18_H

#include <string>
#include <vector>

using namespace std;

class Solution18 {
    public:
        int solve(string &input);
    
    private:
        vector<vector<char>> topView;
        pair<int, int> generateDigArea(const vector<string> &directionVector);
        void visualizeTrench(const vector<string> &directionVector, const pair<int, int> &trenchStart);
        void labelExterior(int rowNum, int colNum);
        int getLagoonSize();
};

#endif