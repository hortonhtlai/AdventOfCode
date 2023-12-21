#ifndef SOLUTION20_H
#define SOLUTION20_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution20 {
    public:
        int solve(string &input);

    private:
        int numLowPulse;
        int numHighPulse;
        unordered_map<string, string> moduleTypeMap;
        unordered_map<string, string> moduleStateMap;
        unordered_map<string, unordered_set<string>> conjunctionLowPulseInputs;
        unordered_map<string, vector<string>> moduleEffectMap;
        void noteModuleInfo(const vector<string> &termVector);
        void initConjunctionMemory();
        void pressButton();
        void handleFlipFlop(const string &currPulse, const string &currDestination, queue<vector<string>> &processQueue);
        void handleConjunction(const string &currSource, const string &currPulse, const string &currDestination, queue<vector<string>> &processQueue);
};

#endif