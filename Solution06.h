#ifndef SOLUTION06_H
#define SOLUTION06_H

#include <string>
#include <vector>

using namespace std;

class Solution06 {
    public:
        int solve(string &input);
    
    private:
        int product;
        vector<int> timeVector;
        vector<int> distanceVector;
        void multiplyWinWays();
};

#endif