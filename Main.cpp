#include <iostream>
#include <string>

#include "Solution01.h"
#include "StringSplitter.h"

using namespace std;

int main()
{
    string input = R"(1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet)";
    Solution01 solution;
    cout << solution.solve(input);
}