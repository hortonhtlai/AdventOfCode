#ifndef SOLUTION06_H
#define SOLUTION06_H

#include <string>
#include <vector>

using namespace std;

class Solution06 {
    public:
        long long solve(string &input);
    
    private:
        long long product;
        vector<long long> timeVector;
        vector<long long> distanceVector;
        void multiplyWinWays();
};

#endif