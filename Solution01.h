#ifndef SOLUTION01_H
#define SOLUTION01_H

#include <string>

using namespace std;

class Solution01 {
    public:
        int solve(string &input);

    private:
        int sum;
        void addCaliValue(string &caliDatapt);
        int getDigitIfValid(string &caliDatapt, int index);
};

#endif