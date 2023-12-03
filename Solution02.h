#ifndef SOLUTION02_H
#define SOLUTION02_H

#include <vector>
#include <string>

using namespace std;

class Solution02 {
    public:
        int solve(string &input);
        
    private:
        int sum;
        int gameNum;
        int redNum;
        int greenNum;
        int blueNum;
        void processPairValues(vector<string> &termVector);
        void verifyGame();
        void addGamePower();
};

#endif