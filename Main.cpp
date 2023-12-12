#include <iostream>
#include <string>

#include "Solution12.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(???.### 1,1,3
.??..??...?##. 1,1,3
?#?#?#?#?#?#?#? 1,3,1,6
????.#...#... 4,1,1
????.######..#####. 1,6,5
?###???????? 3,2,1)";
    Solution12 solution;
    cout << solution.solve(input);
}