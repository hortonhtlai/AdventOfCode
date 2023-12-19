#ifndef SOLUTION18_H
#define SOLUTION18_H

#include <string>
#include <vector>

using namespace std;

class Solution18 {
    public:
        long long solve(string &input);
    
    private:
        vector<long long> rowVectorExpanded;
        vector<long long> colVectorExpanded;
        vector<vector<long long>> topViewCollapsed;
        pair<long long, long long> generateDigArea(const vector<string> &instructionVector);
        void visualizeTrench(const vector<string> &instructionVector, const pair<long long, long long> &trenchStart);
        void labelExterior(int rowNum, int colNum);
        void multipleVerticalFactor();
        void multiplyHorizontalFactor();
        long long getLagoonSize();
};

#endif