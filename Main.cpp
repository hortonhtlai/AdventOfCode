#include <iostream>
#include <string>

#include "Solution03.h"
#include "StringSplitter.h"

using namespace std;

int main()
{
    string input = R"(467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..)";
    Solution03 solution;
    cout << solution.solve(input);
}