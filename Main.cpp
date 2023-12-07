#include <iostream>
#include <string>

#include "Solution07.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(32T3K 765
T55J5 684
KK677 28
KTJJT 220
QQQJA 483)";
    Solution07 solution;
    cout << solution.solve(input);
}