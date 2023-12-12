#include <iostream>
#include <string>
#include <vector>

#include "Solution12.h"
#include "StringParser.h"

using namespace std;

int Solution12::solve(string &input) {
    sum = 0;
    StringParser stringParser;
    vector<string> rowVector;
    stringParser.split(rowVector, input, {"\n"});
    for (string row : rowVector) {
        vector<string> formatVector;
        stringParser.split(formatVector, row, {" "});
        string record = formatVector[0];
        vector<string> groupVector;
        stringParser.split(groupVector, formatVector[1], {","});
        vector<int> sizeVector;
        for (string group : groupVector) {
            sizeVector.push_back(stoi(group));
        }
        sum = sum + getNumArrangements(record, sizeVector);
    }
    return sum;
};

int Solution12::getNumArrangements(string record, vector<int> sizeVector) {
    if (record.empty() && sizeVector.empty()) return 1;
    if (record.empty()) return 0;
    if (sizeVector.empty() && record.find("#") == record.npos) return 1;
    if (sizeVector.empty()) return 0;

    int numIfDot = 0;
    if (record.front() == '.' || record.front() == '?') {
        numIfDot = getNumArrangements(record.substr(1), sizeVector);
    }

    int numIfHash = 0;
    if (record.front() == '#' || record.front() == '?') {
        unsigned int size = sizeVector.front();
        string group = record.substr(0, size);
        if (record.length() == size && group.find('.') == group.npos) {
            sizeVector.erase(sizeVector.begin());
            numIfHash = getNumArrangements(record.substr(size), sizeVector);;
        } else if (record.length() > size && group.find('.') == group.npos && record.at(size) != '#') {
            sizeVector.erase(sizeVector.begin());
            numIfHash = getNumArrangements(record.substr(size + 1), sizeVector);
        }
    }

    if (record.front() == '.') return numIfDot;
    if (record.front() == '#') return numIfHash;
    return numIfDot + numIfHash;
};