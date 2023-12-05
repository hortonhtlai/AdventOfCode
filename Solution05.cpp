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
    for (long long identifier : collection) {
        minNum = min(minNum, identifier);
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
    for (string seed : seedVector) {
        collection.push_back(stoll(seed));
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
        long long source = stoll(termVector[1]);
        long long destination = stoll(termVector[0]);
        long long range = stoll(termVector[2]);
        conversionTable[source] = pair<long long, long long>(range, destination);
    }

    for (unsigned int i = 0; i < collection.size(); i++) {
        long long identifier = collection[i];
        for (auto j = conversionTable.begin(); j != conversionTable.end() && collection[i] == identifier; j++) {
            if (j->first <= identifier && j->first + conversionTable[j->first].first > identifier) {
                collection[i] = identifier - j->first + conversionTable[j->first].second;
            }
        }
    }
}