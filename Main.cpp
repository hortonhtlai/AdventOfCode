#include <iostream>
#include <string>

#include "Solution01.h"
#include "StringSplitter.h"

using namespace std;

int main()
{
    string input = R"(two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen)";
    Solution01 solution;
    cout << solution.solve(input);
}