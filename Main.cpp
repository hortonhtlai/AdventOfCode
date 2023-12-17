#include <iostream>
#include <string>

#include "Solution16.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(.|...\....
|.-.\.....
.....|-...
........|.
..........
.........\
..../.\\..
.-.-/..|..
.|....-|.\
..//.|....)";
    Solution16 solution;
    cout << solution.solve(input);
}