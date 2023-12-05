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
        vector<long long> collection;
        void processSection(string &section);
        void setSeed(string &seeds);
        void convertCategory(vector<string> &headedVector);
};

#endif