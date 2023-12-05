#include <vector>
#include <string>
#include <algorithm>

#include "StringSplitter.h"

using namespace std;

void StringSplitter::split(vector<string> &output, const string &input, const vector<string> &delimiters) {
    string buffer = "";
    for (unsigned int i = 0; i <= input.length(); i++) {
        string prefix = check(i, input, delimiters);
        if (i == input.length() || prefix != "") {
            if (buffer.length() > 0) {
                output.push_back(buffer);
                buffer = "";
            }
            if (prefix != "") {
                i = i + prefix.length() - 1;
            }
        } else {
            buffer = buffer + input.at(i);
        }
    }
};

string StringSplitter::check(int index, const string &input, const vector<string> &delimiters) {
    if (index >= 0 && index < input.length()) {
        for (int i = 0; i < delimiters.size(); i++) {
            if (input.substr(index, delimiters[i].length()) == delimiters[i]) {
                return delimiters[i];
            }
        }
    }
    return "";
};