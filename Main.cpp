#include <iostream>
#include <string>

#include "Solution21.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(...........
.....###.#.
.###.##..#.
..#.#...#..
....#.#....
.##..S####.
.##..#...#.
.......##..
.##.#.####.
.##..##.##.
...........)";
    Solution21 solution;
    cout << solution.solve(input);
}