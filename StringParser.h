#ifndef STRINGPARSER_H
#define STRINGPARSER_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StringParser {
    public:
        void split(vector<string> &output, const string &input, const vector<string> &delimiters);
        string remove(const string &input, const vector<string> &fillers);
    
    private:
        string check(int index, const string &input, const vector<string> &targets);
};

#endif