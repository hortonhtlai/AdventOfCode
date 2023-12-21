#include <iostream>
#include <string>
#include <vector>

#include "Solution20.h"
#include "StringParser.h"

using namespace std;

int Solution20::solve(string &input) {
    numLowPulse = 0;
    numHighPulse = 0;
    StringParser stringParser;
    vector<string> moduleVector;
    stringParser.split(moduleVector, input, {"\n"});
    for (const string &module : moduleVector) {
        vector<string> termVector;
        stringParser.split(termVector, module, {"->", " ", ","});
        noteModuleInfo(termVector);
    }
    initConjunctionMemory();
    for (int i = 0; i < 1000; i++) {
        pressButton();
    }
    return numLowPulse * numHighPulse;
};

void Solution20::noteModuleInfo(const vector<string> &termVector) {
    string moduleName;
    if (termVector[0].at(0) == '%') {
        moduleName = termVector[0].substr(1);
        moduleTypeMap[moduleName] = "flipflop";
        moduleStateMap[moduleName] = "off";
    } else if (termVector[0].at(0) == '&') {
        moduleName = termVector[0].substr(1);
        moduleTypeMap[moduleName] = "conjunction";
        moduleStateMap[moduleName] = "low";
    } else {
        moduleName = termVector[0];
        moduleTypeMap[moduleName] = "broadcaster";
    }
    moduleEffectMap[moduleName] = vector<string>();
    for (unsigned int i = 1; i < termVector.size(); i++) {
        moduleEffectMap[moduleName].push_back(termVector[i]);
    }
};

void Solution20::initConjunctionMemory() {
    for (auto effectIterator = moduleEffectMap.begin(); effectIterator != moduleEffectMap.end(); effectIterator++) {
        for (const string &destination : effectIterator->second) {
            if (moduleTypeMap[destination] == "conjunction") {
                conjunctionLowPulseInputs[destination].insert(effectIterator->first);
            }
        }
    }
};

void Solution20::pressButton() {
    queue<vector<string>> processQueue;
    processQueue.push({"button", "low", "broadcaster"});

    while (!processQueue.empty()) {
        string currSource = processQueue.front()[0];
        string currPulse = processQueue.front()[1];
        string currDestination = processQueue.front()[2];
        processQueue.pop();
        cout << currSource << " " << currPulse << " " << currDestination << endl;

        if (currPulse == "low") {
            numLowPulse++;
        } else {
            numHighPulse++;
        }

        if (moduleTypeMap[currDestination] == "flipflop") {
            handleFlipFlop(currPulse, currDestination, processQueue);
        } else if (moduleTypeMap[currDestination] == "conjunction") {
            handleConjunction(currSource, currPulse, currDestination, processQueue);
        } else {
            for (unsigned int destination = 0; destination < moduleEffectMap[currDestination].size(); destination++) {
                processQueue.push({currDestination, currPulse, moduleEffectMap[currDestination][destination]});
            }
        }
    }
};

void Solution20::handleFlipFlop(const string &currPulse, const string &currDestination, queue<vector<string>> &processQueue) {
    if (currPulse == "low") {
        string nextPulse;
        if (moduleStateMap[currDestination] == "off") {
            moduleStateMap[currDestination] = "on";
            nextPulse = "high";
        } else {
            moduleStateMap[currDestination] = "off";
            nextPulse = "low";
        }

        for (unsigned int destination = 0; destination < moduleEffectMap[currDestination].size(); destination++) {
            processQueue.push({currDestination, nextPulse, moduleEffectMap[currDestination][destination]});
        }
    }


};

void Solution20::handleConjunction(const string &currSource, const string &currPulse, const string &currDestination, queue<vector<string>> &processQueue) {
    if (currPulse == "high") {
        conjunctionLowPulseInputs[currDestination].erase(currSource);
    } else {
        conjunctionLowPulseInputs[currDestination].insert(currSource);
    }

    string nextPulse;
    if (conjunctionLowPulseInputs[currDestination].empty()) {
        nextPulse = "low";
    } else {
        nextPulse = "high";
    }
    for (unsigned int destination = 0; destination < moduleEffectMap[currDestination].size(); destination++) {
        processQueue.push({currDestination, nextPulse, moduleEffectMap[currDestination][destination]});
    }
};