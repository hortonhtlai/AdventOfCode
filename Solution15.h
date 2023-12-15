#ifndef SOLUTION15_H
#define SOLUTION15_H

#include <string>

using namespace std;

class Solution15 {
    public:
        int solve(string &input);

    private:
        int sum;
        void addHashValue(const string &step);
};

#endif