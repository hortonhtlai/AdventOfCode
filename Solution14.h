#ifndef SOLUTION14_H
#define SOLUTION14_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution14 {
    public:
        int solve(string &input);

    private:
        int load;
        vector<vector<char>> platform;
        unordered_map<string, int> cache;
        void slideRocksNorth();
        void slideRocksWest();
        void slideRocksSouth();
        void slideRocksEast();
        void addLoad();
};

#endif