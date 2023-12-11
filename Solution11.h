#ifndef SOLUTION11_H
#define SOLUTION11_H

#include <string>
#include <vector>

using namespace std;

class Solution11 {
    public:
        int solve(string &input);
    
    private:
        int sum;
        vector<vector<char>> image;
        vector<pair<int, int>> galaxyVector;
        void expandImage();
        void addGalaxyDistance();
};

#endif