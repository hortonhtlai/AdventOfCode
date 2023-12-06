#include <iostream>
#include <string>

#include "Solution06.h"
#include "StringSplitter.h"

using namespace std;

int main()
{
    string input = R"(Time:      7  15   30
Distance:  9  40  200)";
    Solution06 solution;
    cout << solution.solve(input);
}