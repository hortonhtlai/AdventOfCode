#ifndef SOLUTION12_H
#define SOLUTION12_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution12 {
    public:
        long long solve(string &input);
    
    private:
        long long sum;
        unordered_map<string, long long> cache;
        long long getNumArrangements(string record, vector<int> sizeVector);
        void unfoldConditions(string &record, vector<int> &sizeVector);
};

#endif