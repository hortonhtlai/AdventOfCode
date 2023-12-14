#ifndef SOLUTION14_H
#define SOLUTION14_H

#include <string>
#include <vector>

using namespace std;

class Solution14 {
    public:
        int solve(string &input);

    private:
        int load;
        vector<vector<char>> platform;
        void slideRockAndAddLoad(int rowNum, int colNum);
};

#endif