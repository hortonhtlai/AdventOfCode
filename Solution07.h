#ifndef SOLUTION07_H
#define SOLUTION07_H

#include <string>
#include <vector>

using namespace std;

class Solution07 {
    public:
        int solve(string &input);

    private:
        int sum;
        vector<pair<string, int>> pairs;
};

#endif