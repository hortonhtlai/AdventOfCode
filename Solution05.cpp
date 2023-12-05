#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "Solution05.h"
#include "StringSplitter.h"

using namespace std;

long long Solution05::solve(string &input) {
    minNum = LONG_LONG_MAX;
    StringSplitter stringSplitter;
    vector<string> sectionVector;
    stringSplitter.split(sectionVector, input, {"\n\n"});
    for (string section : sectionVector) {
        processSection(section);
    }
    for (pair<long long, long long> range : collection) {
        minNum = min(minNum, range.first);
    }
    return minNum;
};

void Solution05::processSection(string &section) {
    StringSplitter stringSplitter;
    vector<string> headeredVector;
    stringSplitter.split(headeredVector, section, {":", "\n"});
    if (headeredVector[0] == "seeds") {
        setSeed(headeredVector[1]);
    } else {
        convertCategory(headeredVector);
    }
};

void Solution05::setSeed(string &seeds) {
    category = "seed";
    StringSplitter stringSplitter;
    vector<string> seedVector;
    stringSplitter.split(seedVector, seeds, {" "});
    for (unsigned int i = 0; i < seedVector.size(); i = i+2) {
        long long identifierBegin = stoll(seedVector[i]);
        long long identifierEnd =identifierBegin + stoll(seedVector[i+1]);
        collection.push_back(pair<long long, long long>(identifierBegin, identifierEnd));
    }
};

void Solution05::convertCategory(vector<string> &headeredVector) {
    StringSplitter stringSplitter;
    vector<string> termVector;
    stringSplitter.split(termVector, headeredVector[0], {"-to-", " "});
    if (termVector[0] == category) {
        category = termVector[1];
    }

    unordered_map<long long, pair<long long, long long>> conversionTable;
    for (unsigned int i = 1; i < headeredVector.size(); i++) {
        termVector = vector<string>();
        stringSplitter.split(termVector, headeredVector[i], {" "});
        long long destination = stoll(termVector[0]);
        long long sourceBegin = stoll(termVector[1]);
        long long sourceEnd = sourceBegin + stoll(termVector[2]);
        conversionTable[destination] = pair<long long, long long>(sourceBegin, sourceEnd);
    }

    for (unsigned int i = 0; i < collection.size(); i++) {
        pair<long long, long long> oldRange = collection[i];
        for (auto j = conversionTable.begin(); j != conversionTable.end() && collection[i] == oldRange; j++) {
            cutRangeIfNeeded(collection[i], conversionTable[j->first]);
            if (conversionTable[j->first].first <= collection[i].first && conversionTable[j->first].second >= collection[i].second) {
                collection[i].first = collection[i].first - conversionTable[j->first].first + j->first;
                collection[i].second = collection[i].second - conversionTable[j->first].first + j->first;
            }
        }
    }
};

void Solution05::cutRangeIfNeeded(pair<long long, long long> &identifierRange, const pair<long long, long long> &sourceRange) {
    if (identifierRange.first < sourceRange.first && identifierRange.second > sourceRange.first) {
        collection.push_back(pair<long long, long long>(identifierRange.first, sourceRange.first));
        identifierRange.first = sourceRange.first;
    }
    if (identifierRange.first < sourceRange.second && identifierRange.second > sourceRange.second) {
        collection.push_back(pair<long long, long long>(sourceRange.second, identifierRange.second));
        identifierRange.second = sourceRange.second;
    }
};