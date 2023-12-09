#include <iostream>
#include <string>

#include "Solution09.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(0 3 6 9 12 15
1 3 6 10 15 21
10 13 16 21 30 45)";
    Solution09 solution;
    cout << solution.solve(input);
}