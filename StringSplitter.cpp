#include <vector>
#include <string>
#include <algorithm>

#include "StringSplitter.h"

using namespace std;

void StringSplitter::split(vector<string> &output, const string &input, const vector<char> &delimiters) {
    string buffer = "";
    for (unsigned int i = 0; i <= input.length(); i++) {
        if (i == input.length() || find(delimiters.begin(), delimiters.end(), input.at(i)) != delimiters.end()) {
            if (buffer.length() > 0) {
                output.push_back(buffer);
                buffer = "";
            }
        } else {
            buffer = buffer + input.at(i);
        }
    }
};