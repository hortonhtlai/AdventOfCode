#include <iostream>
#include <string>

#include "Solution11.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(...#......
.......#..
#.........
..........
......#...
.#........
.........#
..........
.......#..
#...#.....)";
    Solution11 solution;
    cout << solution.solve(input);
}