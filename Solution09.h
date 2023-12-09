#ifndef SOLUTION09_H
#define SOLUTION09_H

#include <string>
#include <vector>

using namespace std;

class Solution09 {
    public:
        int solve(string &input);

    private:
        int sum;
        void addNextPrediction(vector<string> &readingVector);
};

#endif