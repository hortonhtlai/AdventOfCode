#include <vector>
#include <string>
#include <algorithm>

#include "StringParser.h"

using namespace std;

void StringParser::split(vector<string> &output, const string &input, const vector<string> &delimiters) {
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

string StringParser::remove(const string &input, const vector<string> &fillers) {
    string buffer = "";
    for (unsigned int i = 0; i < input.length(); i++) {
        string prefix = check(i, input, fillers);
        if (prefix != "") {
            i = i + prefix.length() - 1;
        } else {
            buffer = buffer + input.at(i);
        }
    }
    return buffer;
}

string StringParser::check(int index, const string &input, const vector<string> &targets) {
    if (index >= 0 && index < (int) input.length()) {
        for (unsigned int i = 0; i < targets.size(); i++) {
            if (input.substr(index, targets[i].length()) == targets[i]) {
                return targets[i];
            }
        }
    }
    return "";
};