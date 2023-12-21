#include <iostream>
#include <string>

#include "Solution20.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(broadcaster -> a
%a -> inv, con
&inv -> b
%b -> con
&con -> output)";
    Solution20 solution;
    cout << solution.solve(input);
}