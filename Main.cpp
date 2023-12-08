#include <iostream>
#include <string>

#include "Solution08.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(LLR

AAA = (BBB, BBB)
BBB = (AAA, ZZZ)
ZZZ = (ZZZ, ZZZ))";
    Solution08 solution;
    cout << solution.solve(input);
}