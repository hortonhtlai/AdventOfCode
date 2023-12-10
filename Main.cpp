#include <iostream>
#include <string>

#include "Solution10.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(..F7.
.FJ|.
SJ.L7
|F--J
LJ...)";
    Solution10 solution;
    cout << solution.solve(input);
}