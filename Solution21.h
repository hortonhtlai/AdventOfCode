#ifndef SOLUTION21_H
#define SOLUTION21_H

#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution21 {
    public:
        int solve(string &input);

    private:
        vector<vector<char>> farmMap;
        set<pair<int, int>> reachedGardenPlots;
        void takeOneStep();
};

#endif