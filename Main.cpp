#include <iostream>
#include <string>

#include "Solution15.h"
#include "StringParser.h"

using namespace std;

int main()
{
    string input = R"(rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7)";
    Solution15 solution;
    cout << solution.solve(input);
}