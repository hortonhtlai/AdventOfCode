#include <iostream>
#include <string>

#include "Solution14.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(O....#....
O.OO#....#
.....##...
OO.#O....O
.O.....O#.
O.#..O.#.#
..O..#O..O
.......O..
#....###..
#OO..#....)";
    Solution14 solution;
    cout << solution.solve(input);
}