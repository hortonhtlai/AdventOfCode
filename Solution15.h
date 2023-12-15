#ifndef SOLUTION15_H
#define SOLUTION15_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution15 {
    public:
        int solve(string &input);

    private:
        int sum;
        unordered_map<int, vector<pair<string, int>>> boxes;
        int getHashValue(const string &step);
        void removeLens(vector<string> &termVector);
        void updateLens(vector<string> &termVector);
        void addFocusingPowers();
};

#endif