#include <iostream>
#include <string>

#include "Solution08.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(LR

11A = (11B, XXX)
11B = (XXX, 11Z)
11Z = (11B, XXX)
22A = (22B, XXX)
22B = (22C, 22C)
22C = (22Z, 22Z)
22Z = (22B, 22B)
XXX = (XXX, XXX))";
    Solution08 solution;
    cout << solution.solve(input);
}