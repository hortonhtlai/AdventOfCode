#ifndef STRINGSPLITTER_H
#define STRINGSPLITTER_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StringSplitter {
    public:
        void split(vector<string> &output, const string &input, const vector<char> &delimiters);
};

#endif