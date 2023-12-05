#ifndef SOLUTION05_H
#define SOLUTION05_H

#include <string>
#include <vector>

using namespace std;

class Solution05 {
    public:
        long long solve(string &input);

    private:
        long long minNum;
        string category;
        vector<pair<long long, long long>> collection;
        void processSection(string &section);
        void setSeed(string &seeds);
        void convertCategory(vector<string> &headedVector);
        void cutRangeIfNeeded(pair<long long, long long> &identifierRange, const pair<long long, long long> &sourceRange);
};

#endif