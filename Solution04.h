#ifndef SOLUTION04_H
#define SOLUTION04_H

#include <string>
#include <vector>

using namespace std;

class Solution04 {
    public:
        int solve(string &input);
    
    private:
        int sum;
        void addCardPoints(vector<string> &winningVector, vector<string> &chosenVector);
};

#endif