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

void StringParser::map(vector<vector<char>> &output, const string &input) {
    vector<char> buffer;
    int rowNum = 0;
    int colNum = 0;
    for (unsigned int i = 0; i <= input.length(); i++) {
        if (i == input.length() || input.at(i) == '\n') {
            output.push_back(buffer);
            buffer = vector<char>();
            rowNum++;
            colNum = 0;
        } else {
            buffer.push_back(input.at(i));
            colNum++;
        }
    }
};

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