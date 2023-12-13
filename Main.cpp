#include <iostream>
#include <string>

#include "Solution13.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(#.##..##.
..#.##.#.
##......#
##......#
..#.##.#.
..##..##.
#.#.##.#.

#...##..#
#....#..#
..##..###
#####.##.
#####.##.
..##..###
#....#..#)";
    Solution13 solution;
    cout << solution.solve(input);
}