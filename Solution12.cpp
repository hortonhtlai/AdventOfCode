#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Solution12.h"
#include "StringParser.h"

using namespace std;

long long Solution12::solve(string &input) {
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
        unfoldConditions(record, sizeVector);
        sum = sum + getNumArrangements(record, sizeVector);
    }
    return sum;
};

long long Solution12::getNumArrangements(string record, vector<int> sizeVector) {
    string stateKey = record;
    for (unsigned int i = 0; i < sizeVector.size(); i++) {
        stateKey = stateKey + "," + to_string(sizeVector[i]);
    }
    if (cache.find(stateKey) == cache.end()) {
        if (record.empty() && sizeVector.empty()) cache[stateKey] = 1;
        else if (record.empty()) cache[stateKey] = 0;
        else if (sizeVector.empty() && record.find("#") == record.npos) cache[stateKey] = 1;
        else if (sizeVector.empty()) cache[stateKey] = 0;
        else {
            long long numIfDot = 0;
            if (record.front() == '.' || record.front() == '?') {
                numIfDot = getNumArrangements(record.substr(1), sizeVector);
            }

            long long numIfHash = 0;
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

            if (record.front() == '.') cache[stateKey] = numIfDot;
            else if (record.front() == '#') cache[stateKey] = numIfHash;
            else cache[stateKey] = numIfDot + numIfHash;
        }
    }
    return cache[stateKey];
};

void Solution12::unfoldConditions(string &record, vector<int> &sizeVector) {
    int recordLength = record.length();
    int groupLength = sizeVector.size();
    for (int i = 0; i < 4; i++) {
        record = record + "?" + record.substr(0, recordLength);
        sizeVector.insert(sizeVector.end(), sizeVector.begin(), sizeVector.begin() + groupLength);
    }
};