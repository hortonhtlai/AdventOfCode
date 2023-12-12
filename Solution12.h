#ifndef SOLUTION12_H
#define SOLUTION12_H

#include <string>
#include <vector>

using namespace std;

class Solution12 {
    public:
        int solve(string &input);
    
    private:
        int sum;
        int getNumArrangements(string record, vector<int> groupVector);
};

#endif