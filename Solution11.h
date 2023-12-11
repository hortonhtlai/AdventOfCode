#ifndef SOLUTION11_H
#define SOLUTION11_H

#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution11 {
    public:
        long long solve(string &input);
    
    private:
        long long sum;
        vector<vector<char>> image;
        set<int> galaxyRowSet;
        set<int> galaxyColSet;
        vector<pair<long long, long long>> galaxyVector;
        void expandCoords();
        void addGalaxyDistance();
};

#endif